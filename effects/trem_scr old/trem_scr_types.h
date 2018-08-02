//
// Classroom License -- for classroom instructional use only.  Not for
// government, commercial, academic research, or other organizational use.
// File: trem_scr_types.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 06-Jun-2018 12:11:20
//
#ifndef TREM_SCR_TYPES_H
#define TREM_SCR_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray__common

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_real_T
#endif

//
// File trailer for trem_scr_types.h
//
// [EOF]
//
