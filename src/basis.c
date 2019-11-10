#include "basis.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void normalise(bfn* basis){
  const int l = basis->shell[0];
  const int m = basis->shell[1];
  const int n = basis->shell[2];
  const L = l+m+n;
  for(int i = 0; i < 3; i++){
    double num = pow(2.0, 2.0*(l+m+n) + 3.0/2.0) * pow(basis->exps[i], (l+m+n) + 3.0/2.0);
    double denom = double_factorial(2*l-1) * double_factorial(2*m-1) * double_factorial(2*n-1) * pow(M_PI, 3.0/2.0);
    basis->norm[i] = sqrt(num/denom);
  }
  double N = 0.0;
  double prefac = (pow(M_PI, 1.5) * double_factorial(2*l-1) * double_factorial(2*m-1) * double_factorial(2*n-1)) / pow(2.0, L);
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      N += (basis->norm[i] * basis->norm[j] * basis->coefs[i] * basis->coefs[j]) /  pow(basis->exps[i] + basis->exps[j], L+1.5);
    }
  }
  N *= prefac;
  N = pow(N, -0.5);
  for (int k = 0; k < 3; k++){
    basis->coefs[k] *= N;
  }
  print_matrix(basis->norm, 1, 3);
}

bfn* bfn_create(int nprimitives, double* exps, double* coefs, double origin[3], int shell[3], double atomno){
  
  bfn *ret_bfn = malloc(sizeof (bfn) * 1);
  if (ret_bfn == NULL)
    return NULL;

  ret_bfn->nprimitives = nprimitives;
  ret_bfn->exps = malloc(sizeof (double) * nprimitives);
  if (ret_bfn->exps == NULL){
    free(ret_bfn);
    return NULL;
  }
  ret_bfn->coefs = malloc(sizeof (double) * nprimitives);
  if (ret_bfn->coefs == NULL){
    free(ret_bfn->exps);
    free(ret_bfn);
    return NULL;
  }
  ret_bfn->norm = malloc(sizeof (double) * nprimitives);
  if (ret_bfn->norm == NULL){
    free(ret_bfn->exps);
    free(ret_bfn->coefs);
    free(ret_bfn);
    return NULL;
  }
  for(int i = 0; i < nprimitives; i++){
    ret_bfn->exps[i] = exps[i];
    ret_bfn->coefs[i] = coefs[i];
  }
  for(int i = 0; i < 3; i++){
    ret_bfn->shell[i] = shell[i];
    ret_bfn->origin[i] = origin[i];
  }
  ret_bfn->atomno = atomno;
  normalise(ret_bfn);
  return ret_bfn;
}

void bfn_destroy(bfn* in_bfn){
  if (in_bfn != NULL) {
    free(in_bfn->norm);
    free(in_bfn->exps);
    free(in_bfn->coefs);
    free(in_bfn);
  }
}
