#include "system.h"
#include "basis.h"
#include <stdlib.h>

sys* system_create(int natoms, int nbfs){
  sys *ret_sys = malloc(sizeof (sys));
  if (ret_sys == NULL)
    return NULL;

  ret_sys->natoms = natoms;
  ret_sys->nbfs = nbfs;
  ret_sys->basisfunctions = malloc(sizeof (bfn) * nbfs);
  if (ret_sys->basisfunctions == NULL){
    free(ret_sys);
    return NULL;
  }
  ret_sys->S = calloc((nbfs*nbfs), sizeof(double));
  if (ret_sys->S == NULL){
    free(ret_sys->basisfunctions);
    free(ret_sys);
    return NULL;
  }
  ret_sys->T = calloc((nbfs*nbfs), sizeof(double));
  if (ret_sys->T == NULL){
    free(ret_sys->basisfunctions);
    free(ret_sys->S);
    free(ret_sys);
    return NULL;
  }
  ret_sys->V = calloc((nbfs*nbfs), sizeof(double));
  if (ret_sys->V == NULL){
    free(ret_sys->basisfunctions);
    free(ret_sys->S);
    free(ret_sys->T);
    free(ret_sys);
    return NULL;
  }
  ret_sys->ERI = calloc((nbfs*nbfs*nbfs*nbfs), sizeof(double));
  if (ret_sys->ERI == NULL){
    free(ret_sys->basisfunctions);
    free(ret_sys->S);
    free(ret_sys->T);
    free(ret_sys->V);
    free(ret_sys);
    return NULL;
  }
  return(ret_sys);
}

void system_destroy(sys* in_system){
  if (in_system != NULL) {
    free(in_system->basisfunctions);
    free(in_system->S);
    free(in_system->T);
    free(in_system->V);
    free(in_system->ERI);
    free(in_system);
  }
}

void print_system_info(sys* system){

}

sys* system_from_file(FILE* infile, char* basis){

}
