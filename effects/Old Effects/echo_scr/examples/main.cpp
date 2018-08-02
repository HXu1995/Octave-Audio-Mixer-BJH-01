//
// Classroom License -- for classroom instructional use only.  Not for
// government, commercial, academic research, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 07-Jun-2018 15:50:38
//

//***********************************************************************
// This automatically generated example C main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************
// Include Files
#include "rt_nonfinite.h"
#include "echo_scr.h"
#include "main.h"
#include "echo_scr_terminate.h"
#include "echo_scr_emxAPI.h"
#include "echo_scr_initialize.h"

// Function Declarations
static emxArray_real_T *argInit_Unboundedx1_real_T();
static double argInit_real_T();
static void main_echo_scr();

// Function Definitions

//
// Arguments    : void
// Return Type  : emxArray_real_T *
//
static emxArray_real_T *argInit_Unboundedx1_real_T()
{
  emxArray_real_T *result;
  static int iv0[1] = { 2 };

  int idx0;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_real_T(1, *(int (*)[1])&iv0[0]);

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result->data[idx0] = argInit_real_T();
  }

  return result;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_echo_scr()
{
  emxArray_real_T *y;
  emxArray_real_T *sample;
  emxInitArray_real_T(&y, 1);

  // Initialize function 'echo_scr' input arguments.
  // Initialize function input argument 'sample'.
  sample = argInit_Unboundedx1_real_T();

  // Call the entry-point 'echo_scr'.
  echo_scr(sample, argInit_real_T(), argInit_real_T(), argInit_real_T(),
           argInit_real_T(), y);
  emxDestroyArray_real_T(y);
  emxDestroyArray_real_T(sample);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  echo_scr_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_echo_scr();

  // Terminate the application.
  // You do not need to do this more than one time.
  echo_scr_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
