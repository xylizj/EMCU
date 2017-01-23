/*******************************************************************************
 **  FILE INFORMATION:
 **  Filename:      ACIM_CurMode.c
 **  Creation Date: 22-Jan-2017
 **  Description:   The C source code file of Simulink model ACIM_CurMode.
 **
 **  ABSTRACT:
 **
 **
 **  NOTES:
 **
 **
 **  MODEL INFORMATION:
 **  Model Name:         ACIM_CurMode
 **  Model Description:
 **  Model Version:      1.87
 **  Model Author:       Administrator - Mon Nov 28 15:01:09 2016
 **
 **  MODIFICATION HISTORY:
 **  Model at Code Generation: Administrator - Sun Jan 22 09:55:23 2017
 **
 **  Last Saved Modification:  Administrator - Sun Jan 22 09:53:49 2017
 **
 **
 **
 **  COPYRIGHT
 **      (c)Copyright 2009£¬Wuhan Eureka Control System Co., Ltd.
 **      All rights reserved
 *******************************************************************************/
/******************************************************************************
 *   Include files
 ******************************************************************************/
#include "ACIM_CurMode.h"
#include "ACIM_CurMode_private.h"

/*****************************************************************************
 *  Defines
 *****************************************************************************/

/*  Local Macros  */

/*  Local Defines  */

/*****************************************************************************
 *   Data Types
 *****************************************************************************/

/*****************************************************************************
 *   GLOBAL DATA
 *****************************************************************************/
/*  Definitions */

/* Exported block signals */
int32_T CurModel_DeugTestValue;        /* '<S2>/Divide' */

/* Block states (auto storage) */
DW_ACIM_CurMode_T ACIM_CurMode_DW;

/* Real-time model */
RT_MODEL_ACIM_CurMode_T ACIM_CurMode_M_;
RT_MODEL_ACIM_CurMode_T *const ACIM_CurMode_M = &ACIM_CurMode_M_;

/*  Declarations  */

/******************************************************************************
 *   FILE SCOPE DATA
 ******************************************************************************/

/*****************************************************************************
 *   FUNCTIONS
 *****************************************************************************/
int32_T div_repeat_s32_floor(int32_T numerator, int32_T denominator, uint32_T
  nRepeatSub)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = (uint32_T)(numerator >= 0 ? numerator : -numerator);
    absDenominator = (uint32_T)(denominator >= 0 ? denominator : -denominator);
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int32_T)div_nzp_repeat_u32_ceiling(absNumerator,
        absDenominator, nRepeatSub);
    } else {
      quotient = (int32_T)div_nzp_repeat_u32(absNumerator, absDenominator,
        nRepeatSub);
    }
  }

  return quotient;
}

uint32_T div_nzp_repeat_u32_ceiling(uint32_T numerator, uint32_T denominator,
  uint32_T nRepeatSub)
{
  uint32_T quotient;
  uint32_T iRepeatSub;
  boolean_T numeratorExtraBit;
  quotient = numerator / denominator;
  numerator %= denominator;
  for (iRepeatSub = 0U; iRepeatSub < nRepeatSub; iRepeatSub++) {
    numeratorExtraBit = (numerator >= 2147483648U);
    numerator <<= 1U;
    quotient <<= 1U;
    if (numeratorExtraBit || (numerator >= denominator)) {
      quotient++;
      numerator -= denominator;
    }
  }

  if (numerator > 0U) {
    quotient++;
  }

  return quotient;
}

uint32_T div_nzp_repeat_u32(uint32_T numerator, uint32_T denominator, uint32_T
  nRepeatSub)
{
  uint32_T quotient;
  uint32_T iRepeatSub;
  boolean_T numeratorExtraBit;
  quotient = numerator / denominator;
  numerator %= denominator;
  for (iRepeatSub = 0U; iRepeatSub < nRepeatSub; iRepeatSub++) {
    numeratorExtraBit = (numerator >= 2147483648U);
    numerator <<= 1U;
    quotient <<= 1U;
    if (numeratorExtraBit || (numerator >= denominator)) {
      quotient++;
      numerator -= denominator;
    }
  }

  return quotient;
}

void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = (uint32_T)(in0 < 0 ? -in0 : in0);
  absIn1 = (uint32_T)(in1 < 0 ? -in1 : in1);
  in0Hi = absIn0 >> 16U;
  in0Lo = absIn0 & 65535U;
  in1Hi = absIn1 >> 16U;
  absIn0 = absIn1 & 65535U;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0U;
  in0Lo = (productLoHi << 16U) + absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1U;
  }

  absIn0 = in0Lo;
  in0Lo += productHiLo << 16U;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    absIn1;
  if (!((in0 == 0) || ((in1 == 0) || ((in0 > 0) == (in1 > 0))))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_s32_s32_sr42(int32_T a, int32_T b)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  return (int32_T)u32_chi >> 10;
}

int32_T mul_s32_s32_s32_sat(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  if (((int32_T)u32_chi > 0) || ((u32_chi == 0U) && (u32_clo >= 2147483648U))) {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1) || (((int32_T)u32_chi == -1) && (u32_clo <
               2147483648U))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = (uint32_T)(numerator >= 0 ? numerator : -numerator);
    absDenominator = (uint32_T)(denominator >= 0 ? denominator : -denominator);
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

/* Model step function */
void ACIM_CurMode_step(void)
{
  uint32_T tmp;

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  s32_hMDRV_thRotEl = ACIM_CurMode_DW.DiscreteTimeIntegrator_DSTATE;

  /* Product: '<S2>/Divide' incorporates:
   *  Constant: '<S2>/Constant'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn'
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain1'
   *  Sum: '<S2>/Sum1'
   *  UnitDelay: '<Root>/Unit Delay5'
   */
  CurModel_DeugTestValue = div_s32_floor((int16_T)(ACIM_CurMode_P.Gain_Gain *
    ACIM_CurMode_DW.UnitDelay5_DSTATE),
    (ACIM_CurMode_P.DiscreteTransferFcn_NumCoef *
     ACIM_CurMode_DW.DiscreteTransferFcn_states >> 21) *
    ACIM_CurMode_P.Gain1_Gain + ACIM_CurMode_P.Constant_Value);

  /* Gain: '<S2>/Gain3' incorporates:
   *  Inport: '<Root>/wm'
   */
  tmp = (uint32_T)ACIM_CurMode_P.Gain3_Gain * SID_m_n_MechRPS;
  if (tmp > 65535U) {
    tmp = 65535U;
  }

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S2>/Gain2'
   *  Gain: '<S2>/Gain3'
   *  Sum: '<S2>/Sum'
   */
  ACIM_CurMode_DW.DiscreteTimeIntegrator_DSTATE += mul_s32_s32_s32_sr42
    (ACIM_CurMode_P.DiscreteTimeIntegrator_gainval, mul_s32_s32_s32_sat
     (ACIM_CurMode_P.Gain2_Gain, CurModel_DeugTestValue) + (int32_T)tmp);

  /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn' incorporates:
   *  Gain: '<S1>/Lm'
   *  Update for Inport: '<Root>/Id'
   */
  ACIM_CurMode_DW.DiscreteTransferFcn_states = (int16_T)(div_repeat_s32_floor
    (((int16_T)((int16_T)(ACIM_CurMode_P.Lm_Gain * SID_m_i_d) << 9) << 12) -
     ACIM_CurMode_P.DiscreteTransferFcn_DenCoef[1] *
     ACIM_CurMode_DW.DiscreteTransferFcn_states,
     ACIM_CurMode_P.DiscreteTransferFcn_DenCoef[0], 12U) >> 12);

  /* Update for UnitDelay: '<Root>/Unit Delay5' incorporates:
   *  Update for Inport: '<Root>/Iq'
   */
  ACIM_CurMode_DW.UnitDelay5_DSTATE = SID_m_i_q;
}

/* Model initialize function */
void ACIM_CurMode_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(ACIM_CurMode_M, (NULL));

  /* block I/O */

  /* exported global signals */
  CurModel_DeugTestValue = 0;

  /* states (dwork) */
  (void) memset((void *)&ACIM_CurMode_DW, 0,
                sizeof(DW_ACIM_CurMode_T));

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  ACIM_CurMode_DW.DiscreteTimeIntegrator_DSTATE =
    ACIM_CurMode_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn' */
  ACIM_CurMode_DW.DiscreteTransferFcn_states =
    ACIM_CurMode_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay5' */
  ACIM_CurMode_DW.UnitDelay5_DSTATE = ACIM_CurMode_P.UnitDelay5_InitialCondition;
}

/* Model terminate function */
void ACIM_CurMode_terminate(void)
{
  /* (no terminate code required) */
}

/*======================== TOOL VERSION INFORMATION ==========================*
 * MATLAB 8.3 (R2014a)27-Dec-2013                                             *
 * Simulink 8.3 (R2014a)27-Dec-2013                                           *
 * Simulink Coder 8.6 (R2014a)27-Dec-2013                                     *
 * Embedded Coder 6.6 (R2014a)27-Dec-2013                                     *
 * Stateflow 8.3 (R2014a)27-Dec-2013                                          *
 * Fixed-Point Designer 4.2 (R2014a)27-Dec-2013                               *
 *============================================================================*/

/*======================= LICENSE IN USE INFORMATION =========================*
 * fixed_point_toolbox                                                        *
 * matlab_coder                                                               *
 * real-time_workshop                                                         *
 * rtw_embedded_coder                                                         *
 * simulink                                                                   *
 *============================================================================*/
