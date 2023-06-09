#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static long int numSteps = 1000000000;

int main(int argc, char **argv) {

  // Typical MPI initialization
  int numP, procID;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numP);
  MPI_Comm_rank(MPI_COMM_WORLD, &procID);

  // Initialization arrays for local and global
  double *globalPi = NULL;
  double localPi[1] = {0.};

  // Only process 0 needs global array 
  if (procID == 0) {
    globalPi = malloc(numP * sizeof(double));
    for (int i = 0; i < numP; i++) {
      globalPi[i] = 0;
    }
  }

  // Initialize global position and increment
  double x = 0.;
  double dx = 1. / numSteps;

  // Set number of sub steps for each process
  long int subSteps = numSteps / numP;

  // Shift global position for each process
  double shift = (double) procID / numP;

  // Loop sub steps and compute local part of Pi
  for (int i = 0; i < subSteps; i++) {
    x = ((i + 0.5) / numSteps) + shift;
    localPi[0] += 4. / (1. + (x * x));
  }

  // Gather local results into global array
  MPI_Gather(localPi, 1, MPI_DOUBLE, globalPi, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  // Only process zero reports output
  if (procID == 0) {

    // Sum each local part of Pi
    double pi = 0.;
    for (int i = 0; i < numP; i++) {
      pi += globalPi[i];
    }

    // Correct for dx width
    pi *= dx;

    printf("PI = %16.14f Difference from math.h definition %16.14f \n", pi, pi-M_PI);
  }
    
  // Typical MPI finalization
  MPI_Finalize();

  return 0;
}
