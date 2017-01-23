/*******************************************************************************
 **  FILE INFORMATION:
 **  Filename:      ACIM_CurMode.h
 **  Creation Date: 22-Jan-2017
 **  Description:   The header file for Simulink model ACIM_CurMode.
 **
 **  MODEL INFORMATION:
 **  Model Name:               ACIM_CurMode
 **  Model Description:
 **  Model Version:            1.87
 **  Model Author:             Administrator - Mon Nov 28 15:01:09 2016
 **  Last Saved Modification:  Administrator - Sun Jan 22 09:53:49 2017
 **
 **  COPYRIGHT
 **      (c)Copyright 2009£¬Wuhan Eureka Control System Co., Ltd.
 **      All rights reserved
 *******************************************************************************/
/******************************************************************************
 *  Include files
 ******************************************************************************/
#ifndef RTW_HEADER_ACIM_CurMode_h_
#define RTW_HEADER_ACIM_CurMode_h_
#include <stddef.h>
#include <string.h>
#ifndef ACIM_CurMode_COMMON_INCLUDES_
# define ACIM_CurMode_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ACIM_CurMode_COMMON_INCLUDES_ */

#include "ACIM_CurMode_types.h"

/*****************************************************************************
 *  Defines
 *****************************************************************************/

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/*****************************************************************************
 *  Data Types
 *****************************************************************************/

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
  int16_T UnitDelay5_DSTATE;           /* '<Root>/Unit Delay5' */
  int16_T DiscreteTransferFcn_states;  /* '<S3>/Discrete Transfer Fcn' */
} DW_ACIM_CurMode_T;

/* Parameters (auto storage) */
struct P_ACIM_CurMode_T_ {
  int32_T DiscreteTimeIntegrator_IC;   /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  int32_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S2>/Constant'
                                        */
  int32_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S2>/Gain2'
                                        */
  int32_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                          * Referenced by: '<S2>/Discrete-Time Integrator'
                                          */
  int16_T UnitDelay5_InitialCondition; /* Computed Parameter: UnitDelay5_InitialCondition
                                        * Referenced by: '<Root>/Unit Delay5'
                                        */
  uint16_T Lm_Gain;                    /* Computed Parameter: Lm_Gain
                                        * Referenced by: '<S1>/Lm'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S2>/Gain'
                                        */
  uint16_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S2>/Gain1'
                                        */
  uint16_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S2>/Gain3'
                                        */
  int16_T DiscreteTransferFcn_InitialStat;/* Computed Parameter: DiscreteTransferFcn_InitialStat
                                           * Referenced by: '<S3>/Discrete Transfer Fcn'
                                           */
  int16_T DiscreteTransferFcn_NumCoef; /* Computed Parameter: DiscreteTransferFcn_NumCoef
                                        * Referenced by: '<S3>/Discrete Transfer Fcn'
                                        */
  int16_T DiscreteTransferFcn_DenCoef[2];/* Computed Parameter: DiscreteTransferFcn_DenCoef
                                          * Referenced by: '<S3>/Discrete Transfer Fcn'
                                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_ACIM_CurMode_T {
  const char_T * volatile errorStatus;
};

/*****************************************************************************
 *  Macros
 *****************************************************************************/

/*****************************************************************************
 *  External Declaration
 *****************************************************************************/

/* Block parameters (auto storage) */
extern P_ACIM_CurMode_T ACIM_CurMode_P;

/* Block states (auto storage) */
extern DW_ACIM_CurMode_T ACIM_CurMode_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern int32_T CurModel_DeugTestValue; /* '<S2>/Divide' */

/* Model entry point functions */
extern void ACIM_CurMode_initialize(void);
extern void ACIM_CurMode_step(void);
extern void ACIM_CurMode_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ACIM_CurMode_T *const ACIM_CurMode_M;

/*****************************************************************************
 *  Global Function Declaration
 *****************************************************************************/

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
 * '<Root>' : 'ACIM_CurMode'
 * '<S1>'   : 'ACIM_CurMode/Flux Calculation'
 * '<S2>'   : 'ACIM_CurMode/Teta Calculation'
 * '<S3>'   : 'ACIM_CurMode/Flux Calculation/Discrete Tranfer Function'
 */
#endif                                 /* RTW_HEADER_ACIM_CurMode_h_ */

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
