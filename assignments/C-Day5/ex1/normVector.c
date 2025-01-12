#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv) {

  //
  // create vector with random numbers
  //
  
  if (argc != 2) {
    printf("Error correct usage: app vectorSize\n");
    return 0;
  }
  int vectorSize = atoi(argv[1]);
  
  double *globalVector = (double*)malloc(sizeof(double) * vectorSize);
  srand(50);
  for (int i = 0; i < vectorSize; i++) {
    double random_number = 1.0 + (double)rand() / RAND_MAX;
    globalVector[i] = random_number;
  }  
  
  int nThreads = 0;
  double sum[64][64];
  for (int i = 0; i < 64; i++) {
    sum[i][0] = 0.;
  }

  //
  // calculate norm
  //
  #pragma omp parallel
  {
    int tid = omp_get_thread_num();
    int numT = omp_get_num_threads();
    if (tid == 0) {
      nThreads = numT;
    }
    for (int i = tid; i < vectorSize; i += numT) {
      sum[tid][0] += globalVector[i] * globalVector[i]; 
    }
  }

  double norm = 0;
  for (int i = 0; i < nThreads; i++) {
    norm += sum[i][0];
  }

  norm = sqrt(norm);

  //
  // print norm
  //
  
  printf("Norm = %f \n", norm);
  
  return 0;
}
