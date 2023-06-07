// program to transform stress:
//
// sigmaX' = sigmaX * cos^2(theta) + sigmaY * sin^2(theta) + 2 * tauXY Sin(theta)Cos(theta)
// sigmaY' = sigmaX * sin^2(theta) + sigmaY * cos^2(theta) - 2 * tauXY Sin(theta)Cos(theta)
// tauXY' = (sigmaY-sigmaX) * sin(theta)cos(theta) + tauXY(cos^2(theta) - sin^2(theta))
//
// write a program to take:
// 1: 4 inputs: sigmaX, sigmaY, tauXY, theta and output transformed stresses: sigmaX', sigmaY', tauXY'
// 2: 3  inputs: sigmaX, sigmaY, tauXY and output transformed stresses: sigmaX', sigmaY', tauXY' for every 10 degrees
//
// NOTE: perform the transformation inside a function that cannot be named main
//
// Extend to possibly include all outputs for a Mohr circle, were the theta now provided is a deltaTheta

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void transformStress(double *stressIN, double theta, double *stressTransformed);

int main(int argc, char **argv) {

  double sigmaX = atof(argv[1]);
  double sigmaY = atof(argv[2]);
  double sigmaZ = atof(argv[3]);

  double theta = 0.;

  double stressIN[3] = {sigmaX, sigmaY, sigmaZ};
  double stressOUT[3] = {0., 0., 0.};

  if (argc == 4) {
  
    for (int i = 0; i < 36; i++) {
      transformStress(stressIN, theta, stressOUT);
      printf("%.4f, %.4f, %.4f, %.4f\n", theta, stressOUT[0], stressOUT[1], stressOUT[2]);
      theta += 10.;
    }

  } else if (argc == 5) {

    theta = atof(argv[4]);
    transformStress(stressIN, theta, stressOUT);
    printf("%.4f, %.4f, %.4f\n", stressOUT[0], stressOUT[1], stressOUT[2]);

  } else {
  
    printf("WRONG ARGS\n");
    exit(-1);

  }

  return 0;
}

void transformStress(double *stressIN, double theta, double *stressTransformed) {

  theta = theta * M_PI / 180.;

  double cos2t = cos(theta) * cos(theta);
  double sin2t = sin(theta) * sin(theta);
  double sintcost = sin(theta) * cos(theta);

  double sigmaX = stressIN[0];
  double sigmaY = stressIN[1];
  double sigmaXY = stressIN[2];

  stressTransformed[0] = sigmaX * cos2t + sigmaY * sin2t + 2 * sigmaXY * sintcost;
  stressTransformed[1] = sigmaX * sin2t + sigmaY * cos2t - 2 * sigmaXY * sintcost;
  stressTransformed[2] = (sigmaY - sigmaX) * sintcost + sigmaXY * (cos2t - sin2t);
}
