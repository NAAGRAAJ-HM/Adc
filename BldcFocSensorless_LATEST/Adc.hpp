#pragma once
/******************************************************************************/
/* File   : Adc.hpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "ConstAdc.hpp"
#include "CfgAdc.hpp"
#include "Adc_core.hpp"
#include "infAdc_Exp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_Adc:
      INTERFACES_EXPORTED_ADC
      public abstract_module
   ,  public class_Adc_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
      const ConstAdc_Type* lptrConst = (ConstAdc_Type*)NULL_PTR;

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
#if(STD_ON == Adc_SupportStatePowerLow)
      FUNC(void,               ADC_CODE) PreparePowerState    (Adc_TypeStatePower lstStatePowerTargetRequested);
      FUNC(void,               ADC_CODE) SetPowerState        (void);
      FUNC(Adc_TypeStatePower, ADC_CODE) GetCurrentPowerState (void);
      FUNC(Adc_TypeStatePower, ADC_CODE) GetTargetPowerState  (void);
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
extern VAR(module_Adc, ADC_VAR) Adc;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

