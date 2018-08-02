//
// Classroom License -- for classroom instructional use only.  Not for
// government, commercial, academic research, or other organizational use.
// File: echo_scr_emxutil.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 07-Jun-2018 15:50:38
//
#ifndef ECHO_SCR_EMXUTIL_H
#define ECHO_SCR_EMXUTIL_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "echo_scr_types.h"

// Function Declarations
extern void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel, unsigned
  int elementSize);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

//
// File trailer for echo_scr_emxutil.h
//
// [EOF]
//
