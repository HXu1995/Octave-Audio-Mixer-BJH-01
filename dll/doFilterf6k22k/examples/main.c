/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 22-Jun-2018 11:22:36
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "doFilterf6k22k.h"
#include "main.h"
#include "doFilterf6k22k_terminate.h"
#include "doFilterf6k22k_initialize.h"

/* Function Declarations */
static void argInit_512x1_real32_T(float result[512]);
static float argInit_real32_T(void);
static void main_doFilterf6k22k(void);

/* Function Definitions */

/*
 * Arguments    : float result[512]
 * Return Type  : void
 */
static void argInit_512x1_real32_T(float result[512])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 512; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real32_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : float
 */
static float argInit_real32_T(void)
{
  return 0.0F;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_doFilterf6k22k(void)
{
  float fv3[512];
  float y[512];

  /* Initialize function 'doFilterf6k22k' input arguments. */
  /* Initialize function input argument 'x'. */
  /* Call the entry-point 'doFilterf6k22k'. */
  argInit_512x1_real32_T(fv3);
  doFilterf6k22k(fv3, y);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  doFilterf6k22k_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_doFilterf6k22k();

  /* Terminate the application.
     You do not need to do this more than one time. */
  doFilterf6k22k_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
