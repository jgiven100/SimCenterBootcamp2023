// program to solve quadratic equation
//        ax^2 + bx + c = 0
//
// soln: x = -b/2a +/- sqrt(b^2-4ac)/2a
//
// write a program to take 3 inputs and output the soln
// if two real solutions, printf("%.8f, %.8f\n", x1, x2);    
// if only one solution, just ouput a single value, i.e. printf("%.8f\n", x1);    
// if complex, output a complex number, i.e. printf("%.8f + %.8fi,%.8f - %.8fi\n", x1, im, x2,im);    

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if (argc != 4) {
    printf("Usage: appName a b c\n");
    exit(-1);
  }

  float a = atof(argv[1]);
  float b = atof(argv[2]);
  float c = atof(argv[3]);

  float x1 = 0, x2 = 0;

  double bb4ac = (b * b) - (4 * a * c);

  if (bb4ac < 0) {
    float x = -(b / (2 * a));

    float imag = sqrt(-bb4ac) / (2 * a);

    printf("%.8f + %8.fi,%.8f - %fi\n", x , imag, x , imag);
  } else {

    x1 = -(b / (2 * a)) - (sqrt(bb4ac) / (2 * a ));
    x2 = -(b / (2 * a)) + (sqrt(bb4ac) / (2 * a ));

    if (abs(x1 - x2) < 1e-12) {
      printf("%.8f\n", x1);
    } else {
      printf("%.8f, %.8f\n", x1, x2);    
    }
  }
 
  return 0;
}

