//
// Classroom License -- for classroom instructional use only.  Not for
// government, commercial, academic research, or other organizational use.
// File: trem_scr_emxAPI.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 06-Jun-2018 12:11:20
//
#ifndef TREM_SCR_EMXAPI_H
#define TREM_SCR_EMXAPI_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "trem_scr_types.h"

// Function Declarations
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, int *size);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

//
// File trailer for trem_scr_emxAPI.h
//
// [EOF]
//
