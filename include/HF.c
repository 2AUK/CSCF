#include "HF.h"

HF* HF_create(sys in_sys){
  HF *ret_HF = malloc(sizeof (HF));
  if (ret_HF == NULL)
    return NULL;

  ret_HF->Hmatrix = malloc(sizeof (double) * in_sys.nbfs);
  if (ret_HF->Hmatrix == NULL){
    free(ret_HF);
  }

  ret_HF->Omatrix = malloc (sizeof (double) * in_sys.nbfs);
  if (ret_HF->Omatrix == NULL){
    free(ret_HF->Hmatrix);
    free(ret_HF);
  }

  ret_HF->Pmatrix = malloc (sizeof (double) * in_sys.nbfs);
  if (ret_HF->Pmatrix == NULL){
    free(ret_HF->Hmatrix);
    free(ret_HF->Pmatrix);
    free(ret_HF);
  }
  
  ret_HF->Pnew = malloc (sizeof (double) * in_sys.nbfs);
  if (ret_HF->Pnew == NULL){
    free(ret_HF->Hmatrix);
    free(ret_HF->Pmatrix);
    free(ret_HF->Pnew);
    free(ret_HF);
  }
}
