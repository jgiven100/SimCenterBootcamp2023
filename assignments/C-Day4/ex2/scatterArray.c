#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char** argv) {
  
    int procID, numP;
    
    double* globalVector = NULL;
    double* localVector = NULL;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &procID);
    MPI_Comm_size(MPI_COMM_WORLD, &numP);

    if (argc != 2) {
      printf("Error correct usage: app vectorSize\n");
      return 0;
    }
    int vectorSize = atoi(argv[1]);
    int remainder = vectorSize % numP;

    // Force remainder to be 0
    int vectorSizeCor;
    if (remainder != 0) {
      vectorSizeCor = vectorSize + remainder;
      remainder = 0;
    } else { 
      vectorSizeCor = vectorSize;
    }

    // Only the root process initializes the global array
    if (procID == 0) {
      globalVector = (double*)malloc(sizeof(double) * vectorSizeCor);
      srand(50);
      for (int i = 0; i < vectorSizeCor; i++) {
	double random_number = 1.0 + (double)rand() / RAND_MAX;
	if (i < vectorSize) {
          globalVector[i] = random_number;
        } else {
          globalVector[i] = 0.;
        }
      }
    }

    // Determine the size of the local array for each process
    int localSize = vectorSizeCor / numP;

    // Allocate memory for the local array
    localVector = (double*)malloc(sizeof(double) * localSize);

    // Scatter the global array to all processes
    MPI_Scatter(globalVector, localSize, MPI_DOUBLE,
                localVector, localSize, MPI_DOUBLE,
                0, MPI_COMM_WORLD);

    // Print the local array for each process
    printf("Process %d received: ", procID);
    for (int i = 0; i < localSize; i++) {
        printf("%.2f ", localVector[i]);
    }
    printf("\n");

    // process0 has some stuff in the globalArray that was not sent!
    if (procID == 0) {
      if (remainder != 0) {
        printf("Process 0 Additional NOT SENT still in globalVector: ");    
        exit(-1);
      }
    }

    // Init arrays for local and global
    double *globalSum = NULL;
    double localSum[1] = {0.};

    //
    if (procID == 0) {
      globalSum = malloc(numP * sizeof(double));
      for (int i = 0; i < numP; i++) {
        globalSum[i] = 0;
      }
    }

    // 
    for (int i = 0; i < localSize; i++) {
      localSum[0] += localVector[i] * localVector[i];
    }

    //
    MPI_Gather(localSum, 1, MPI_DOUBLE, globalSum, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    //
    if (procID == 0) {
      double sum = 0;
      for (int i = 0; i < numP; i++) {
        sum += globalSum[i];
      }
      double norm = sqrt(sum);

      printf("Norm = %16.14f\n", norm);
    }

    // Clean up memory
    free(globalVector);
    free(localVector);

    free(globalSum);

    MPI_Finalize();
    return 0;
}
