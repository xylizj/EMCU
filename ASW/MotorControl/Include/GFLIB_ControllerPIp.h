/******************************************************************************
*
*   (c) Copyright 2015 Freescale Semiconductor, Inc.
*   All Rights Reserved.
*
******************************************************************************/
/*!
*
* @file       GFLIB_ControllerPIp.h
*
* @version    1.0.7.0
*
* @date       Mar-10-2014
*
* @brief      Header file for GFLIB_ControllerPIp function
*
******************************************************************************/
#ifndef GFLIB_CONTROLLERPIP_H
#define GFLIB_CONTROLLERPIP_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section GFLIB_ControllerPIp_h_REF_1
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of disallowed macro
* definition.
*
* @section GFLIB_ControllerPIp_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires the function-like macro
* definition.
*
* @section GFLIB_ControllerPIp_h_REF_3
* Violates MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter in definition of macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of unparenthesized
* macro parameters.
*
* @section GFLIB_ControllerPIp_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of '#/##' operators.
*
* @section GFLIB_ControllerPIp_h_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters.
* This is not a violation since all the used compilers interpret the identifiers correctly.
*
* @section GFLIB_ControllerPIp_h_REF_6
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* This is not a violation since all the used compilers interpret the identifiers correctly.
*/
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
  /*
  * @violates @ref GFLIB_ControllerPIp_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
  * for macro.
  * @violates @ref GFLIB_ControllerPIp_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
  * defined.
  * @violates @ref GFLIB_ControllerPIp_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  */
  #define GFLIB_ControllerPIp(...)     macro_dispatcher(GFLIB_ControllerPIp, __VA_ARGS__)(__VA_ARGS__)     /*!< This function calculates a parallel form of the Proportional- Integral controller, without integral anti-windup. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /*
    * @violates @ref GFLIB_ControllerPIp_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed
    * definition for macro.
    */
    #define GFLIB_CONTROLLER_PI_P_T                         GFLIB_CONTROLLER_PI_P_T_F32                         /*!< Definition of GFLIB_CONTROLLER_PI_P_T as alias for GFLIB_CONTROLLER_PI_P_T_F32 datatype in case the 32-bit fractional implementation is selected. */
    /*
    * @violates @ref GFLIB_ControllerPIp_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed
    * definition for macro.
    */
    #define GFLIB_CONTROLLER_PI_P_DEFAULT                   GFLIB_CONTROLLER_PI_P_DEFAULT_F32                   /*!< Definition of GFLIB_CONTROLLER_PI_P_DEFAULT as alias for GFLIB_CONTROLLER_PI_P_DEFAULT_F32 default value in case the 32-bit fractional implementation is selected. */
    /*
    * @violates @ref GFLIB_ControllerPIp_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed
    * definition for macro.
    * @violates @ref GFLIB_ControllerPIp_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
    * defined.
    * @violates @ref GFLIB_ControllerPIp_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized
    * macro parameter in definition of macro.
    */
    /** @remarks Implements DGFLIB00300 */
    #define GFLIB_ControllerPIp_Dsptchr_2(InErr,pParam)     GFLIB_ControllerPIp_Dsptchr_3(InErr,pParam,F32)     /*!< Function dispatcher for GFLIB_ControllerPIp_Dsptchr_2, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /*
    * @violates @ref GFLIB_ControllerPIp_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed
    * definition for macro.
    */
    #define GFLIB_CONTROLLER_PI_P_T                         GFLIB_CONTROLLER_PI_P_T_F16                         /*!< Definition of GFLIB_CONTROLLER_PI_P_T as alias for GFLIB_CONTROLLER_PI_P_T_F16 datatype in case the 16-bit fractional implementation is selected. */
    /*
    * @violates @ref GFLIB_ControllerPIp_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed
    * definition for macro.
    */
    #define GFLIB_CONTROLLER_PI_P_DEFAULT                   GFLIB_CONTROLLER_PI_P_DEFAULT_F16                   /*!< Definition of GFLIB_CONTROLLER_PI_P_DEFAULT as alias for GFLIB_CONTROLLER_PI_P_DEFAULT_F16 default value in case the 16-bit fractional implementation is selected. */
    /*
    * @violates @ref GFLIB_ControllerPIp_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed
    * definition for macro.
    * @violates @ref GFLIB_ControllerPIp_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
    * defined.
    * @violates @ref GFLIB_ControllerPIp_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized
    * macro parameter in definition of macro.
    */
    /** @remarks Implements DGFLIB00300 */
    #define GFLIB_ControllerPIp_Dsptchr_2(InErr,pParam)     GFLIB_ControllerPIp_Dsptchr_3(InErr,pParam,F16)     /*!< Function dispatcher for GFLIB_ControllerPIp_Dsptchr_2, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /*
    * @violates @ref GFLIB_ControllerPIp_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed
    * definition for macro.
    */
    #define GFLIB_CONTROLLER_PI_P_T                         GFLIB_CONTROLLER_PI_P_T_FLT                         /*!< Definition of GFLIB_CONTROLLER_PI_P_T as alias for GFLIB_CONTROLLER_PI_P_T_FLT datatype in case the single precision floating point implementation is selected. */
    /*
    * @violates @ref GFLIB_ControllerPIp_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed
    * definition for macro.
    */
    #define GFLIB_CONTROLLER_PI_P_DEFAULT                   GFLIB_CONTROLLER_PI_P_DEFAULT_FLT                   /*!< Definition of GFLIB_CONTROLLER_PI_P_DEFAULT as alias for GFLIB_CONTROLLER_PI_P_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /*
    * @violates @ref GFLIB_ControllerPIp_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed
    * definition for macro.
    * @violates @ref GFLIB_ControllerPIp_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
    * defined.
    * @violates @ref GFLIB_ControllerPIp_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized
    * macro parameter in definition of macro.
    */
    /** @remarks Implements DGFLIB00300 */
    #define GFLIB_ControllerPIp_Dsptchr_2(InErr,pParam)     GFLIB_ControllerPIp_Dsptchr_3(InErr,pParam,FLT)     /*!< Function dispatcher for GFLIB_ControllerPIp_Dsptchr_2, do not modify!!! */
  #endif

  /*
  * @violates @ref GFLIB_ControllerPIp_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
  * for macro.
  * @violates @ref GFLIB_ControllerPIp_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
  * defined.
  * @violates @ref GFLIB_ControllerPIp_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  */
  #define GFLIB_ControllerPIp_Dsptchr_3(InErr,pParam,Impl)    GFLIB_ControllerPIp_Dsptchr_(InErr,pParam,Impl)     /*!< Function dispatcher for GFLIB_ControllerPIp_Dsptchr_3, do not modify!!! */

  /*
  * @violates @ref GFLIB_ControllerPIp_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
  * for macro.
  * @violates @ref GFLIB_ControllerPIp_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
  * defined.
  * @violates @ref GFLIB_ControllerPIp_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  * @violates @ref GFLIB_ControllerPIp_h_REF_4 MISRA 2004 Advisory Rule 19.13, #/##' operator used
  * in macro.
  */
  /** @remarks Implements DGFLIB00303 */
  #define GFLIB_ControllerPIp_Dsptchr_(InErr,pParam,Impl)     GFLIB_ControllerPIp_##Impl(InErr,pParam)            /*!< Function dispatcher for GFLIB_ControllerPIp_Dsptchr_, do not modify!!! */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  /*
  * @violates @ref GFLIB_ControllerPIp_h_REF_5 MISRA 2004 Required Rule 5.1, Identifier exceeds 31
  * characters.
  */
  #define GFLIB_CONTROLLER_PI_P_DEFAULT_F32 {(tFrac32)0,(tFrac32)0,(tS16)0,(tS16)0,(tFrac32)0,(tFrac32)0}     /*!< Default value for GFLIB_CONTROLLER_PI_P_T_F32. */

  /************************************************************************/
  /*!
  @struct GFLIB_CONTROLLER_PI_P_T_F32 "\GFLIB_ControllerPIp.h"

  @brief  Structure containing parameters and states of the parallel form PI controller.
  *//**********************************************************************/
  /** @remarks Implements DGFLIB00302 */
  typedef struct{
    tFrac32 f32PropGain;        /*!< Proportional Gain, fractional format normalized to fit into (-2\f$^{31}\f$, 2\f$^{31}\f$-1). */
    tFrac32 f32IntegGain;       /*!< Integral Gain, fractional format normalized to fit into  (-2\f$^{31}\f$, 2\f$^{31}\f$-1). */
    tS16 s16PropGainShift;      /*!< Proportional Gain Shift, integer format [-31, 31]. */
    tS16 s16IntegGainShift;     /*!< Integral Gain Shift, integer format [-31, 31]. */
    tFrac32 f32IntegPartK_1;    /*!< State variable integral part at step k-1. */
    tFrac32 f32InK_1;           /*!< State variable input error at step k-1. */
  }GFLIB_CONTROLLER_PI_P_T_F32;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac32 GFLIB_ControllerPIp_F32(tFrac32 f32InErr,GFLIB_CONTROLLER_PI_P_T_F32 * const pParam);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
  /*
  * @violates @ref GFLIB_ControllerPIp_h_REF_5 MISRA 2004 Required Rule 5.1, Identifier exceeds 31
  * characters.
  * @violates @ref GFLIB_ControllerPIp_h_REF_6 MISRA 2004 Required Rule 1.4, Identifier clash.
  */
  #define GFLIB_CONTROLLER_PI_P_DEFAULT_F16 {(tFrac16)0,(tFrac16)0,(tS16)0,(tS16)0,(tFrac32)0,(tFrac16)0}     /*!< Default value for GFLIB_CONTROLLER_PI_P_T_F16. */

  /************************************************************************/
  /*!
  @struct GFLIB_CONTROLLER_PI_P_T_F16 "\GFLIB_ControllerPIp.h"

  @brief  Structure containing parameters and states of the parallel form PI controller.
  *//**********************************************************************/
  /** @remarks Implements DGFLIB00302 */
  typedef struct{
    tFrac16 f16PropGain;        /*!< Proportional Gain, fractional format normalized to fit into (-2\f$^{15}\f$, 2\f$^{15}\f$-1). */
    tFrac16 f16IntegGain;       /*!< Integral Gain, fractional format normalized to fit into  (-2\f$^{15}\f$, 2\f$^{15}\f$-1). */
    tS16 s16PropGainShift;      /*!< Proportional Gain Shift, integer format [-15, 15]. */
    tS16 s16IntegGainShift;     /*!< Integral Gain Shift, integer format [-15, 15]. */
    tFrac32 f32IntegPartK_1;    /*!< State variable integral part at step k-1. */
    tFrac16 f16InK_1;           /*!< State variable input error at step k-1. */
  }GFLIB_CONTROLLER_PI_P_T_F16;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac16 GFLIB_ControllerPIp_F16(tFrac16 f16InErr,GFLIB_CONTROLLER_PI_P_T_F16 * const pParam);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  /*
  * @violates @ref GFLIB_ControllerPIp_h_REF_5 MISRA 2004 Required Rule 5.1, Identifier exceeds 31
  * characters.
  * @violates @ref GFLIB_ControllerPIp_h_REF_6 MISRA 2004 Required Rule 1.4, Identifier clash.
  */
  #define GFLIB_CONTROLLER_PI_P_DEFAULT_FLT {(tFloat)0,(tFloat)0,(tFloat)0,(tFloat)0}     /*!< Default value for GFLIB_CONTROLLER_PI_P_T_FLT. */

  /************************************************************************/
  /*!
  @struct GFLIB_CONTROLLER_PI_P_T_FLT "\GFLIB_ControllerPIp.h"

  @brief  Structure containing parameters and states of the parallel form PI controller.
  *//**********************************************************************/
  /** @remarks Implements DGFLIB00302 */
  typedef struct{
    tFloat fltPropGain;     /*!< Proportional Gain, single precision floating point format. */
    tFloat fltIntegGain;    /*!< Integral Gain, single precision floating point format. */
    tFloat fltIntegPartK_1; /*!< State variable integral part at step k-1, single precision floating point format. */
    tFloat fltInK_1;        /*!< State variable input error at step k-1, single precision floating point format. */
  }GFLIB_CONTROLLER_PI_P_T_FLT;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFloat GFLIB_ControllerPIp_FLT(tFloat fltInErr,GFLIB_CONTROLLER_PI_P_T_FLT * const pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_CONTROLLERPIP_H */
