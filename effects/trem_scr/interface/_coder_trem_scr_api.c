/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: _coder_trem_scr_api.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Jun-2018 13:18:51
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_trem_scr_api.h"
#include "_coder_trem_scr_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131450U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "trem_scr",                          /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real32_T (*b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *
  parentId))[512];
static real32_T c_emlrt_marshallIn(const mxArray *f, const char_T *identifier);
static real32_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static real32_T (*e_emlrt_marshallIn(const mxArray *src, const
  emlrtMsgIdentifier *msgId))[512];
static real32_T (*emlrt_marshallIn(const mxArray *sample, const char_T
  *identifier))[512];
static const mxArray *emlrt_marshallOut(const real32_T u[512]);
static real32_T f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId);

/* Function Definitions */

/*
 * Arguments    : const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real32_T (*)[512]
 */
static real32_T (*b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *
  parentId))[512]
{
  real32_T (*y)[512];
  y = e_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const mxArray *f
 *                const char_T *identifier
 * Return Type  : real32_T
 */
  static real32_T c_emlrt_marshallIn(const mxArray *f, const char_T *identifier)
{
  real32_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(emlrtAlias(f), &thisId);
  emlrtDestroyArray(&f);
  return y;
}

/*
 * Arguments    : const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real32_T
 */
static real32_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real32_T y;
  y = f_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real32_T (*)[512]
 */
static real32_T (*e_emlrt_marshallIn(const mxArray *src, const
  emlrtMsgIdentifier *msgId))[512]
{
  real32_T (*ret)[512];
  static const int32_T dims[1] = { 512 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "single", false, 1U,
    dims);
  ret = (real32_T (*)[512])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const mxArray *sample
 *                const char_T *identifier
 * Return Type  : real32_T (*)[512]
 */
  static real32_T (*emlrt_marshallIn(const mxArray *sample, const char_T
  *identifier))[512]
{
  real32_T (*y)[512];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(emlrtAlias(sample), &thisId);
  emlrtDestroyArray(&sample);
  return y;
}

/*
 * Arguments    : const real32_T u[512]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real32_T u[512])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[1] = { 0 };

  static const int32_T iv1[1] = { 512 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxSINGLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m0, iv1, 1);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real32_T
 */
static real32_T f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId)
{
  real32_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "single", false, 0U,
    &dims);
  ret = *(real32_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void trem_scr_api(const mxArray * const prhs[3], const mxArray *plhs[1])
{
  real32_T (*y)[512];
  real32_T (*sample)[512];
  real32_T f;
  real32_T fs;
  y = (real32_T (*)[512])mxMalloc(sizeof(real32_T [512]));

  /* Marshall function inputs */
  sample = emlrt_marshallIn(emlrtAlias(prhs[0]), "sample");
  f = c_emlrt_marshallIn(emlrtAliasP(prhs[1]), "f");
  fs = c_emlrt_marshallIn(emlrtAliasP(prhs[2]), "fs");

  /* Invoke the target function */
  trem_scr(*sample, f, fs, *y);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*y);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void trem_scr_atexit(void)
{
  mexFunctionCreateRootTLS();
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  trem_scr_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void trem_scr_initialize(void)
{
  mexFunctionCreateRootTLS();
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void trem_scr_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_trem_scr_api.c
 *
 * [EOF]
 */
