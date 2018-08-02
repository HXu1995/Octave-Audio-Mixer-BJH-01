/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: doFilterf60250_initialize.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Jun-2018 11:24:43
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "doFilterf60250.h"
#include "doFilterf60250_initialize.h"
#include "doFilterf60250_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void doFilterf60250_initialize(void)
{
  static const float fv0[18] = { 1.0F, -1.99847293F, 1.0F, 1.0F, -1.99995673F,
    1.0F, 1.0F, -1.99407494F, 1.0F, 1.0F, -1.99998891F, 1.0F, 1.0F, -1.9987725F,
    1.0F, 1.0F, -1.99994624F, 1.0F };

  int i;
  static const float fv1[12] = { -1.99449193F, 0.995408416F, -1.99864113F,
    0.998713F, -1.98927927F, 0.989765763F, -1.99447191F, 0.994606674F,
    -1.99797678F, 0.999046504F, -1.99970925F, 0.999770939F };

  static const float fv2[7] = { 0.846154273F, 0.846154273F, 0.673526824F,
    0.673526824F, 0.174604774F, 0.174604774F, 0.0F };

  static const boolean_T bv0[7] = { true, true, true, true, true, true, false };

  rt_InitInfAndNaN(8U);

  /*  The following code was used to design the filter coefficients: */
  /*  */
  /*  Fstop1 = 40;     % First Stopband Frequency */
  /*  Fpass1 = 60;     % First Passband Frequency */
  /*  Fpass2 = 250;    % Second Passband Frequency */
  /*  Fstop2 = 280;    % Second Stopband Frequency */
  /*  Astop1 = 40;     % First Stopband Attenuation (dB) */
  /*  Apass  = 1;      % Passband Ripple (dB) */
  /*  Astop2 = 40;     % Second Stopband Attenuation (dB) */
  /*  Fs     = 48000;  % Sampling Frequency */
  /*  */
  /*  h = fdesign.bandpass('fst1,fp1,fp2,fst2,ast1,ap,ast2', Fstop1, Fpass1, ... */
  /*                       Fpass2, Fstop2, Astop1, Apass, Astop2, Fs); */
  /*  */
  /*  Hd = design(h, 'ellip', ... */
  /*      'MatchExactly', 'both', ... */
  /*      'SystemObject', true); */
  /* System object Constructor function: dsp.BiquadFilter */
  Hd.cSFunObject.P0_ICRTP = 0.0F;
  memcpy(&Hd.cSFunObject.P1_RTP1COEFF[0], &fv0[0], 18U * sizeof(float));
  for (i = 0; i < 12; i++) {
    Hd.cSFunObject.P2_RTP2COEFF[i] = fv1[i];
  }

  for (i = 0; i < 7; i++) {
    Hd.cSFunObject.P3_RTP3COEFF[i] = fv2[i];
    Hd.cSFunObject.P4_RTP_COEFF3_BOOL[i] = bv0[i];
  }

  /* System object Initialization function: dsp.BiquadFilter */
  for (i = 0; i < 12; i++) {
    Hd.cSFunObject.W0_FILT_STATES[i] = Hd.cSFunObject.P0_ICRTP;
  }
}

/*
 * File trailer for doFilterf60250_initialize.c
 *
 * [EOF]
 */
