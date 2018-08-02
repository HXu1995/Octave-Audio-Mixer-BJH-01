/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: doFilterf60250_initialize.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 08-Jun-2018 12:28:07
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
  static const double dv0[18] = { 1.0, -1.99847293533624, 1.0, 1.0,
    -1.99995674950492, 1.0, 1.0, -1.99407494361384, 1.0, 1.0, -1.99998886522209,
    1.0, 1.0, -1.99877252022067, 1.0, 1.0, -1.99994618968551, 1.0 };

  static const double dv1[12] = { -1.99449194703547, 0.995408412763851,
    -1.99864116399063, 0.99871302900421, -1.98927930434106, 0.989765737955392,
    -1.9944719443502, 0.994606693773363, -1.99797682002882, 0.999046526677543,
    -1.99970920215674, 0.999770914860847 };

  int i;
  static const double dv2[7] = { 0.846154246528169, 0.846154246528169,
    0.673526823988711, 0.673526823988711, 0.174604767549556, 0.174604767549556,
    0.0 };

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
  Hd.cSFunObject.P0_ICRTP = 0.0;
  memcpy(&Hd.cSFunObject.P1_RTP1COEFF[0], &dv0[0], 18U * sizeof(double));
  memcpy(&Hd.cSFunObject.P2_RTP2COEFF[0], &dv1[0], 12U * sizeof(double));
  for (i = 0; i < 7; i++) {
    Hd.cSFunObject.P3_RTP3COEFF[i] = dv2[i];
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
