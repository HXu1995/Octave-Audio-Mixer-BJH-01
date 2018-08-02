/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: _coder_doFilterf6k22k_api.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Jun-2018 11:22:36
 */

#ifndef _CODER_DOFILTERF6K22K_API_H
#define _CODER_DOFILTERF6K22K_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_doFilterf6k22k_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void doFilterf6k22k(real32_T x[512], real32_T y[512]);
  extern void doFilterf6k22k_api(const mxArray * const prhs[1], const mxArray
    *plhs[1]);
  extern void doFilterf6k22k_atexit(void);
  extern void doFilterf6k22k_initialize(void);
  extern void doFilterf6k22k_terminate(void);
  extern void doFilterf6k22k_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_doFilterf6k22k_api.h
 *
 * [EOF]
 */
