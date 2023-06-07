
// program to read values from a file, each file a csv list of int and two double
// written: fmk

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  if (argc != 3) {
    fprintf(stdout, "ERROR correct usage appName inputFile outputBinaryFile\n");
    return -1;
  }

  //
  // read from ascii file
  //
  
  FILE *filePtr = fopen(argv[1],"r"); 

  int i = 0;
  float float1, float2;
  int maxVectorSize = 100;
  double *vector1 = (double *)malloc(maxVectorSize*sizeof(double));
  double *vector2 = (double *)malloc(maxVectorSize*sizeof(double));  
  int vectorSize = 0;
  
  while (fscanf(filePtr,"%d, %f, %f\n", &i, &float1, &float2) != EOF) {
    vector1[vectorSize] = float1;
    vector2[vectorSize] = float2;
    printf("%d, %f, %f\n",i, vector2[i], vector1[i]);
    vectorSize++;

    if (vectorSize == maxVectorSize) {
      double *tmpVector1 = (double *)malloc(2 * vectorSize*sizeof(double));
      double *tmpVector2 = (double *)malloc(2 * vectorSize*sizeof(double));

      for (int j = 0; j < vectorSize; j++) {
        tmpVector1[j] = vector1[j];
        tmpVector2[j] = vector2[j];
      }

      free(vector1);
      free(vector2);

      vector1 = tmpVector1;
      vector2 = tmpVector2;

      maxVectorSize *= 2;
    }
  }
 
  fclose(filePtr);

  //
  // write data to binary file
  //
  
  FILE *filePtrB = fopen(argv[2],"wb");
  
  fwrite(vector1, sizeof(double), vectorSize, filePtrB);
  fwrite(vector2, sizeof(double), vectorSize, filePtrB);
  
  fclose(filePtrB);  

  free(vector1);
  free(vector2);

  return 0;
}
