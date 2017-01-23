/*******************************************************************************
 **  FILE INFORMATION:
 **  Filename:      ACIM_CurMode_data.c
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

/* Block parameters (auto storage) */
P_ACIM_CurMode_T ACIM_CurMode_P = {
  0,                                   /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  10,                                  /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S2>/Constant'
                                        */
  1,                                   /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S2>/Gain2'
                                        */
  439804651,                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  0,                                   /* Computed Parameter: UnitDelay5_InitialCondition
                                        * Referenced by: '<Root>/Unit Delay5'
                                        */
  347U,                                /* Computed Parameter: Lm_Gain
                                        * Referenced by: '<S1>/Lm'
                                        */
  347U,                                /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S2>/Gain'
                                        */
  1557U,                               /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S2>/Gain1'
                                        */
  4U,                                  /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S2>/Gain3'
                                        */
  0,                                   /* Computed Parameter: DiscreteTransferFcn_InitialStat
                                        * Referenced by: '<S3>/Discrete Transfer Fcn'
                                        */
  -26307,                              /* Computed Parameter: DiscreteTransferFcn_NumCoef
                                        * Referenced by: '<S3>/Discrete Transfer Fcn'
                                        */

  /*  Computed Parameter: DiscreteTransferFcn_DenCoef
   * Referenced by: '<S3>/Discrete Transfer Fcn'
   */
  { 4096, -30403 }
};

/*  Declarations  */

/******************************************************************************
 *   FILE SCOPE DATA
 ******************************************************************************/

/*****************************************************************************
 *   FUNCTIONS
 *****************************************************************************/

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
