//
// Classroom License -- for classroom instructional use only.  Not for
// government, commercial, academic research, or other organizational use.
// File: trem_scr_emxutil.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 06-Jun-2018 12:11:20
//
#ifndef TREM_SCR_EMXUTIL_H
#define TREM_SCR_EMXUTIL_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "trem_scr_types.h"

// Function Declarations
extern void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel, unsigned
  int elementSize);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_real_T1(emxArray_real_T **pEmxArray, int numDimensions);

#endif

//
// File trailer for trem_scr_emxutil.h
//
// [EOF]
//
