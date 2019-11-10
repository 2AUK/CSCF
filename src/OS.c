#include "OS.h"
#include <math.h>

double** generate_overlap_1d(int i, int j, double XAB, double PAx, double PBx, double a, double b){
  double p = a + b;
  double q = a * b / p;

  double** array = malloc(i * sizeof(double *));
  for(int row = 0; row < nbfs; row++)
    array[row] = malloc(j * sizeof(int));

  array[0][0] = sqrt(M_PI / p) * exp(-q * XAB * XAB);
  
  for (int k = 1; k < j; k++)
    array[0][k+1] = PBx * array[0][k] + 0.5/p * j * array[0][j-1];

  for (int k = 0; k < i; k++){
    for(int l = 0; l < j; l++){
      array[i+1][j] = array[i][j+1] - XAB*array[i][j];
    }
  }

  return array;
}

