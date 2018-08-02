/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: _coder_trem_scr_api.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Jun-2018 13:18:51
 */

#ifndef _CODER_TREM_SCR_API_H
#define _CODER_TREM_SCR_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_trem_scr_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void trem_scr(real32_T sample[512], real32_T f, real32_T fs, real32_T
                       y[512]);
  extern void trem_scr_api(const mxArray * const prhs[3], const mxArray *plhs[1]);
  extern void trem_scr_atexit(void);
  extern void trem_scr_initialize(void);
  extern void trem_scr_terminate(void);
  extern void trem_scr_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_trem_scr_api.h
 *
 * [EOF]
 */
