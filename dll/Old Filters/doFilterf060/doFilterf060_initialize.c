/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: doFilterf060_initialize.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 07-Jun-2018 17:32:53
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
  static const double dv0[15] = { 1.0, -1.99990676824524, 1.0, 1.0,
    -1.99999886633286, 1.0, 1.0, -1.99982866516189, 1.0, 1.0, -1.99999938312097,
    1.0, 1.0, 0.0, -1.0 };

  static const double dv1[10] = { -1.99919395331032, 0.99925679870439,
    -1.99987674602107, 0.999878427127912, -1.99704176264169, 0.997085199087896,
    -1.99930790777116, 0.999310336693105, -1.9969182622425, 0.996928527319615 };

  int i;
  static const double dv2[6] = { 0.529703750143307, 0.529703750143307,
    0.424903392381323, 0.424903392381323, 0.00326747832613248, 0.0 };

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
  Hd.cSFunObject.P0_ICRTP = 0.0;
  memcpy(&Hd.cSFunObject.P1_RTP1COEFF[0], &dv0[0], 15U * sizeof(double));
  memcpy(&Hd.cSFunObject.P2_RTP2COEFF[0], &dv1[0], 10U * sizeof(double));
  for (i = 0; i < 6; i++) {
    Hd.cSFunObject.P3_RTP3COEFF[i] = dv2[i];
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
