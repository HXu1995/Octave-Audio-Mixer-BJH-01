/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: _coder_doFilterf60250_api.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 08-Jun-2018 12:28:07
 */

#ifndef _CODER_DOFILTERF60250_API_H
#define _CODER_DOFILTERF60250_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_doFilterf60250_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern real_T doFilterf60250(real_T x);
  extern void doFilterf60250_api(const mxArray * const prhs[1], const mxArray
    *plhs[1]);
  extern void doFilterf60250_atexit(void);
  extern void doFilterf60250_initialize(void);
  extern void doFilterf60250_terminate(void);
  extern void doFilterf60250_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_doFilterf60250_api.h
 *
 * [EOF]
 */