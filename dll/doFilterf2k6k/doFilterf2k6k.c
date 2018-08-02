/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: doFilterf2k6k.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Jun-2018 11:21:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "doFilterf2k6k.h"
#include "doFilterf2k6k_data.h"

/* Function Definitions */

/*
 * DOFILTER Filters input x and returns output y.
 * Arguments    : const float x[512]
 *                float y[512]
 * Return Type  : void
 */
void doFilterf2k6k(const float x[512], float y[512])
{
  dsp_BiquadFilter_0 *obj;
  int ioIdx;
  int i;
  float stageIn;
  float numAccum;

  /*  MATLAB Code */
  /*  Generated by MATLAB(R) 9.2 and the DSP System Toolbox 9.4. */
  /*  Generated on: 30-May-2018 12:06:34 */
  /*  To generate C/C++ code from this function use the codegen command. */
  /*  Type 'help codegen' for more information. */
  obj = &Hd.cSFunObject;

  /* System object Outputs function: dsp.BiquadFilter */
  ioIdx = 0;
  for (i = 0; i < 512; i++) {
    stageIn = obj->P3_RTP3COEFF[0U] * x[ioIdx];
    stageIn -= obj->P2_RTP2COEFF[0] * obj->W0_FILT_STATES[0];
    stageIn -= obj->P2_RTP2COEFF[1] * obj->W0_FILT_STATES[1];
    numAccum = obj->P1_RTP1COEFF[0] * stageIn;
    numAccum += obj->P1_RTP1COEFF[1] * obj->W0_FILT_STATES[0];
    numAccum += obj->P1_RTP1COEFF[2] * obj->W0_FILT_STATES[1];
    obj->W0_FILT_STATES[1] = obj->W0_FILT_STATES[0];
    obj->W0_FILT_STATES[0] = stageIn;
    stageIn = obj->P3_RTP3COEFF[1U] * numAccum;
    stageIn -= obj->P2_RTP2COEFF[2] * obj->W0_FILT_STATES[2];
    stageIn -= obj->P2_RTP2COEFF[3] * obj->W0_FILT_STATES[3];
    numAccum = obj->P1_RTP1COEFF[3] * stageIn;
    numAccum += obj->P1_RTP1COEFF[4] * obj->W0_FILT_STATES[2];
    numAccum += obj->P1_RTP1COEFF[5] * obj->W0_FILT_STATES[3];
    obj->W0_FILT_STATES[3] = obj->W0_FILT_STATES[2];
    obj->W0_FILT_STATES[2] = stageIn;
    stageIn = obj->P3_RTP3COEFF[2U] * numAccum;
    stageIn -= obj->P2_RTP2COEFF[4] * obj->W0_FILT_STATES[4];
    stageIn -= obj->P2_RTP2COEFF[5] * obj->W0_FILT_STATES[5];
    numAccum = obj->P1_RTP1COEFF[6] * stageIn;
    numAccum += obj->P1_RTP1COEFF[7] * obj->W0_FILT_STATES[4];
    numAccum += obj->P1_RTP1COEFF[8] * obj->W0_FILT_STATES[5];
    obj->W0_FILT_STATES[5] = obj->W0_FILT_STATES[4];
    obj->W0_FILT_STATES[4] = stageIn;
    stageIn = obj->P3_RTP3COEFF[3U] * numAccum;
    stageIn -= obj->P2_RTP2COEFF[6] * obj->W0_FILT_STATES[6];
    stageIn -= obj->P2_RTP2COEFF[7] * obj->W0_FILT_STATES[7];
    numAccum = obj->P1_RTP1COEFF[9] * stageIn;
    numAccum += obj->P1_RTP1COEFF[10] * obj->W0_FILT_STATES[6];
    numAccum += obj->P1_RTP1COEFF[11] * obj->W0_FILT_STATES[7];
    obj->W0_FILT_STATES[7] = obj->W0_FILT_STATES[6];
    obj->W0_FILT_STATES[6] = stageIn;
    stageIn = obj->P3_RTP3COEFF[4U] * numAccum;
    stageIn -= obj->P2_RTP2COEFF[8] * obj->W0_FILT_STATES[8];
    stageIn -= obj->P2_RTP2COEFF[9] * obj->W0_FILT_STATES[9];
    numAccum = obj->P1_RTP1COEFF[12] * stageIn;
    numAccum += obj->P1_RTP1COEFF[13] * obj->W0_FILT_STATES[8];
    numAccum += obj->P1_RTP1COEFF[14] * obj->W0_FILT_STATES[9];
    obj->W0_FILT_STATES[9] = obj->W0_FILT_STATES[8];
    obj->W0_FILT_STATES[8] = stageIn;
    stageIn = obj->P3_RTP3COEFF[5U] * numAccum;
    stageIn -= obj->P2_RTP2COEFF[10] * obj->W0_FILT_STATES[10];
    stageIn -= obj->P2_RTP2COEFF[11] * obj->W0_FILT_STATES[11];
    numAccum = obj->P1_RTP1COEFF[15] * stageIn;
    numAccum += obj->P1_RTP1COEFF[16] * obj->W0_FILT_STATES[10];
    numAccum += obj->P1_RTP1COEFF[17] * obj->W0_FILT_STATES[11];
    obj->W0_FILT_STATES[11] = obj->W0_FILT_STATES[10];
    obj->W0_FILT_STATES[10] = stageIn;
    stageIn = obj->P3_RTP3COEFF[6U] * numAccum;
    stageIn -= obj->P2_RTP2COEFF[12] * obj->W0_FILT_STATES[12];
    stageIn -= obj->P2_RTP2COEFF[13] * obj->W0_FILT_STATES[13];
    numAccum = obj->P1_RTP1COEFF[18] * stageIn;
    numAccum += obj->P1_RTP1COEFF[19] * obj->W0_FILT_STATES[12];
    numAccum += obj->P1_RTP1COEFF[20] * obj->W0_FILT_STATES[13];
    obj->W0_FILT_STATES[13] = obj->W0_FILT_STATES[12];
    obj->W0_FILT_STATES[12] = stageIn;
    y[ioIdx] = numAccum;
    ioIdx++;
  }
}

/*
 * File trailer for doFilterf2k6k.c
 *
 * [EOF]
 */
