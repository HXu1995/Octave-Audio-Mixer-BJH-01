/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: _coder_trem_scr_info.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 06-Jun-2018 12:11:20
 */

/* Include Files */
#include "_coder_trem_scr_info.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
const mxArray *emlrtMexFcnResolvedFunctionsInfo()
{
  const mxArray *nameCaptureInfo;
  const char * data[11] = {
    "789ced5bcd6fe34414779765d945022ca445aa3850add00aa81497dd7e840a892669d2a49bef38dba6abd576ec8c5377c71fb59d34eda9478e9c3871e302da0b"
    "9ce00837fe0138f047202e7bc78d3d4d3c7414531b67937aa46afafa4bdfefcdebf3ef8dc72e335728cd310cf3b6fd753ee73f6706e32d67625877bec1780789",
    "cfb9f39b848dc7ebcc4dcfef61fc1b771635d5827dcb3190acc2725711a0611b2a50e0859bb6a6c82a502dfe44878c014d0df5607b80483282bcacc0a23662e4"
    "65db507223d085710e9d7f9f3980e2f34657618c0373182e1a359891fc7c4959ff4d9ff9f988921f96c09f649feead7319a09b96a642ae94e28ba93497952428",
    "5a2667195079668a4642c171ed53786ff98c8b9cf1b8c3dc1eb1ee6d60be3ec59fdf3cdca5f0b1042e6a6d682464bb380c15a004826ac73a60867f8ffd2bc641"
    "0e5a1c7860be1faec887fd97c7f061fc49a1b89b7d9a59e7aa86d63180b2705eab26ae83fa83a54fd70067691a12b43e071534f85a1c648b5bc4e9e29c742594",
    "f1f90aaf4ece7e7af9e7efa968eb32caf54d962faaebae943bae3e36aa7c6165335917ca2ba77afbd41a89a33a86675c1c0cc58ecafff5d6f10f3782ea27f67f"
    "9bb0998bcf398862b4e59edc8661f1dd22ec219f83b4b5ae8060787abd4de5f3e2ff59af912c700ab01010384d37399ca784eef88bb01ee68b0b7fccb25effb8",
    "333fb97e14955ef75b7b7bd94e4a368e967b4a76856fa56a8780991dbd8eafe3cbe3f7d6dddf5f84a5b36f50f85817719719781f3e295d2f50f9bc78d07ac0e5"
    "a0b8fe22dc87bf78bf16efc3a75dd793c735a9b9bbbcba96efa1fa679bc964516b8a4cacebafca75ac53e2f35b7737081b8f3bc4e79d716fc399ef5fecdfcf28",
    "fefde6ef030a3f4be0c4398c6ca6bb32b20a6ab9ab40431627d6077e0ec8b74be5f3e2e19cc790698bf2be2f3e97f93ff982f683f7287c2c81577a47999494ef"
    "25f9daf2899855d407b93d948ffbc1abd20ff629f1855b779f84a6ff0b143e96c009fd374580605fcf688a0e2cd956e449e9ff2f01f95a543e2f1e8efeff2b6d",
    "93a89f17933c0f9975bea8fa80d06f95eb1278feb8567a54deae43abb1d4a8c47de09af581f5d09ec7be4be163099ce803f6ea9d9f4feb39d0232a9f170f47ff"
    "ed74b99512e1beffdbf81c68faf5bed4b4965a859d94aa36eb72d5ac953b267f949d1dbdbfdecf6387e739343ebf79788dc2c7ba88a8392f364d4aafbf0bc8b7",
    "45e5f3e241fa3a445257e5ec4cd95a1d611dfcdabc1febf4b4ebb4cef70fd72a567575ad02f8c6216f6c9d886a7a76743abe7ebd83f65ecd19c59fdf3ccd53f8"
    "5802bfe45c061809acf2937b4f32e8b97c630c1fc6c3d9972f3a79736b66741dfb943843ac9bd5afbf8f757fda753f69144d50134bad1da1b52ba4d3abcb5207",
    "c6ba7fed74ff2b8a3fbf79fa98c2c71238a1fb40d7d149632062b9ae2a5ab2a616d42a0222fed78971cfabfdc6f7ce98f8302eb9513c3b006a1b0ddf13fa2d20"
    "bf30861fe3e1f4057a5af1815f8475f6f2aff8f9edd4f789fcf166a6de4f9e3ed4401e6ee7aca45891d25bb3d327e2ebfbf275f9abc7c4ccdd3f5cf59c28be7f",
    "b87cc623be7f88862fbe7f08e6ff1fc90e6837", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 15456U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
mxArray *emlrtMexFcnProperties()
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[4] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 4, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", mxCreateString("trem_scr"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", mxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", mxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", mxCreateString("9.2.0.538062 (R2017a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_trem_scr_info.c
 *
 * [EOF]
 */
