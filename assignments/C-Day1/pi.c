#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double F(double x);

int main(int argc, char **argv) {

  if (argc != 2) {
    printf("Usage: appName numSteps\n");
    exit(-1);
  }

  int numSteps = atoi(argv[1]);
  double pi   = 0;
  
  double dx = 1. / numSteps;
  double xi = dx / 2.;

  for (int i = 0; i < numSteps; i++) {
    pi += F(xi);
    xi += dx;
  }

  pi *= dx;

  printf("PI = %16.14f, diff(%16.14f)\n",pi, fabs(pi-M_PI));
  return 0;
}

double F(double x) {
  return (4 / (1 + (x * x)));
}
