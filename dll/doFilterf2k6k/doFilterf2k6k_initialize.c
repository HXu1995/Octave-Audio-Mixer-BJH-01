/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: doFilterf2k6k_initialize.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Jun-2018 11:21:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "doFilterf2k6k.h"
#include "doFilterf2k6k_initialize.h"
#include "doFilterf2k6k_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void doFilterf2k6k_initialize(void)
{
  static const float fv0[21] = { 1.0F, -1.47202957F, 1.0F, 1.0F, 1.93948328F,
    1.0F, 1.0F, -1.54005659F, 1.0F, 1.0F, 1.9481796F, 1.0F, 1.0F, -1.76131666F,
    1.0F, 1.0F, 1.9745214F, 1.0F, 1.0F, 0.0F, -1.0F };

  int i;
  static const float fv1[14] = { -1.40308142F, 0.979923725F, 1.92512667F,
    0.992610395F, -1.28979123F, 0.895325959F, 1.88596964F, 0.959829688F,
    -0.857309699F, 0.602460921F, 1.71069407F, 0.818703055F, 0.593237698F,
    0.146047235F };

  static const float fv2[8] = { 0.64168191F, 0.64168191F, 0.918198049F,
    0.918198049F, 0.717002213F, 0.717002213F, 0.992506F, 0.0F };

  static const boolean_T bv0[8] = { true, true, true, true, true, true, true,
    false };

  rt_InitInfAndNaN(8U);

  /*  The following code was used to design the filter coefficients: */
  /*  */
  /*  Fstop1 = 5700;   % First Stopband Frequency */
  /*  Fpass1 = 6000;   % First Passband Frequency */
  /*  Fpass2 = 22000;  % Second Passband Frequency */
  /*  Fstop2 = 22200;  % Second Stopband Frequency */
  /*  Astop1 = 40;     % First Stopband Attenuation (dB) */
  /*  Apass  = 0.5;    % Passband Ripple (dB) */
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
  memcpy(&Hd.cSFunObject.P1_RTP1COEFF[0], &fv0[0], 21U * sizeof(float));
  for (i = 0; i < 14; i++) {
    Hd.cSFunObject.P2_RTP2COEFF[i] = fv1[i];
  }

  for (i = 0; i < 8; i++) {
    Hd.cSFunObject.P3_RTP3COEFF[i] = fv2[i];
    Hd.cSFunObject.P4_RTP_COEFF3_BOOL[i] = bv0[i];
  }

  /* System object Initialization function: dsp.BiquadFilter */
  for (i = 0; i < 14; i++) {
    Hd.cSFunObject.W0_FILT_STATES[i] = Hd.cSFunObject.P0_ICRTP;
  }
}

/*
 * File trailer for doFilterf2k6k_initialize.c
 *
 * [EOF]
 */
