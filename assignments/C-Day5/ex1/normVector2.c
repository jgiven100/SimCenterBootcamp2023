#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv) {

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
  
  double norm = 0;

#pragma omp parallel
  {
    int tid = omp_get_thread_num();
    int numT = omp_get_num_threads();
    double sum = 0.;
    for (int i = tid; i < vectorSize; i += numT) {
      sum += globalVector[i] * globalVector[i]; 
    }
#pragma omp_critical
    {
      norm += sum;
    }
  }

  norm = sqrt(norm);
  printf("Norm = %f \n", norm);
  
  return 0;
}
