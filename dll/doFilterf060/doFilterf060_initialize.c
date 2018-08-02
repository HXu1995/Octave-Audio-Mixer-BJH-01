/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: doFilterf060_initialize.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Jun-2018 11:27:30
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "doFilterf060.h"
#include "doFilterf060_initialize.h"
#include "doFilterf060_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void doFilterf060_initialize(void)
{
  int i;
  static const float fv0[15] = { 1.0F, -1.99990678F, 1.0F, 1.0F, -1.99999881F,
    1.0F, 1.0F, -1.9998287F, 1.0F, 1.0F, -1.9999994F, 1.0F, 1.0F, 0.0F, -1.0F };

  static const float fv1[10] = { -1.99919391F, 0.99925679F, -1.99987674F,
    0.999878407F, -1.99704182F, 0.997085214F, -1.99930787F, 0.999310315F,
    -1.99691832F, 0.996928513F };

  static const float fv2[6] = { 0.529703736F, 0.529703736F, 0.424903393F,
    0.424903393F, 0.00326747843F, 0.0F };

  static const boolean_T bv0[6] = { true, true, true, true, true, false };

  rt_InitInfAndNaN(8U);

  /*  The following code was used to design the filter coefficients: */
  /*  */
  /*  Fstop1 = 1;      % First Stopband Frequency */
  /*  Fpass1 = 10;     % First Passband Frequency */
  /*  Fpass2 = 60;     % Second Passband Frequency */
  /*  Fstop2 = 80;     % Second Stopband Frequency */
  /*  Astop1 = 1;      % First Stopband Attenuation (dB) */
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
  for (i = 0; i < 15; i++) {
    Hd.cSFunObject.P1_RTP1COEFF[i] = fv0[i];
  }

  for (i = 0; i < 10; i++) {
    Hd.cSFunObject.P2_RTP2COEFF[i] = fv1[i];
  }

  for (i = 0; i < 6; i++) {
    Hd.cSFunObject.P3_RTP3COEFF[i] = fv2[i];
    Hd.cSFunObject.P4_RTP_COEFF3_BOOL[i] = bv0[i];
  }

  /* System object Initialization function: dsp.BiquadFilter */
  for (i = 0; i < 10; i++) {
    Hd.cSFunObject.W0_FILT_STATES[i] = Hd.cSFunObject.P0_ICRTP;
  }
}

/*
 * File trailer for doFilterf060_initialize.c
 *
 * [EOF]
 */
