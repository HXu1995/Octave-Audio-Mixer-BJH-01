//
// Classroom License -- for classroom instructional use only.  Not for
// government, commercial, academic research, or other organizational use.
// File: cat.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 07-Jun-2018 15:50:38
//

// Include Files
#include "rt_nonfinite.h"
#include "echo_scr.h"
#include "cat.h"
#include "echo_scr_emxutil.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *varargin_1
//                const emxArray_real_T *varargin_2
//                emxArray_real_T *y
// Return Type  : void
//
void cat(const emxArray_real_T *varargin_1, const emxArray_real_T *varargin_2,
         emxArray_real_T *y)
{
  int ysize_idx_0;
  int ix;
  int l;
  ysize_idx_0 = varargin_1->size[0] + varargin_2->size[0];
  ix = y->size[0];
  y->size[0] = ysize_idx_0;
  emxEnsureCapacity((emxArray__common *)y, ix, sizeof(double));
  ysize_idx_0 = 0;
  ix = 0;
  for (l = 1; l <= varargin_1->size[0]; l++) {
    y->data[ysize_idx_0] = varargin_1->data[ix];
    ix++;
    ysize_idx_0++;
  }

  ix = 0;
  for (l = 1; l <= varargin_2->size[0]; l++) {
    y->data[ysize_idx_0] = varargin_2->data[ix];
    ix++;
    ysize_idx_0++;
  }
}

//
// File trailer for cat.cpp
//
// [EOF]
//
