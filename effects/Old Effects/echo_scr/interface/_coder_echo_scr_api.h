/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: _coder_echo_scr_api.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 07-Jun-2018 15:50:38
 */

#ifndef _CODER_ECHO_SCR_API_H
#define _CODER_ECHO_SCR_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_echo_scr_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void echo_scr(emxArray_real_T *sample, real_T delay, real_T gain, real_T
                     echo_num, real_T fs, emxArray_real_T *y);
extern void echo_scr_api(const mxArray * const prhs[5], const mxArray *plhs[1]);
extern void echo_scr_atexit(void);
extern void echo_scr_initialize(void);
extern void echo_scr_terminate(void);
extern void echo_scr_xil_terminate(void);

#endif

/*
 * File trailer for _coder_echo_scr_api.h
 *
 * [EOF]
 */
