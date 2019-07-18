#include "HF.h"

HF* HF_create(sys in_sys){
  HF *ret_HF = malloc(sizeof (HF));
  if (ret_HF == NULL)
    return NULL;

  ret_HF->sys = in_sys;
  ret_HF->Hmatrix = calloc((in_sys.nbfs * in_sys.nbfs), sizeof(double));
  if (ret_HF->Hmatrix == NULL){
    free(ret_HF);
    return NULL;
  }
  ret_HF->Omatrix = calloc((in_sys.nbfs * in_sys.nbfs), sizeof(double));
  if (ret_HF->Omatrix == NULL){
    free(ret_HF->Hmatrix);
    free(ret_HF);
    return NULL;
  }
  ret_HF->Pmatrix = calloc((in_sys.nbfs * in_sys.nbfs), sizeof(double));
  if (ret_HF->Pmatrix == NULL){
    free(ret_HF->Hmatrix);
    free(ret_HF->Omatrix);
    free(ret_HF);
    return NULL;
  }
  ret_HF->Pnew = calloc((in_sys.nbfs * in_sys.nbfs), sizeof(double));
  if (ret_HF->Pnew == NULL){
    free(ret_HF->Hmatrix);
    free(ret_HF->Omatrix);
    free(ret_HF->Pmatrix);
    free(ret_HF);
    return NULL;
  }
  return ret_HF;
}

void update(HF in_HF){

}
