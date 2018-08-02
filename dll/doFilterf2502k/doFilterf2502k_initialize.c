/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: doFilterf2502k_initialize.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Jun-2018 11:25:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "doFilterf2502k.h"
#include "doFilterf2502k_initialize.h"
#include "doFilterf2502k_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void doFilterf2502k_initialize(void)
{
  static const float fv0[21] = { 1.0F, -1.92440891F, 1.0F, 1.0F, -1.99903643F,
    1.0F, 1.0F, -1.91333508F, 1.0F, 1.0F, -1.99916184F, 1.0F, 1.0F, -1.83583856F,
    1.0F, 1.0F, -1.9995662F, 1.0F, 1.0F, 0.0F, -1.0F };

  int i;
  static const float fv1[14] = { -1.92525053F, 0.993536949F, -1.99812031F,
    0.999184966F, -1.90701091F, 0.968413889F, -1.99440944F, 0.995578229F,
    -1.86765301F, 0.907417059F, -1.97839975F, 0.980144F, -1.89749312F,
    0.905686498F };

  static const float fv2[8] = { 0.615024924F, 0.615024924F, 0.805956483F,
    0.805956483F, 0.425006032F, 0.425006032F, 0.109615788F, 0.0F };

  static const boolean_T bv0[8] = { true, true, true, true, true, true, true,
    false };

  rt_InitInfAndNaN(8U);

  /*  The following code was used to design the filter coefficients: */
  /*  */
  /*  Fstop1 = 230;    % First Stopband Frequency */
  /*  Fpass1 = 250;    % First Passband Frequency */
  /*  Fpass2 = 2000;   % Second Passband Frequency */
  /*  Fstop2 = 2200;   % Second Stopband Frequency */
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
 * File trailer for doFilterf2502k_initialize.c
 *
 * [EOF]
 */
