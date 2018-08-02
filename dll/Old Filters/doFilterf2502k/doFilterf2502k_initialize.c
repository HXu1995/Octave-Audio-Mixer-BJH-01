/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: doFilterf2502k_initialize.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 08-Jun-2018 12:28:53
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
  static const double dv0[21] = { 1.0, -1.92440892089849, 1.0, 1.0,
    -1.99903641045072, 1.0, 1.0, -1.91333503478134, 1.0, 1.0, -1.99916188143271,
    1.0, 1.0, -1.83583857829366, 1.0, 1.0, -1.99956625435506, 1.0, 1.0, 0.0,
    -1.0 };

  static const double dv1[14] = { -1.92525055064263, 0.993536943721822,
    -1.99812026677486, 0.999184943752796, -1.90701086804238, 0.968413903448253,
    -1.99440946658885, 0.995578250010221, -1.86765297035585, 0.907417071336577,
    -1.97839977843911, 0.980144002656646, -1.89749312323118, 0.905686507907269 };

  static const double dv2[8] = { 0.615024943159447, 0.615024943159447,
    0.805956485198649, 0.805956485198649, 0.425006031895317, 0.425006031895317,
    0.109615790465583, 0.0 };

  int i;
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
 * File trailer for doFilterf2502k_initialize.c
 *
 * [EOF]
 */
