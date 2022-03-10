/*****************************************************/
/* File   : Adc.cpp                                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "module.h"
#include "infAdc_EcuM.h"
#include "infAdc_SchM.h"
#include "Adc_Unused.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class module_Adc:
      public abstract_module
{
   public:
      FUNC(void, ADC_CODE) InitFunction   (void);
      FUNC(void, ADC_CODE) DeInitFunction (void);
      FUNC(void, ADC_CODE) GetVersionInfo (void);
      FUNC(void, ADC_CODE) MainFunction   (void);
};

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
module_Adc     Adc;
infEcuMClient* gptrinfEcuMClient_Adc = &Adc;
infDcmClient*  gptrinfDcmClient_Adc  = &Adc;
infSchMClient* gptrinfSchMClient_Adc = &Adc;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, ADC_CODE) module_Adc::InitFunction(void){
}

FUNC(void, ADC_CODE) module_Adc::DeInitFunction(void){
}

FUNC(void, ADC_CODE) module_Adc::GetVersionInfo(void){
}

FUNC(void, ADC_CODE) module_Adc::MainFunction(void){
}

FUNC(void, ADC_CODE) class_Adc_Unused::SetupResultBuffer(void){
}

FUNC(void, ADC_CODE) class_Adc_Unused::StartGroupConversion(void){
}

FUNC(void, ADC_CODE) class_Adc_Unused::StopGroupConversion(void){
}

FUNC(void, ADC_CODE) class_Adc_Unused::ReadGroup(void){
}

FUNC(void, ADC_CODE) class_Adc_Unused::EnableHardwareTrigger(void){
}

FUNC(void, ADC_CODE) class_Adc_Unused::DisableHardwareTrigger(void){
}

FUNC(void, ADC_CODE) class_Adc_Unused::EnableGroupNotification(void){
}

FUNC(void, ADC_CODE) class_Adc_Unused::DisableGroupNotification(void){
}

FUNC(void, ADC_CODE) class_Adc_Unused::GetGroupStatus(void){
}

FUNC(void, ADC_CODE) class_Adc_Unused::GetStreamLastPointer(void){
}

FUNC(void, ADC_CODE) class_Adc_Unused::GetVersionInfo(void){
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

