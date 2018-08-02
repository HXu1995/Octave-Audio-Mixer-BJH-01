/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: doFilterf2k6k_initialize.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 21-Jun-2018 13:12:34
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
  static const double dv0[21] = { 1.0, -1.37784021595965, 1.0, 1.0,
    -1.936445220913, 1.0, 1.0, -1.32555127968238, 1.0, 1.0, -1.94219575483135,
    1.0, 1.0, -1.00311060985691, 1.0, 1.0, -1.96448450162766, 1.0, 1.0, 0.0,
    -1.0 };

  static const double dv1[14] = { -1.40419027334361, 0.988297980125513,
    -1.92794558533864, 0.995713403871643, -1.40274026520441, 0.943236231731457,
    -1.90625411241804, 0.977756018138362, -1.4321565747206, 0.835853284355609,
    -1.82685994843216, 0.916986554555256, -1.60781515949805, 0.793284792422562 };

  static const double dv2[8] = { 0.615929735219473, 0.615929735219473,
    0.807281257358317, 0.807281257358317, 0.436539090785192, 0.436539090785192,
    0.240254605964319, 0.0 };

  int i;
  static const boolean_T bv0[8] = { true, true, true, true, true, true, true,
    false };

  rt_InitInfAndNaN(8U);

  /*  The following code was used to design the filter coefficients: */
  /*  */
  /*  Fstop1 = 1700;   % First Stopband Frequency */
  /*  Fpass1 = 2000;   % First Passband Frequency */
  /*  Fpass2 = 6000;   % Second Passband Frequency */
  /*  Fstop2 = 6300;   % Second Stopband Frequency */
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
 * File trailer for doFilterf2k6k_initialize.c
 *
 * [EOF]
 */
