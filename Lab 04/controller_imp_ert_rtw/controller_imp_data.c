/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_imp_data.c
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

#include "controller_imp.h"

/* Block parameters (default storage) */
P_controller_imp_T controller_imp_P = {
  /* Variable: MAX_RDB_ENGAGE_SPEED
   * Referenced by: '<S5>/Controller'
   */
  0.5F,

  /* Variable: MAX_TORQUE
   * Referenced by: '<S5>/Controller'
   */
  80.0F,

  /* Variable: MAX_TORQUE_REVERSE
   * Referenced by: '<S5>/Controller'
   */
  40.0F,

  /* Expression: 5/(2^10-1)
   * Referenced by: '<Root>/Gain3'
   */
  0.0048875855327468231,

  /* Expression: 1/5
   * Referenced by: '<Root>/Gain9'
   */
  0.2,

  /* Expression: 5/(2^10-1)
   * Referenced by: '<Root>/Gain'
   */
  0.0048875855327468231,

  /* Expression: 1/5
   * Referenced by: '<Root>/Gain6'
   */
  0.2,

  /* Expression: 5/(2^10-1)
   * Referenced by: '<Root>/Gain1'
   */
  0.0048875855327468231,

  /* Expression: 1/5
   * Referenced by: '<Root>/Gain7'
   */
  0.2,

  /* Expression: 5/(2^10-1)
   * Referenced by: '<Root>/Gain2'
   */
  0.0048875855327468231,

  /* Expression: 1/5
   * Referenced by: '<Root>/Gain8'
   */
  0.2,

  /* Expression: 5/(2^10-1)
   * Referenced by: '<Root>/Gain4'
   */
  0.0048875855327468231,

  /* Expression: 4/5
   * Referenced by: '<Root>/Gain10'
   */
  0.8,

  /* Expression: 5/(2^10-1)
   * Referenced by: '<Root>/Gain5'
   */
  0.0048875855327468231,

  /* Expression: 60
   * Referenced by: '<Root>/Gain11'
   */
  60.0,

  /* Expression: -60
   * Referenced by: '<Root>/Constant'
   */
  -60.0,

  /* Expression: TransmissionState.Park
   * Referenced by: '<S5>/Unit Delay1'
   */
  Park,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S5>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<Root>/Constant1'
   */
  127.5F,

  /* Computed Parameter: Gain12_Gain
   * Referenced by: '<Root>/Gain12'
   */
  1.59375F,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<Root>/Delay'
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
