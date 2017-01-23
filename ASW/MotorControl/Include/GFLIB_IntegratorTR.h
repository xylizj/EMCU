/******************************************************************************
*
*   (c) Copyright 2015 Freescale Semiconductor, Inc.
*   All Rights Reserved.
*
******************************************************************************/
/*!
*
* @file       GFLIB_IntegratorTR.h
*
* @version    1.0.7.0
*
* @date       Mar-10-2014
*
* @brief      Header file for GFLIB_IntegratorTR function
*
******************************************************************************/
#ifndef GFLIB_INTEGRATORTR_H
#define GFLIB_INTEGRATORTR_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section GFLIB_IntegratorTR_h_REF_1
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of disallowed macro
* definition.
*
* @section GFLIB_IntegratorTR_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires the function-like macro
* definition.
*
* @section GFLIB_IntegratorTR_h_REF_3
* Violates MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter in definition of macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of unparenthesized
* macro parameters.
*
* @section GFLIB_IntegratorTR_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of '#/##' operators.
*/
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
  /*
  * @violates @ref GFLIB_IntegratorTR_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
  * for macro.
  * @violates @ref GFLIB_IntegratorTR_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
  * defined.
  * @violates @ref GFLIB_IntegratorTR_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  */
  #define GFLIB_IntegratorTR(...)     macro_dispatcher(GFLIB_IntegratorTR, __VA_ARGS__)(__VA_ARGS__)     /*!< The function calculates a discrete implementation of the integrator (sum), discretized using a trapezoidal (Bilinear) transformation. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /*
    * @violates @ref GFLIB_IntegratorTR_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    */
    #define GFLIB_INTEGRATOR_TR_T                       GFLIB_INTEGRATOR_TR_T_F32                       /*!< Definition of GFLIB_INTEGRATOR_TR_T as alias for GFLIB_INTEGRATOR_TR_T_F32 datatype in case the 32-bit fractional implementation is selected. */
    /*
    * @violates @ref GFLIB_IntegratorTR_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    */
    #define GFLIB_INTEGRATOR_TR_DEFAULT                 GFLIB_INTEGRATOR_TR_DEFAULT_F32                 /*!< Definition of GFLIB_INTEGRATOR_TR_DEFAULT as alias for GFLIB_INTEGRATOR_TR_DEFAULT_F32 default value in case the 32-bit fractional implementation is selected. */
    /*
    * @violates @ref GFLIB_IntegratorTR_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    * @violates @ref GFLIB_IntegratorTR_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
    * defined.
    * @violates @ref GFLIB_IntegratorTR_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized
    * macro parameter in definition of macro.
    */
    /** @remarks Implements DGFLIB00261 */
    #define GFLIB_IntegratorTR_Dsptchr_2(In,pParam)     GFLIB_IntegratorTR_Dsptchr_3(In,pParam,F32)     /*!< Function dispatcher for GFLIB_IntegratorTR_Dsptchr_2, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /*
    * @violates @ref GFLIB_IntegratorTR_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    */
    #define GFLIB_INTEGRATOR_TR_T                       GFLIB_INTEGRATOR_TR_T_F16                       /*!< Definition of GFLIB_INTEGRATOR_TR_T as alias for GFLIB_INTEGRATOR_TR_T_F16 datatype in case the 16-bit fractional implementation is selected. */
    /*
    * @violates @ref GFLIB_IntegratorTR_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    */
    #define GFLIB_INTEGRATOR_TR_DEFAULT                 GFLIB_INTEGRATOR_TR_DEFAULT_F16                 /*!< Definition of GFLIB_INTEGRATOR_TR_DEFAULT as alias for GFLIB_INTEGRATOR_TR_DEFAULT_F16 default value in case the 16-bit fractional implementation is selected. */
    /*
    * @violates @ref GFLIB_IntegratorTR_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    * @violates @ref GFLIB_IntegratorTR_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
    * defined.
    * @violates @ref GFLIB_IntegratorTR_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized
    * macro parameter in definition of macro.
    */
    /** @remarks Implements DGFLIB00261 */
    #define GFLIB_IntegratorTR_Dsptchr_2(In,pParam)     GFLIB_IntegratorTR_Dsptchr_3(In,pParam,F16)     /*!< Function dispatcher for GFLIB_IntegratorTR_Dsptchr_2, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /*
    * @violates @ref GFLIB_IntegratorTR_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    */
    #define GFLIB_INTEGRATOR_TR_T                       GFLIB_INTEGRATOR_TR_T_FLT                       /*!< Definition of GFLIB_INTEGRATOR_TR_T as alias for GFLIB_INTEGRATOR_TR_T_FLT datatype in case the single precision floating point implementation is selected. */
    /*
    * @violates @ref GFLIB_IntegratorTR_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    */
    #define GFLIB_INTEGRATOR_TR_DEFAULT                 GFLIB_INTEGRATOR_TR_DEFAULT_FLT                 /*!< Definition of GFLIB_INTEGRATOR_TR_DEFAULT as alias for GFLIB_INTEGRATOR_TR_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /*
    * @violates @ref GFLIB_IntegratorTR_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    * @violates @ref GFLIB_IntegratorTR_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
    * defined.
    * @violates @ref GFLIB_IntegratorTR_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized
    * macro parameter in definition of macro.
    */
    /** @remarks Implements DGFLIB00261 */
    #define GFLIB_IntegratorTR_Dsptchr_2(In,pParam)     GFLIB_IntegratorTR_Dsptchr_3(In,pParam,FLT)     /*!< Function dispatcher for GFLIB_IntegratorTR_Dsptchr_2, do not modify!!! */
  #endif

  /*
  * @violates @ref GFLIB_IntegratorTR_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
  * for macro.
  * @violates @ref GFLIB_IntegratorTR_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
  * defined.
  * @violates @ref GFLIB_IntegratorTR_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  */
  #define GFLIB_IntegratorTR_Dsptchr_3(In,pParam,Impl)    GFLIB_IntegratorTR_Dsptchr_(In,pParam,Impl)     /*!< Function dispatcher for GFLIB_IntegratorTR_Dsptchr_3, do not modify!!! */

  /*
  * @violates @ref GFLIB_IntegratorTR_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition
  * for macro.
  * @violates @ref GFLIB_IntegratorTR_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
  * defined.
  * @violates @ref GFLIB_IntegratorTR_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  * @violates @ref GFLIB_IntegratorTR_h_REF_4 MISRA 2004 Advisory Rule 19.13, #/##' operator used in
  * macro.
  */
  /** @remarks Implements DGFLIB00263 */
  #define GFLIB_IntegratorTR_Dsptchr_(In,pParam,Impl)     GFLIB_IntegratorTR_##Impl(In,pParam)            /*!< Function dispatcher for GFLIB_IntegratorTR_Dsptchr_, do not modify!!! */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  #define GFLIB_INTEGRATOR_TR_DEFAULT_F32 {(tFrac32)0,(tFrac32)0,(tFrac32)0,(tU16)0}     /*!< Default value for GFLIB_INTEGRATOR_TR_T_F32. */

  /************************************************************************/
  /*!
  @struct GFLIB_INTEGRATOR_TR_T_F32 "\GFLIB_IntegratorTR.h"

  @brief  Structure containing integrator parameters and coefficients.
  *//**********************************************************************/
  /** @remarks Implements DGFLIB00264 */
  typedef struct{
    tFrac32 f32State;       /*!< Integrator state value. */
    tFrac32 f32InK1;        /*!< Input value in step k-1. */
    tFrac32 f32C1;          /*!< Integrator coefficient = (E\f$_{MAX}\f$/T\f$_{s}\f$)(U\f$_{MAX}\f$*2)*(2\f$^{-u16NShift}\f$). */
    tU16    u16NShift;      /*!< Scaling factor for the integrator coefficient f32C1, integer format [0, 31]. */
  }GFLIB_INTEGRATOR_TR_T_F32;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac32 GFLIB_IntegratorTR_F32(tFrac32 f32In, GFLIB_INTEGRATOR_TR_T_F32 * const pParam);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
  #define GFLIB_INTEGRATOR_TR_DEFAULT_F16 {(tFrac32)0,(tFrac16)0,(tFrac16)0,(tU16)0}     /*!< Default value for GFLIB_INTEGRATOR_TR_T_F16. */

  /************************************************************************/
  /*!
  @struct GFLIB_INTEGRATOR_TR_T_F16 "\GFLIB_IntegratorTR.h"

  @brief  Structure containing integrator parameters and coefficients.
  *//**********************************************************************/
  /** @remarks Implements DGFLIB00264 */
  typedef struct{
    tFrac32 f32State;       /*!< Integrator state value. */
    tFrac16 f16InK1;        /*!< Input value in step k-1. */
    tFrac16 f16C1;          /*!< Integrator coefficient = (E\f$_{MAX}\f$/T\f$_{s}\f$)(U\f$_{MAX}\f$*2)*(2\f$^{-u16NShift}\f$). */
    tU16    u16NShift;      /*!< Scaling factor for the integrator coefficient f16C1, integer format [0, 15]. */
  }GFLIB_INTEGRATOR_TR_T_F16;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac16 GFLIB_IntegratorTR_F16(tFrac16 f16In, GFLIB_INTEGRATOR_TR_T_F16 * const pParam);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define GFLIB_INTEGRATOR_TR_DEFAULT_FLT {(tFloat)0,(tFloat)0,(tFloat)0}     /*!< Default value for GFLIB_INTEGRATOR_TR_T_FLT. */

  /************************************************************************/
  /*!
  @struct GFLIB_INTEGRATOR_TR_T_FLT "\GFLIB_IntegratorTR.h"

  @brief  Structure containing integrator parameters and coefficients.
  *//**********************************************************************/
  /** @remarks Implements DGFLIB00264 */
  typedef struct{
    tFloat fltState;     /*!< Integrator state value, single precision floating point format. */
    tFloat fltInK1;      /*!< Input value in step k-1, single precision floating point format. */
    tFloat fltC1;        /*!< Integrator coefficient, single precision floating point format. */
  }GFLIB_INTEGRATOR_TR_T_FLT;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFloat GFLIB_IntegratorTR_FLT(tFloat fltIn, GFLIB_INTEGRATOR_TR_T_FLT * const pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_INTEGRATORTR_H */
