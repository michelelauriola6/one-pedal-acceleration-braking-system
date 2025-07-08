/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_imp.c
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
#include "rtwtypes.h"
#include "controller_imp_types.h"
#include "controller_imp_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Named constants for Chart: '<S5>/Controller' */
#define control_IN_BackwardAcceleration ((uint8_T)1U)
#define controll_IN_RegenarativeBraking ((uint8_T)3U)
#define controller_i_IN_BackwardRestart ((uint8_T)2U)
#define controller_i_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define controller_imp_IN_Acceleration ((uint8_T)1U)
#define controller_imp_IN_Brake        ((uint8_T)1U)
#define controller_imp_IN_Drive        ((uint8_T)2U)
#define controller_imp_IN_EmergencyStop ((uint8_T)2U)
#define controller_imp_IN_Limiter      ((uint8_T)2U)
#define controller_imp_IN_Limiter_g    ((uint8_T)3U)
#define controller_imp_IN_Neutral      ((uint8_T)3U)
#define controller_imp_IN_Park         ((uint8_T)4U)
#define controller_imp_IN_Restart      ((uint8_T)4U)
#define controller_imp_IN_Restart_h    ((uint8_T)3U)
#define controller_imp_IN_Reverse      ((uint8_T)5U)
#define controller_imp_IN_Stop         ((uint8_T)5U)
#define controller_imp_IN_Stop_d       ((uint8_T)4U)

/* Block signals (default storage) */
B_controller_imp_T controller_imp_B;

/* Block states (default storage) */
DW_controller_imp_T controller_imp_DW;

/* Real-time model */
static RT_MODEL_controller_imp_T controller_imp_M_;
RT_MODEL_controller_imp_T *const controller_imp_M = &controller_imp_M_;

/* Forward declaration for local functions */
static void controller_imp_Brake(const boolean_T *OR, const TransmissionState
  *Controlled_ATSS, const boolean_T *Controlled_BPP, const real32_T
  *Controlled_VS, const real32_T *TPP, TransmissionState
  *AutomaticTransmissionState);
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<S5>/Controller' */
static void controller_imp_Brake(const boolean_T *OR, const TransmissionState
  *Controlled_ATSS, const boolean_T *Controlled_BPP, const real32_T
  *Controlled_VS, const real32_T *TPP, TransmissionState
  *AutomaticTransmissionState)
{
  *AutomaticTransmissionState = Brake;
  if (((int16_T)*Controlled_ATSS != 4) || (*OR)) {
    controller_imp_DW.is_Brake = controller_i_IN_NO_ACTIVE_CHILD;
    controller_imp_DW.is_c3_controller_imp = controller_imp_IN_Drive;
    *AutomaticTransmissionState = Drive;
    controller_imp_DW.is_Drive = controller_imp_IN_Acceleration;
  } else {
    switch (controller_imp_DW.is_Brake) {
     case controller_imp_IN_Acceleration:
      if (*TPP <= 0.33333333333333331) {
        controller_imp_DW.is_Brake = controll_IN_RegenarativeBraking;
      } else if ((*Controlled_BPP) || controller_imp_B.LogicalOperator) {
        controller_imp_DW.is_Brake = controller_imp_IN_EmergencyStop;
      } else {
        controller_imp_B.TorqueRequest_Nm = controller_imp_P.MAX_TORQUE * 3.0F /
          2.0F * (*TPP - 0.333333343F);
      }
      break;

     case controller_imp_IN_EmergencyStop:
      if ((!*Controlled_BPP) && (!controller_imp_B.LogicalOperator)) {
        controller_imp_DW.is_Brake = controll_IN_RegenarativeBraking;
      } else {
        controller_imp_B.TorqueRequest_Nm = 0.0F;
      }
      break;

     case controll_IN_RegenarativeBraking:
      if (*TPP > 0.33333333333333331) {
        controller_imp_DW.is_Brake = controller_imp_IN_Acceleration;
      } else if (*Controlled_VS <= controller_imp_P.MAX_RDB_ENGAGE_SPEED) {
        controller_imp_DW.is_Brake = controller_imp_IN_Stop;
      } else if (*Controlled_BPP) {
        controller_imp_DW.is_Brake = controller_imp_IN_EmergencyStop;
      } else {
        controller_imp_B.TorqueRequest_Nm = (1.0F - 3.0F * *TPP) *
          -controller_imp_P.MAX_TORQUE;
      }
      break;

     case controller_imp_IN_Restart:
      if ((*TPP <= 0.33333333333333331) || (*Controlled_BPP)) {
        controller_imp_DW.is_Brake = controller_imp_IN_Stop;
      } else if (*Controlled_VS > controller_imp_P.MAX_RDB_ENGAGE_SPEED) {
        controller_imp_DW.is_Brake = controller_imp_IN_Acceleration;
      } else {
        controller_imp_B.TorqueRequest_Nm = controller_imp_P.MAX_TORQUE / 20.0F;
      }
      break;

     default:
      /* case IN_Stop: */
      if (*TPP > 0.33333333333333331) {
        controller_imp_DW.is_Brake = controller_imp_IN_Restart;
      } else if (*Controlled_BPP) {
        controller_imp_DW.is_Brake = controller_imp_IN_EmergencyStop;
      } else {
        controller_imp_B.TorqueRequest_Nm = 0.0F;
      }
      break;
    }
  }
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void controller_imp_step(void)
{
  real_T rtb_Add;
  real_T rtb_Add_m;
  real32_T Diff_1_2;
  real32_T Diff_1_3;
  real32_T rtb_Cast;
  real32_T rtb_Cast1;
  int16_T i;
  int16_T rtb_PedalError;
  uint16_T b_varargout_1;
  boolean_T rtb_y_p[5];
  boolean_T rtb_y_h[2];
  boolean_T Controlled_BPP;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  boolean_T rtb_Fault_ATSS;
  boolean_T rtb_Fault_TPP;
  boolean_T rtb_Fault_TR;
  boolean_T rtb_Limiter_TR;
  boolean_T y;
  TransmissionState Controlled_ATSS;
  TransmissionState rtb_Cast4;
  WarningType rtb_Warning;

  /* MATLABSystem: '<Root>/Analog Input3' */
  controller_imp_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (controller_imp_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Rounding: '<Root>/Round1' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double3'
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Gain9'
   *  MATLABSystem: '<Root>/Analog Input3'
   * */
  rtb_Add_m = rt_roundd_snf(controller_imp_P.Gain3_Gain * (real_T)b_varargout_1 *
    controller_imp_P.Gain9_Gain);

  /* MATLAB Function: '<S7>/BPP_Plausability' incorporates:
   *  DataTypeConversion: '<Root>/Cast3'
   */
  Controlled_BPP = (rtb_Add_m != 0.0);

  /* MATLABSystem: '<Root>/Analog Input' */
  controller_imp_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(15UL);
  MW_AnalogInSingle_ReadResult
    (controller_imp_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<Root>/Cast' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain6'
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  rtb_Cast = (real32_T)(controller_imp_P.Gain_Gain * (real_T)b_varargout_1 *
                        controller_imp_P.Gain6_Gain);

  /* MATLABSystem: '<Root>/Analog Input1' */
  controller_imp_DW.obj_fl.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(16UL);
  MW_AnalogInSingle_ReadResult
    (controller_imp_DW.obj_fl.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<Root>/Cast1' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double1'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain7'
   *  MATLABSystem: '<Root>/Analog Input1'
   * */
  rtb_Cast1 = (real32_T)(controller_imp_P.Gain1_Gain * (real_T)b_varargout_1 *
    controller_imp_P.Gain7_Gain);

  /* MATLABSystem: '<Root>/Analog Input2' */
  controller_imp_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(17UL);
  MW_AnalogInSingle_ReadResult
    (controller_imp_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Gain: '<Root>/Gain8' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double2'
   *  Gain: '<Root>/Gain2'
   *  MATLABSystem: '<Root>/Analog Input2'
   * */
  rtb_Add = controller_imp_P.Gain2_Gain * (real_T)b_varargout_1 *
    controller_imp_P.Gain8_Gain;

  /* MATLAB Function: '<S7>/Warning_Detection' incorporates:
   *  MATLAB Function: '<S7>/Voter_TPP'
   */
  controller_imp_B.Warning_set[0] = Off;

  /* MATLAB Function: '<S7>/Voter_TPP' incorporates:
   *  DataTypeConversion: '<Root>/Cast2'
   */
  rtb_PedalError = 0;
  rtb_Fault_TPP = false;
  Diff_1_2 = (real32_T)fabs(rtb_Cast - rtb_Cast1);
  Diff_1_3 = (real32_T)fabs(rtb_Cast - (real32_T)rtb_Add);
  if ((Diff_1_2 <= 0.02) && (Diff_1_3 <= 0.02)) {
    rtb_Cast = ((rtb_Cast + rtb_Cast1) + (real32_T)rtb_Add) / 3.0F;
  } else if (Diff_1_2 <= 0.02) {
    rtb_Cast = (rtb_Cast + rtb_Cast1) / 2.0F;

    /* MATLAB Function: '<S7>/Warning_Detection' */
    controller_imp_B.Warning_set[0] = Yellow;
    rtb_PedalError = 3;
  } else if (Diff_1_3 <= 0.02) {
    rtb_Cast = (rtb_Cast + (real32_T)rtb_Add) / 2.0F;

    /* MATLAB Function: '<S7>/Warning_Detection' */
    controller_imp_B.Warning_set[0] = Yellow;
    rtb_PedalError = 2;
  } else if ((real32_T)fabs(rtb_Cast1 - (real32_T)rtb_Add) <= 0.02) {
    rtb_Cast = (rtb_Cast1 + (real32_T)rtb_Add) / 2.0F;

    /* MATLAB Function: '<S7>/Warning_Detection' */
    controller_imp_B.Warning_set[0] = Yellow;
    rtb_PedalError = 1;
  } else {
    rtb_Cast = 0.0F;

    /* MATLAB Function: '<S7>/Warning_Detection' */
    controller_imp_B.Warning_set[0] = Red;
    rtb_Fault_TPP = true;
    rtb_PedalError = 4;
  }

  /* MATLABSystem: '<Root>/Analog Input4' */
  controller_imp_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(18UL);
  MW_AnalogInSingle_ReadResult
    (controller_imp_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double4'
   *  Gain: '<Root>/Gain10'
   *  Gain: '<Root>/Gain4'
   *  MATLABSystem: '<Root>/Analog Input4'
   *  Rounding: '<Root>/Round2'
   * */
  rtb_Add = rt_roundd_snf(controller_imp_P.Gain4_Gain * (real_T)b_varargout_1 *
    controller_imp_P.Gain10_Gain);
  if (rtIsNaN(rtb_Add) || rtIsInf(rtb_Add)) {
    rtb_Add = 0.0;
  } else {
    rtb_Add = fmod(rtb_Add, 4.294967296E+9);
  }

  /* DataTypeConversion: '<Root>/Cast4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   */
  rtb_Cast4 = (TransmissionState)(rtb_Add < 0.0 ? -(int32_T)(uint32_T)-rtb_Add :
    (int32_T)(uint32_T)rtb_Add);

  /* MATLAB Function: '<S7>/ATSS_Plausability' */
  Controlled_ATSS = Neutral;

  /* MATLAB Function: '<S7>/Warning_Detection' incorporates:
   *  MATLAB Function: '<S7>/ATSS_Plausability'
   */
  controller_imp_B.Warning_set[2] = Off;

  /* MATLAB Function: '<S7>/ATSS_Plausability' */
  rtb_Fault_ATSS = false;
  for (i = 0; i < 5; i++) {
    rtb_y_p[i] = ((int16_T)rtb_Cast4 == i);
  }

  y = false;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 5)) {
    if (rtb_y_p[i]) {
      y = true;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (y) {
    Controlled_ATSS = rtb_Cast4;
  } else {
    /* MATLAB Function: '<S7>/Warning_Detection' */
    controller_imp_B.Warning_set[2] = Red;
    rtb_Fault_ATSS = true;
  }

  /* MATLAB Function: '<S7>/Warning_Detection' incorporates:
   *  MATLAB Function: '<S7>/TR_Plausability'
   */
  controller_imp_B.Warning_set[4] = Off;

  /* MATLAB Function: '<S7>/TR_Plausability' incorporates:
   *  UnitDelay: '<S5>/Unit Delay'
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  rtb_Fault_TR = false;
  rtb_Limiter_TR = false;
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (controller_imp_DW.UnitDelay_DSTATE == 0.0F) {
    guard2 = true;
  } else if (controller_imp_DW.UnitDelay_DSTATE > 0.0F) {
    rtb_y_h[0] = (controller_imp_DW.UnitDelay1_DSTATE == Drive);
    rtb_y_h[1] = (controller_imp_DW.UnitDelay1_DSTATE == Brake);
    y = false;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 2)) {
      if (rtb_y_h[i]) {
        y = true;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (y) {
      guard2 = true;
    } else {
      guard3 = true;
    }
  } else {
    guard3 = true;
  }

  if (guard3) {
    if (controller_imp_DW.UnitDelay_DSTATE < 0.0F) {
      rtb_y_h[0] = (controller_imp_DW.UnitDelay1_DSTATE == Reverse);
      rtb_y_h[1] = (controller_imp_DW.UnitDelay1_DSTATE == Brake);
      y = false;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 2)) {
        if (rtb_y_h[i]) {
          y = true;
          exitg1 = true;
        } else {
          i++;
        }
      }

      if (y) {
        guard2 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard2) {
    if ((controller_imp_DW.UnitDelay_DSTATE > 80.0F) ||
        (controller_imp_DW.UnitDelay_DSTATE < -80.0F)) {
      /* MATLAB Function: '<S7>/Warning_Detection' */
      controller_imp_B.Warning_set[4] = Yellow;
      rtb_Limiter_TR = true;
    }
  }

  if (guard1) {
    /* MATLAB Function: '<S7>/Warning_Detection' */
    controller_imp_B.Warning_set[4] = Red;
    rtb_Fault_TR = true;
  }

  /* Logic: '<S7>/OR' */
  rtb_Fault_TPP = (rtb_Fault_TPP || rtb_Fault_ATSS || rtb_Fault_TR);

  /* MATLABSystem: '<Root>/Analog Input5' */
  controller_imp_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(19UL);
  MW_AnalogInSingle_ReadResult
    (controller_imp_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant'
   *  DataTypeConversion: '<Root>/Cast To Double5'
   *  Gain: '<Root>/Gain11'
   *  Gain: '<Root>/Gain5'
   *  MATLABSystem: '<Root>/Analog Input5'
   * */
  rtb_Add = controller_imp_P.Gain5_Gain * (real_T)b_varargout_1 *
    controller_imp_P.Gain11_Gain + controller_imp_P.Constant_Value;

  /* MATLAB Function: '<S7>/VS_Plausability' incorporates:
   *  DataTypeConversion: '<Root>/Cast5'
   */
  rtb_Cast1 = (real32_T)rtb_Add;

  /* MATLAB Function: '<S7>/Warning_Detection' incorporates:
   *  MATLAB Function: '<S7>/VS_Plausability'
   */
  controller_imp_B.Warning_set[3] = Off;

  /* MATLAB Function: '<S7>/VS_Plausability' incorporates:
   *  DataTypeConversion: '<Root>/Cast5'
   */
  rtb_Fault_ATSS = false;
  if (((real32_T)rtb_Add > 240.0F) || ((real32_T)rtb_Add < -60.0F)) {
    /* MATLAB Function: '<S7>/Warning_Detection' */
    controller_imp_B.Warning_set[3] = Yellow;
    rtb_Fault_ATSS = true;
  }

  /* Logic: '<S7>/Logical Operator' */
  controller_imp_B.LogicalOperator = (rtb_Fault_ATSS || rtb_Limiter_TR);

  /* Chart: '<S5>/Controller' incorporates:
   *  DataTypeConversion: '<Root>/Cast3'
   *  DataTypeConversion: '<Root>/Cast5'
   */
  if (controller_imp_DW.is_active_c3_controller_imp == 0) {
    controller_imp_DW.is_active_c3_controller_imp = 1U;
    controller_imp_DW.is_c3_controller_imp = controller_imp_IN_Park;
    controller_imp_DW.UnitDelay1_DSTATE = Park;
  } else {
    switch (controller_imp_DW.is_c3_controller_imp) {
     case controller_imp_IN_Brake:
      controller_imp_Brake(&rtb_Fault_TPP, &Controlled_ATSS, &Controlled_BPP,
                           &rtb_Cast1, &rtb_Cast,
                           &controller_imp_DW.UnitDelay1_DSTATE);
      break;

     case controller_imp_IN_Drive:
      controller_imp_DW.UnitDelay1_DSTATE = Drive;
      if (((int16_T)Controlled_ATSS == 0) || ((int16_T)Controlled_ATSS == 1) ||
          ((int16_T)Controlled_ATSS == 2) || rtb_Fault_TPP) {
        controller_imp_DW.is_Drive = controller_i_IN_NO_ACTIVE_CHILD;
        controller_imp_DW.is_c3_controller_imp = controller_imp_IN_Neutral;
        controller_imp_DW.UnitDelay1_DSTATE = Neutral;
      } else if ((rtb_Cast > 0.33333333333333331) && ((int16_T)Controlled_ATSS ==
                  4)) {
        controller_imp_DW.is_Drive = controller_i_IN_NO_ACTIVE_CHILD;
        controller_imp_DW.is_c3_controller_imp = controller_imp_IN_Brake;
        controller_imp_DW.UnitDelay1_DSTATE = Brake;
        controller_imp_DW.is_Brake = controller_imp_IN_Acceleration;
      } else {
        switch (controller_imp_DW.is_Drive) {
         case controller_imp_IN_Acceleration:
          if (rtb_Add_m != 0.0) {
            controller_imp_DW.is_Drive = controller_imp_IN_Stop_d;
          } else if (controller_imp_B.LogicalOperator) {
            controller_imp_DW.is_Drive = controller_imp_IN_Limiter;
          } else {
            controller_imp_B.TorqueRequest_Nm = controller_imp_P.MAX_TORQUE *
              rtb_Cast;
          }
          break;

         case controller_imp_IN_Limiter:
          if (!controller_imp_B.LogicalOperator) {
            controller_imp_DW.is_Drive = controller_imp_IN_Acceleration;
          } else {
            controller_imp_B.TorqueRequest_Nm = 0.0F;
          }
          break;

         case controller_imp_IN_Restart_h:
          if ((!(rtb_Add_m != 0.0)) && (rtb_Cast > 0.0F)) {
            controller_imp_DW.is_Drive = controller_imp_IN_Acceleration;
          } else {
            controller_imp_B.TorqueRequest_Nm = controller_imp_P.MAX_TORQUE /
              20.0F;
          }
          break;

         default:
          /* case IN_Stop: */
          Controlled_BPP = !(rtb_Add_m != 0.0);
          if (Controlled_BPP && ((real32_T)rtb_Add <=
                                 controller_imp_P.MAX_RDB_ENGAGE_SPEED)) {
            controller_imp_DW.is_Drive = controller_imp_IN_Restart_h;
          } else if (Controlled_BPP) {
            controller_imp_DW.is_Drive = controller_imp_IN_Acceleration;
          } else {
            controller_imp_B.TorqueRequest_Nm = 0.0F;
          }
          break;
        }
      }
      break;

     case controller_imp_IN_Neutral:
      controller_imp_DW.UnitDelay1_DSTATE = Neutral;
      Controlled_BPP = !rtb_Fault_TPP;
      if (((real32_T)rtb_Add > -5.0F) && (rtb_Add_m != 0.0) && (((int16_T)
            Controlled_ATSS == 4) || ((int16_T)Controlled_ATSS == 3)) &&
          Controlled_BPP) {
        controller_imp_DW.is_c3_controller_imp = controller_imp_IN_Drive;
        controller_imp_DW.UnitDelay1_DSTATE = Drive;
        controller_imp_DW.is_Drive = controller_imp_IN_Acceleration;
      } else if (((real32_T)rtb_Add < 5.0F) && (rtb_Add_m != 0.0) && ((int16_T)
                  Controlled_ATSS == 1) && Controlled_BPP) {
        controller_imp_DW.is_c3_controller_imp = controller_imp_IN_Reverse;
        controller_imp_DW.UnitDelay1_DSTATE = Reverse;
        controller_imp_DW.is_Reverse = control_IN_BackwardAcceleration;
      } else if (((real32_T)fabs((real32_T)rtb_Add) < 5.0F) && ((rtb_Add_m !=
                   0.0) && ((int16_T)Controlled_ATSS == 0) && Controlled_BPP)) {
        controller_imp_DW.is_c3_controller_imp = controller_imp_IN_Park;
        controller_imp_DW.UnitDelay1_DSTATE = Park;
      } else {
        controller_imp_B.TorqueRequest_Nm = 0.0F;
      }
      break;

     case controller_imp_IN_Park:
      controller_imp_DW.UnitDelay1_DSTATE = Park;
      if (((rtb_Add_m != 0.0) && ((int16_T)Controlled_ATSS != 0)) ||
          rtb_Fault_TPP) {
        controller_imp_DW.is_c3_controller_imp = controller_imp_IN_Neutral;
        controller_imp_DW.UnitDelay1_DSTATE = Neutral;
      } else {
        controller_imp_B.TorqueRequest_Nm = 0.0F;
      }
      break;

     default:
      /* case IN_Reverse: */
      controller_imp_DW.UnitDelay1_DSTATE = Reverse;
      if (((int16_T)Controlled_ATSS != 1) || rtb_Fault_TPP) {
        controller_imp_DW.is_Reverse = controller_i_IN_NO_ACTIVE_CHILD;
        controller_imp_DW.is_c3_controller_imp = controller_imp_IN_Neutral;
        controller_imp_DW.UnitDelay1_DSTATE = Neutral;
      } else {
        switch (controller_imp_DW.is_Reverse) {
         case control_IN_BackwardAcceleration:
          if (rtb_Add_m != 0.0) {
            controller_imp_DW.is_Reverse = controller_imp_IN_Stop_d;
          } else if (controller_imp_B.LogicalOperator) {
            controller_imp_DW.is_Reverse = controller_imp_IN_Limiter_g;
          } else {
            controller_imp_B.TorqueRequest_Nm =
              -controller_imp_P.MAX_TORQUE_REVERSE * rtb_Cast;
          }
          break;

         case controller_i_IN_BackwardRestart:
          if ((!(rtb_Add_m != 0.0)) && (rtb_Cast > 0.0F)) {
            controller_imp_DW.is_Reverse = control_IN_BackwardAcceleration;
          } else {
            controller_imp_B.TorqueRequest_Nm =
              -controller_imp_P.MAX_TORQUE_REVERSE / 20.0F;
          }
          break;

         case controller_imp_IN_Limiter_g:
          if (!controller_imp_B.LogicalOperator) {
            controller_imp_DW.is_Reverse = control_IN_BackwardAcceleration;
          } else {
            controller_imp_B.TorqueRequest_Nm = 0.0F;
          }
          break;

         default:
          /* case IN_Stop: */
          Controlled_BPP = !(rtb_Add_m != 0.0);
          if (Controlled_BPP && ((real32_T)fabs((real32_T)rtb_Add) <=
                                 controller_imp_P.MAX_RDB_ENGAGE_SPEED)) {
            controller_imp_DW.is_Reverse = controller_i_IN_BackwardRestart;
          } else if (Controlled_BPP) {
            controller_imp_DW.is_Reverse = control_IN_BackwardAcceleration;
          } else {
            controller_imp_B.TorqueRequest_Nm = 0.0F;
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S5>/Controller' */

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  for (i = 0; i < 5; i++) {
    rtb_y_p[i] = false;
  }

  rtb_y_p[(int16_T)controller_imp_DW.UnitDelay1_DSTATE] = true;

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* MATLABSystem: '<Root>/Digital Output2' */
  writeDigitalPin(3, (uint8_T)rtb_y_p[1]);

  /* MATLABSystem: '<Root>/Digital Output5' */
  writeDigitalPin(4, (uint8_T)rtb_y_p[2]);

  /* MATLABSystem: '<Root>/Digital Output6' */
  writeDigitalPin(5, (uint8_T)rtb_y_p[3]);

  /* MATLABSystem: '<Root>/Digital Output7' */
  writeDigitalPin(2, (uint8_T)rtb_y_p[0]);

  /* MATLABSystem: '<Root>/Digital Output8' */
  writeDigitalPin(6, (uint8_T)rtb_y_p[4]);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  rtb_PedalError = (int16_T)(real32_T)fmod(rtb_PedalError, 4.294967296E+9);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  rtb_y_h[0] = false;
  rtb_y_h[1] = false;
  if ((rtb_PedalError >= 1) && (rtb_PedalError <= 3)) {
    rtb_y_h[0] = true;
  } else if (rtb_PedalError == 4) {
    rtb_y_h[1] = true;
  }

  /* MATLABSystem: '<Root>/Digital Output4' */
  writeDigitalPin(7, (uint8_T)rtb_y_h[0]);

  /* MATLABSystem: '<Root>/Digital Output9' */
  writeDigitalPin(8, (uint8_T)rtb_y_h[1]);

  /* MATLAB Function: '<S7>/Warning_Detection' incorporates:
   *  MATLAB Function: '<S7>/BPP_Plausability'
   */
  rtb_Warning = Off;
  controller_imp_B.Warning_set[1] = Off;
  for (i = 0; i < 5; i++) {
    rtb_y_p[i] = (controller_imp_B.Warning_set[i] == Yellow);
  }

  y = false;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 5)) {
    if (rtb_y_p[i]) {
      y = true;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (y) {
    rtb_Warning = Yellow;
    for (i = 0; i < 5; i++) {
      rtb_y_p[i] = (controller_imp_B.Warning_set[i] == Red);
    }

    Controlled_BPP = false;
    rtb_PedalError = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_PedalError < 5)) {
      if (rtb_y_p[rtb_PedalError]) {
        Controlled_BPP = true;
        exitg1 = true;
      } else {
        rtb_PedalError++;
      }
    }

    if (Controlled_BPP) {
      rtb_Warning = Red;
    }
  } else {
    for (i = 0; i < 5; i++) {
      rtb_y_p[i] = (controller_imp_B.Warning_set[i] == Red);
    }

    y = false;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 5)) {
      if (rtb_y_p[i]) {
        y = true;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (y) {
      rtb_Warning = Red;
    }
  }

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  rtb_y_h[0] = false;
  rtb_y_h[1] = false;
  if ((int16_T)rtb_Warning > 0) {
    rtb_y_h[0] = false;
    rtb_y_h[1] = true;
    if ((int16_T)rtb_Warning == 1) {
      rtb_y_h[0] = true;
      rtb_y_h[1] = true;
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */

  /* MATLABSystem: '<Root>/Digital Output11' */
  writeDigitalPin(10, (uint8_T)rtb_y_h[1]);

  /* MATLABSystem: '<Root>/Digital Output14' */
  writeDigitalPin(9, (uint8_T)rtb_y_h[0]);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<Root>/Gain12'
   *  Rounding: '<Root>/Round'
   *  Sum: '<Root>/Add1'
   */
  rtb_Cast = rt_roundf_snf(controller_imp_P.Gain12_Gain *
    controller_imp_B.TorqueRequest_Nm + controller_imp_P.Constant1_Value);
  if (rtIsNaNF(rtb_Cast) || rtIsInfF(rtb_Cast)) {
    rtb_Cast = 0.0F;
  } else {
    rtb_Cast = (real32_T)fmod(rtb_Cast, 4.294967296E+9);
  }

  /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  rtb_y_h[0] = false;
  rtb_y_h[1] = false;
  if ((rtb_Cast < 0.0F ? -(int32_T)(uint32_T)-rtb_Cast : (int32_T)(uint32_T)
       rtb_Cast) >= 128L) {
    rtb_y_h[0] = true;
  } else {
    rtb_y_h[1] = true;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function3' */

  /* MATLABSystem: '<Root>/Digital Output10' */
  writeDigitalPin(12, (uint8_T)rtb_y_h[1]);

  /* MATLABSystem: '<Root>/Digital Output3' */
  writeDigitalPin(11, (uint8_T)rtb_y_h[0]);

  /* Logic: '<Root>/NOT' incorporates:
   *  Delay: '<Root>/Delay'
   */
  controller_imp_DW.Delay_DSTATE = !controller_imp_DW.Delay_DSTATE;

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Delay: '<Root>/Delay'
   */
  writeDigitalPin(13, (uint8_T)controller_imp_DW.Delay_DSTATE);

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  controller_imp_DW.UnitDelay_DSTATE = controller_imp_B.TorqueRequest_Nm;
}

/* Model initialize function */
void controller_imp_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
  controller_imp_DW.UnitDelay_DSTATE =
    controller_imp_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */
  controller_imp_DW.UnitDelay1_DSTATE =
    controller_imp_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  controller_imp_DW.Delay_DSTATE = controller_imp_P.Delay_InitialCondition;

  /* Start for MATLABSystem: '<Root>/Analog Input3' */
  controller_imp_DW.obj_f.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_f.isInitialized = 1L;
  controller_imp_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(14UL);
  controller_imp_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  controller_imp_DW.obj_c.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_c.isInitialized = 1L;
  controller_imp_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(15UL);
  controller_imp_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  controller_imp_DW.obj_fl.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_fl.isInitialized = 1L;
  controller_imp_DW.obj_fl.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(16UL);
  controller_imp_DW.obj_fl.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input2' */
  controller_imp_DW.obj_h.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_h.isInitialized = 1L;
  controller_imp_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(17UL);
  controller_imp_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input4' */
  controller_imp_DW.obj_j.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_j.isInitialized = 1L;
  controller_imp_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(18UL);
  controller_imp_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input5' */
  controller_imp_DW.obj.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj.isInitialized = 1L;
  controller_imp_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(19UL);
  controller_imp_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output2' */
  controller_imp_DW.obj_g.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_g.isInitialized = 1L;
  digitalIOSetup(3, 1);
  controller_imp_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output5' */
  controller_imp_DW.obj_di.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_di.isInitialized = 1L;
  digitalIOSetup(4, 1);
  controller_imp_DW.obj_di.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output6' */
  controller_imp_DW.obj_cj.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_cj.isInitialized = 1L;
  digitalIOSetup(5, 1);
  controller_imp_DW.obj_cj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output7' */
  controller_imp_DW.obj_d.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_d.isInitialized = 1L;
  digitalIOSetup(2, 1);
  controller_imp_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output8' */
  controller_imp_DW.obj_m.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(6, 1);
  controller_imp_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output4' */
  controller_imp_DW.obj_dz.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_dz.isInitialized = 1L;
  digitalIOSetup(7, 1);
  controller_imp_DW.obj_dz.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output9' */
  controller_imp_DW.obj_b.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_b.isInitialized = 1L;
  digitalIOSetup(8, 1);
  controller_imp_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output11' */
  controller_imp_DW.obj_e.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(10, 1);
  controller_imp_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output14' */
  controller_imp_DW.obj_p.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_p.isInitialized = 1L;
  digitalIOSetup(9, 1);
  controller_imp_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output10' */
  controller_imp_DW.obj_gt.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_gt.isInitialized = 1L;
  digitalIOSetup(12, 1);
  controller_imp_DW.obj_gt.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output3' */
  controller_imp_DW.obj_o.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_o.isInitialized = 1L;
  digitalIOSetup(11, 1);
  controller_imp_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  controller_imp_DW.obj_bh.matlabCodegenIsDeleted = false;
  controller_imp_DW.obj_bh.isInitialized = 1L;
  digitalIOSetup(13, 1);
  controller_imp_DW.obj_bh.isSetupComplete = true;
}

/* Model terminate function */
void controller_imp_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input3' */
  if (!controller_imp_DW.obj_f.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((controller_imp_DW.obj_f.isInitialized == 1L) &&
        controller_imp_DW.obj_f.isSetupComplete) {
      controller_imp_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (controller_imp_DW.obj_f.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input3' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!controller_imp_DW.obj_c.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((controller_imp_DW.obj_c.isInitialized == 1L) &&
        controller_imp_DW.obj_c.isSetupComplete) {
      controller_imp_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close
        (controller_imp_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!controller_imp_DW.obj_fl.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_fl.matlabCodegenIsDeleted = true;
    if ((controller_imp_DW.obj_fl.isInitialized == 1L) &&
        controller_imp_DW.obj_fl.isSetupComplete) {
      controller_imp_DW.obj_fl.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(16UL);
      MW_AnalogIn_Close
        (controller_imp_DW.obj_fl.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  if (!controller_imp_DW.obj_h.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((controller_imp_DW.obj_h.isInitialized == 1L) &&
        controller_imp_DW.obj_h.isSetupComplete) {
      controller_imp_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(17UL);
      MW_AnalogIn_Close
        (controller_imp_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input2' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input4' */
  if (!controller_imp_DW.obj_j.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((controller_imp_DW.obj_j.isInitialized == 1L) &&
        controller_imp_DW.obj_j.isSetupComplete) {
      controller_imp_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(18UL);
      MW_AnalogIn_Close
        (controller_imp_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input4' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input5' */
  if (!controller_imp_DW.obj.matlabCodegenIsDeleted) {
    controller_imp_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_imp_DW.obj.isInitialized == 1L) &&
        controller_imp_DW.obj.isSetupComplete) {
      controller_imp_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(19UL);
      MW_AnalogIn_Close
        (controller_imp_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input5' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!controller_imp_DW.obj_g.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output5' */
  if (!controller_imp_DW.obj_di.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_di.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output5' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output6' */
  if (!controller_imp_DW.obj_cj.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_cj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output6' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output7' */
  if (!controller_imp_DW.obj_d.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output7' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output8' */
  if (!controller_imp_DW.obj_m.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output8' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output4' */
  if (!controller_imp_DW.obj_dz.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_dz.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output9' */
  if (!controller_imp_DW.obj_b.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output9' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output11' */
  if (!controller_imp_DW.obj_e.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output11' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output14' */
  if (!controller_imp_DW.obj_p.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output14' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output10' */
  if (!controller_imp_DW.obj_gt.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_gt.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output10' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!controller_imp_DW.obj_o.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!controller_imp_DW.obj_bh.matlabCodegenIsDeleted) {
    controller_imp_DW.obj_bh.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
