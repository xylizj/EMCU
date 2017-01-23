/*******************************************************************************
 **  FILE INFORMATION:
 **  Filename:      ACIM_CurMode_private.h
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
#ifndef RTW_HEADER_ACIM_CurMode_private_h_
#define RTW_HEADER_ACIM_CurMode_private_h_
#include "rtwtypes.h"

/*****************************************************************************
 *  Defines
 *****************************************************************************/
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

/*****************************************************************************
 *  Data Types
 *****************************************************************************/

/*****************************************************************************
 *  Macros
 *****************************************************************************/

/*****************************************************************************
 *  External Declaration
 *****************************************************************************/

/* Imported (extern) block signals */
extern int32_T s32_hMDRV_thRotEl;      /* '<S2>/Discrete-Time Integrator' */
extern int16_T SID_m_i_d;              /* '<Root>/Id' */
extern uint16_T SID_m_n_MechRPS;       /* '<Root>/wm' */
extern int16_T SID_m_i_q;              /* '<Root>/Iq' */
extern int32_T div_repeat_s32_floor(int32_T numerator, int32_T denominator,
  uint32_T nRepeatSub);
extern uint32_T div_nzp_repeat_u32_ceiling(uint32_T numerator, uint32_T
  denominator, uint32_T nRepeatSub);
extern uint32_T div_nzp_repeat_u32(uint32_T numerator, uint32_T denominator,
  uint32_T nRepeatSub);
extern void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern int32_T mul_s32_s32_s32_sr42(int32_T a, int32_T b);
extern int32_T mul_s32_s32_s32_sat(int32_T a, int32_T b);
extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);

/*****************************************************************************
 *  Global Function Declaration
 *****************************************************************************/
#endif                                 /* RTW_HEADER_ACIM_CurMode_private_h_ */

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
