/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: doFilterf6k22k_initialize.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 08-Jun-2018 12:29:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "doFilterf6k22k.h"
#include "doFilterf6k22k_initialize.h"
#include "doFilterf6k22k_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void doFilterf6k22k_initialize(void)
{
  static const double dv0[21] = { 1.0, -1.4720296027166, 1.0, 1.0,
    1.93948333358488, 1.0, 1.0, -1.54005662867438, 1.0, 1.0, 1.94817961531891,
    1.0, 1.0, -1.76131670822259, 1.0, 1.0, 1.97452134343481, 1.0, 1.0, 0.0, -1.0
  };

  static const double dv1[14] = { -1.40308143132317, 0.979923733546906,
    1.92512664524393, 0.992610409669, -1.28979128016779, 0.895325967326599,
    1.88596962817023, 0.959829712422001, -0.857309726833291, 0.602460932440392,
    1.71069405788019, 0.818703044704657, 0.593237698596974, 0.146047228406217 };

  static const double dv2[8] = { 0.641681911409801, 0.641681911409801,
    0.918198031503191, 0.918198031503191, 0.717002236260881, 0.717002236260881,
    0.992506013736531, 0.0 };

  int i;
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
  Hd.cSFunObject.P0_ICRTP = 0.0;
  memcpy(&Hd.cSFunObject.P1_RTP1COEFF[0], &dv0[0], 21U * sizeof(double));
  memcpy(&Hd.cSFunObject.P2_RTP2COEFF[0], &dv1[0], 14U * sizeof(double));
  memcpy(&Hd.cSFunObject.P3_RTP3COEFF[0], &dv2[0], sizeof(double) << 3);
  for (i = 0; i < 8; i++) {
    Hd.cSFunObject.P4_RTP_COEFF3_BOOL[i] = bv0[i];
  }

  /* System object Initialization function: dsp.BiquadFilter */
  for (i = 0; i < 14; i++) {
    Hd.cSFunObject.W0_FILT_STATES[i] = Hd.cSFunObject.P0_ICRTP;
  }
}

/*
 * File trailer for doFilterf6k22k_initialize.c
 *
 * [EOF]
 */
