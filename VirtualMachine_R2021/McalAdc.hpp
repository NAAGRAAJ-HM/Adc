#pragma once
/******************************************************************************/
/* File   : McalAdc.hpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "ConstMcalAdc.hpp"
#include "CfgMcalAdc.hpp"
#include "McalAdc_core.hpp"
#include "infMcalAdc_Exp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_McalAdc:
      INTERFACES_EXPORTED_ADC
      public abstract_module
   ,  public class_McalAdc_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
      const ConstMcalAdc_Type* lptrConst = (ConstMcalAdc_Type*)NULL_PTR;

   public:
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
      FUNC(void, ADC_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, ADC_CONST,       ADC_APPL_CONST) lptrConstModule
         ,  CONSTP2CONST(CfgModule_TypeAbstract,   ADC_CONFIG_DATA, ADC_APPL_CONST) lptrCfgModule
      );
      FUNC(void, ADC_CODE) DeInitFunction (void);
      FUNC(void, ADC_CODE) MainFunction   (void);
      ADC_CORE_FUNCTIONALITIES
#if(STD_ON == McalAdc_SupportStatePowerLow)
      FUNC(void,               ADC_CODE) PreparePowerState    (McalAdc_TypeStatePower lstStatePowerTargetRequested);
      FUNC(void,               ADC_CODE) SetPowerState        (void);
      FUNC(McalAdc_TypeStatePower, ADC_CODE) GetCurrentPowerState (void);
      FUNC(McalAdc_TypeStatePower, ADC_CODE) GetTargetPowerState  (void);
#endif
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
extern VAR(module_McalAdc, ADC_VAR) McalAdc;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

