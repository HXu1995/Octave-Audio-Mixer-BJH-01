/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: doFilterf6k22k_types.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 08-Jun-2018 12:29:32
 */

#ifndef DOFILTERF6K22K_TYPES_H
#define DOFILTERF6K22K_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_dsp_BiquadFilter_0
#define struct_dsp_BiquadFilter_0

struct dsp_BiquadFilter_0
{
  int S0_isInitialized;
  double W0_FILT_STATES[14];
  int W1_PreviousNumChannels;
  double P0_ICRTP;
  double P1_RTP1COEFF[21];
  double P2_RTP2COEFF[14];
  double P3_RTP3COEFF[8];
  boolean_T P4_RTP_COEFF3_BOOL[8];
};

#endif                                 /*struct_dsp_BiquadFilter_0*/

#ifndef typedef_dsp_BiquadFilter_0
#define typedef_dsp_BiquadFilter_0

typedef struct dsp_BiquadFilter_0 dsp_BiquadFilter_0;

#endif                                 /*typedef_dsp_BiquadFilter_0*/

#ifndef typedef_dspcodegen_BiquadFilter
#define typedef_dspcodegen_BiquadFilter

typedef struct {
  int isInitialized;
  dsp_BiquadFilter_0 cSFunObject;
} dspcodegen_BiquadFilter;

#endif                                 /*typedef_dspcodegen_BiquadFilter*/
#endif

/*
 * File trailer for doFilterf6k22k_types.h
 *
 * [EOF]
 */
