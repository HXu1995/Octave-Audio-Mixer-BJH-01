//
// Classroom License -- for classroom instructional use only.  Not for
// government, commercial, academic research, or other organizational use.
// File: trem_scr.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 06-Jun-2018 12:11:20
//

// Include Files
#include "rt_nonfinite.h"
#include "trem_scr.h"
#include "trem_scr_emxutil.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *sample
//                double f
//                double fs
//                emxArray_real_T *y
// Return Type  : void
//
void trem_scr(const emxArray_real_T *sample, double f, double fs,
              emxArray_real_T *y)
{
  emxArray_real_T *t_sample;
  unsigned int sz_idx_0;
  int i;
  int loop_ub;
  emxInit_real_T(&t_sample, 1);

  // 'trem_scr:3' f0 = f;
  // 'trem_scr:4' a = sample;
  // 'trem_scr:5' fs0 = fs;
  // 'trem_scr:6' sz = size(a);
  sz_idx_0 = (unsigned int)sample->size[0];

  // 'trem_scr:7' t_sample = zeros(sz);
  i = t_sample->size[0];
  t_sample->size[0] = (int)sz_idx_0;
  emxEnsureCapacity((emxArray__common *)t_sample, i, sizeof(double));
  loop_ub = (int)sz_idx_0;
  for (i = 0; i < loop_ub; i++) {
    t_sample->data[i] = 0.0;
  }

  // 'trem_scr:9' for i = 1:length(sample)
  for (i = 0; i < sample->size[0]; i++) {
    // 'trem_scr:10' t = i/fs;
    // 'trem_scr:11' lfo = cos(2*pi*f*t);
    // + offset);
    // 'trem_scr:12' t_sample(i) = lfo*sample(i);
    t_sample->data[i] = std::cos(6.2831853071795862 * f * ((1.0 + (double)i) /
      fs)) * sample->data[i];
  }

  // 'trem_scr:14' y = transpose(t_sample);
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = t_sample->size[0];
  emxEnsureCapacity((emxArray__common *)y, i, sizeof(double));
  loop_ub = t_sample->size[0];
  for (i = 0; i < loop_ub; i++) {
    y->data[y->size[0] * i] = t_sample->data[i];
  }

  emxFree_real_T(&t_sample);
}

//
// File trailer for trem_scr.cpp
//
// [EOF]
//
