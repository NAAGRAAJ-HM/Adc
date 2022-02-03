/*****************************************************/
/* File   : Adc.cpp                                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "Adc.h"

#include "Adc_EcuM.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
class_Adc_EcuM Adc_EcuM;
class_EcuM_Client *EcuM_Client_ptr_Adc = &Adc_EcuM;
class_Adc Adc;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, ADC_CODE) class_Adc_EcuM::InitFunction(void){
}

FUNC(void, ADC_CODE) class_Adc_EcuM::DeInitFunction(void){
}

FUNC(void, ADC_CODE) class_Adc::MainFunction(void){
}

FUNC(void, ADC_CODE) class_Adc::SetupResultBuffer(void){
}

FUNC(void, ADC_CODE) class_Adc::StartGroupConversion(void){
}

FUNC(void, ADC_CODE) class_Adc::StopGroupConversion(void){
}

FUNC(void, ADC_CODE) class_Adc::ReadGroup(void){
}

FUNC(void, ADC_CODE) class_Adc::EnableHardwareTrigger(void){
}

FUNC(void, ADC_CODE) class_Adc::DisableHardwareTrigger(void){
}

FUNC(void, ADC_CODE) class_Adc::EnableGroupNotification(void){
}

FUNC(void, ADC_CODE) class_Adc::DisableGroupNotification(void){
}

FUNC(void, ADC_CODE) class_Adc::GetGroupStatus(void){
}

FUNC(void, ADC_CODE) class_Adc::GetStreamLastPointer(void){
}

FUNC(void, ADC_CODE) class_Adc::GetVersionInfo(void){
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

