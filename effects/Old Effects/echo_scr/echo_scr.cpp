//
// Classroom License -- for classroom instructional use only.  Not for
// government, commercial, academic research, or other organizational use.
// File: echo_scr.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 07-Jun-2018 15:50:38
//

// Include Files
#include "rt_nonfinite.h"
#include "echo_scr.h"
#include "echo_scr_emxutil.h"
#include "cat.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *sample
//                double delay
//                double gain
//                double echo_num
//                double fs
//                emxArray_real_T *y
// Return Type  : void
//
void echo_scr(const emxArray_real_T *sample, double delay, double gain, double
              echo_num, double fs, emxArray_real_T *y)
{
  double delay0;
  int i0;
  int loop_ub;
  int x;
  emxArray_real_T *echosample1;
  emxArray_real_T *b;
  emxArray_real_T *r0;
  emxArray_real_T *r1;

  // 'echo_scr:3' delay0 = delay * fs;
  delay0 = delay * fs;

  //  prompt2 = 'Enter the gain (>1 for gradually increase in volume, <1 for decreasing volume)\n'; 
  // 'echo_scr:5' gain0 = gain;
  // 'echo_scr:6' echo_num0 = echo_num;
  // 'echo_scr:7' echosample = sample;
  i0 = y->size[0];
  y->size[0] = sample->size[0];
  emxEnsureCapacity((emxArray__common *)y, i0, sizeof(double));
  loop_ub = sample->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    y->data[i0] = sample->data[i0];
  }

  // 'echo_scr:8' for x = 1:echo_num
  x = 0;
  emxInit_real_T(&echosample1, 1);
  emxInit_real_T(&b, 1);
  emxInit_real_T(&r0, 1);
  emxInit_real_T(&r1, 1);
  while (x <= (int)echo_num - 1) {
    // 'echo_scr:9' echosample1 = cat(1, echosample, zeros(1,delay0).');
    i0 = r1->size[0];
    r1->size[0] = (int)delay0;
    emxEnsureCapacity((emxArray__common *)r1, i0, sizeof(double));
    loop_ub = (int)delay0;
    for (i0 = 0; i0 < loop_ub; i0++) {
      r1->data[i0] = 0.0;
    }

    cat(y, r1, echosample1);

    // 'echo_scr:10' echosample = (echosample1 + gain*cat(1,zeros(1,delay0).',echosample)/echo_num); 
    i0 = r0->size[0];
    r0->size[0] = (int)delay0;
    emxEnsureCapacity((emxArray__common *)r0, i0, sizeof(double));
    loop_ub = (int)delay0;
    for (i0 = 0; i0 < loop_ub; i0++) {
      r0->data[i0] = 0.0;
    }

    cat(r0, y, b);
    i0 = y->size[0];
    y->size[0] = echosample1->size[0];
    emxEnsureCapacity((emxArray__common *)y, i0, sizeof(double));
    loop_ub = echosample1->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      y->data[i0] = echosample1->data[i0] + gain * b->data[i0] / echo_num;
    }

    x++;
  }

  emxFree_real_T(&r1);
  emxFree_real_T(&r0);
  emxFree_real_T(&b);
  emxFree_real_T(&echosample1);

  // 'echo_scr:13' y = echosample;
}

//
// File trailer for echo_scr.cpp
//
// [EOF]
//
