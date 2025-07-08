/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_imp.h
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

#ifndef controller_imp_h_
#define controller_imp_h_
#ifndef controller_imp_COMMON_INCLUDES_
#define controller_imp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* controller_imp_COMMON_INCLUDES_ */

#include "controller_imp_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  WarningType Warning_set[5];
  real32_T TorqueRequest_Nm;           /* '<S5>/Controller' */
  boolean_T LogicalOperator;           /* '<S7>/Logical Operator' */
} B_controller_imp_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input5' */
  codertarget_arduinobase_inter_T obj_j;/* '<Root>/Analog Input4' */
  codertarget_arduinobase_inter_T obj_f;/* '<Root>/Analog Input3' */
  codertarget_arduinobase_inter_T obj_h;/* '<Root>/Analog Input2' */
  codertarget_arduinobase_inter_T obj_fl;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_c;/* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_b;/* '<Root>/Digital Output9' */
  codertarget_arduinobase_block_T obj_m;/* '<Root>/Digital Output8' */
  codertarget_arduinobase_block_T obj_d;/* '<Root>/Digital Output7' */
  codertarget_arduinobase_block_T obj_cj;/* '<Root>/Digital Output6' */
  codertarget_arduinobase_block_T obj_di;/* '<Root>/Digital Output5' */
  codertarget_arduinobase_block_T obj_dz;/* '<Root>/Digital Output4' */
  codertarget_arduinobase_block_T obj_o;/* '<Root>/Digital Output3' */
  codertarget_arduinobase_block_T obj_g;/* '<Root>/Digital Output2' */
  codertarget_arduinobase_block_T obj_p;/* '<Root>/Digital Output14' */
  codertarget_arduinobase_block_T obj_e;/* '<Root>/Digital Output11' */
  codertarget_arduinobase_block_T obj_gt;/* '<Root>/Digital Output10' */
  codertarget_arduinobase_block_T obj_bh;/* '<Root>/Digital Output1' */
  real32_T UnitDelay_DSTATE;           /* '<S5>/Unit Delay' */
  TransmissionState UnitDelay1_DSTATE; /* '<S5>/Unit Delay1' */
  boolean_T Delay_DSTATE;              /* '<Root>/Delay' */
  uint8_T is_active_c3_controller_imp; /* '<S5>/Controller' */
  uint8_T is_c3_controller_imp;        /* '<S5>/Controller' */
  uint8_T is_Brake;                    /* '<S5>/Controller' */
  uint8_T is_Drive;                    /* '<S5>/Controller' */
  uint8_T is_Reverse;                  /* '<S5>/Controller' */
} DW_controller_imp_T;

/* Parameters (default storage) */
struct P_controller_imp_T_ {
  real32_T MAX_RDB_ENGAGE_SPEED;       /* Variable: MAX_RDB_ENGAGE_SPEED
                                        * Referenced by: '<S5>/Controller'
                                        */
  real32_T MAX_TORQUE;                 /* Variable: MAX_TORQUE
                                        * Referenced by: '<S5>/Controller'
                                        */
  real32_T MAX_TORQUE_REVERSE;         /* Variable: MAX_TORQUE_REVERSE
                                        * Referenced by: '<S5>/Controller'
                                        */
  real_T Gain3_Gain;                   /* Expression: 5/(2^10-1)
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Gain9_Gain;                   /* Expression: 1/5
                                        * Referenced by: '<Root>/Gain9'
                                        */
  real_T Gain_Gain;                    /* Expression: 5/(2^10-1)
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1/5
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T Gain1_Gain;                   /* Expression: 5/(2^10-1)
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain7_Gain;                   /* Expression: 1/5
                                        * Referenced by: '<Root>/Gain7'
                                        */
  real_T Gain2_Gain;                   /* Expression: 5/(2^10-1)
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain8_Gain;                   /* Expression: 1/5
                                        * Referenced by: '<Root>/Gain8'
                                        */
  real_T Gain4_Gain;                   /* Expression: 5/(2^10-1)
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Gain10_Gain;                  /* Expression: 4/5
                                        * Referenced by: '<Root>/Gain10'
                                        */
  real_T Gain5_Gain;                   /* Expression: 5/(2^10-1)
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Gain11_Gain;                  /* Expression: 60
                                        * Referenced by: '<Root>/Gain11'
                                        */
  real_T Constant_Value;               /* Expression: -60
                                        * Referenced by: '<Root>/Constant'
                                        */
  TransmissionState UnitDelay1_InitialCondition;/* Expression: TransmissionState.Park
                                                 * Referenced by: '<S5>/Unit Delay1'
                                                 */
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S5>/Unit Delay'
                                */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real32_T Gain12_Gain;                /* Computed Parameter: Gain12_Gain
                                        * Referenced by: '<Root>/Gain12'
                                        */
  boolean_T Delay_InitialCondition;/* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<Root>/Delay'
                                    */
};

/* Real-time Model Data Structure */
struct tag_RTM_controller_imp_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_controller_imp_T controller_imp_P;

/* Block signals (default storage) */
extern B_controller_imp_T controller_imp_B;

/* Block states (default storage) */
extern DW_controller_imp_T controller_imp_DW;

/* Model entry point functions */
extern void controller_imp_initialize(void);
extern void controller_imp_step(void);
extern void controller_imp_terminate(void);

/* Real-time Model object */
extern RT_MODEL_controller_imp_T *const controller_imp_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'controller_imp'
 * '<S1>'   : 'controller_imp/MATLAB Function'
 * '<S2>'   : 'controller_imp/MATLAB Function1'
 * '<S3>'   : 'controller_imp/MATLAB Function2'
 * '<S4>'   : 'controller_imp/MATLAB Function3'
 * '<S5>'   : 'controller_imp/Subsystem'
 * '<S6>'   : 'controller_imp/Subsystem/Controller'
 * '<S7>'   : 'controller_imp/Subsystem/Functional Redundancy and Plausability'
 * '<S8>'   : 'controller_imp/Subsystem/Functional Redundancy and Plausability/ATSS_Plausability'
 * '<S9>'   : 'controller_imp/Subsystem/Functional Redundancy and Plausability/BPP_Plausability'
 * '<S10>'  : 'controller_imp/Subsystem/Functional Redundancy and Plausability/TR_Plausability'
 * '<S11>'  : 'controller_imp/Subsystem/Functional Redundancy and Plausability/VS_Plausability'
 * '<S12>'  : 'controller_imp/Subsystem/Functional Redundancy and Plausability/Voter_TPP'
 * '<S13>'  : 'controller_imp/Subsystem/Functional Redundancy and Plausability/Warning_Detection'
 */
#endif                                 /* controller_imp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
