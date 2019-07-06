#pragma once

#include "THO.h"
#include "system.h"

typedef struct HF {
  sys system;
  double* Hmatrix;
  double* Omatrix;
  double* Pmatrix;
  double* Pnew;
  double nucl_repl; 
} HF;


HF* HF_create(sys);

double calcnuclrepl(sys);
