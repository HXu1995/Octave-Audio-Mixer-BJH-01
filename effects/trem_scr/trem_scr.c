/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: trem_scr.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Jun-2018 13:18:51
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "trem_scr.h"

/* Function Definitions */

/*
 * Arguments    : const float sample[512]
 *                float f
 *                float fs
 *                float y[512]
 * Return Type  : void
 */
void trem_scr(const float sample[512], float f, float fs, float y[512])
{
  int i;
  for (i = 0; i < 512; i++) {
    /* + offset); */
    y[i] = (float)cos(6.28318548F * f * ((1.0F + (float)i) / fs)) * sample[i];
  }
}

/*
 * File trailer for trem_scr.c
 *
 * [EOF]
 */
