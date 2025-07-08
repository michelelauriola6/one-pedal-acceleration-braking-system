/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_imp_types.h
 *
 * Code generated for Simulink model 'controller_imp'.
 *
 * Model version                  : 7.124
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sat Jun 14 19:42:13 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef controller_imp_types_h_
#define controller_imp_types_h_
#include "MW_SVD.h"
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_TransmissionState_
#define DEFINED_TYPEDEF_FOR_TransmissionState_

typedef enum {
  Park = 0,                            /* Default value */
  Reverse,
  Neutral,
  Drive,
  Brake
} TransmissionState;

#endif

#ifndef DEFINED_TYPEDEF_FOR_WarningType_
#define DEFINED_TYPEDEF_FOR_WarningType_

typedef enum {
  Off = 0,                             /* Default value */
  Yellow,
  Red
} WarningType;

#endif

/* Custom Type definition for MATLABSystem: '<Root>/Analog Input5' */
#include "MW_SVD.h"
#ifndef struct_tag_pMPPJgn69ckPBhypf3vQzD
#define struct_tag_pMPPJgn69ckPBhypf3vQzD

struct tag_pMPPJgn69ckPBhypf3vQzD
{
  MW_Handle_Type MW_ANALOGIN_HANDLE;
};

#endif                                 /* struct_tag_pMPPJgn69ckPBhypf3vQzD */

#ifndef typedef_e_arduinodriver_ArduinoAnalog_T
#define typedef_e_arduinodriver_ArduinoAnalog_T

typedef struct tag_pMPPJgn69ckPBhypf3vQzD e_arduinodriver_ArduinoAnalog_T;

#endif                             /* typedef_e_arduinodriver_ArduinoAnalog_T */

#ifndef struct_tag_FIY6N64L77TlG9jHBRqBuB
#define struct_tag_FIY6N64L77TlG9jHBRqBuB

struct tag_FIY6N64L77TlG9jHBRqBuB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  e_arduinodriver_ArduinoAnalog_T AnalogInDriverObj;
};

#endif                                 /* struct_tag_FIY6N64L77TlG9jHBRqBuB */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_FIY6N64L77TlG9jHBRqBuB codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_bpMNyLZPCJBeBnOB7xlwFB
#define struct_tag_bpMNyLZPCJBeBnOB7xlwFB

struct tag_bpMNyLZPCJBeBnOB7xlwFB
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_bpMNyLZPCJBeBnOB7xlwFB */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_bpMNyLZPCJBeBnOB7xlwFB b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_ldqgYDWP5Rq6U8J4ptL7cG
#define struct_tag_ldqgYDWP5Rq6U8J4ptL7cG

struct tag_ldqgYDWP5Rq6U8J4ptL7cG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_ldqgYDWP5Rq6U8J4ptL7cG */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_ldqgYDWP5Rq6U8J4ptL7cG codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

/* Parameters (default storage) */
typedef struct P_controller_imp_T_ P_controller_imp_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_controller_imp_T RT_MODEL_controller_imp_T;

#endif                                 /* controller_imp_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
