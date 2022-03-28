/******************************************************************************/
/* File   : Adc.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.hpp"
#include "CfgAdc.hpp"
#include "infAdc_EcuM.hpp"
#include "infAdc_Dcm.hpp"
#include "infAdc_SchM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define ADC_AR_RELEASE_MAJOR_VERSION                                           4
#define ADC_AR_RELEASE_MINOR_VERSION                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(ADC_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
   #error "Incompatible ADC_AR_RELEASE_MAJOR_VERSION!"
#endif

#if(ADC_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)
   #error "Incompatible ADC_AR_RELEASE_MINOR_VERSION!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_Adc:
      public abstract_module
{
   public:
      FUNC(void, ADC_CODE) InitFunction   (void);
      FUNC(void, ADC_CODE) DeInitFunction (void);
      FUNC(void, ADC_CODE) GetVersionInfo (void);
      FUNC(void, ADC_CODE) MainFunction   (void);

   private:
      CONST(Std_TypeVersionInfo, ADC_CONST) VersionInfo = {
            0x0000
         ,  0xFFFF
         ,  0x01
         ,  '0'
         ,  '1'
         ,  '0'
      };
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
VAR(module_Adc, ADC_VAR) Adc;
CONSTP2VAR(infEcuMClient, ADC_VAR, ADC_CONST) gptrinfEcuMClient_Adc = &Adc;
CONSTP2VAR(infDcmClient,  ADC_VAR, ADC_CONST) gptrinfDcmClient_Adc  = &Adc;
CONSTP2VAR(infSchMClient, ADC_VAR, ADC_CONST) gptrinfSchMClient_Adc = &Adc;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, ADC_CODE) module_Adc::InitFunction(void){
   Adc.IsInitDone = E_OK;
}

FUNC(void, ADC_CODE) module_Adc::DeInitFunction(void){
   Adc.IsInitDone = E_NOT_OK;
}

FUNC(void, ADC_CODE) module_Adc::GetVersionInfo(void){
#if(STD_ON == Adc_DevErrorDetect)
//TBD: API parameter check
   Det_ReportError(
   );
#endif
}

FUNC(void, ADC_CODE) module_Adc::MainFunction(void){
}

class class_Adc_Unused{
   public:
      FUNC(void, ADC_CODE) SetupResultBuffer        (void);
      FUNC(void, ADC_CODE) StartGroupConversion     (void);
      FUNC(void, ADC_CODE) StopGroupConversion      (void);
      FUNC(void, ADC_CODE) ReadGroup                (void);
      FUNC(void, ADC_CODE) EnableHardwareTrigger    (void);
      FUNC(void, ADC_CODE) DisableHardwareTrigger   (void);
      FUNC(void, ADC_CODE) EnableGroupNotification  (void);
      FUNC(void, ADC_CODE) DisableGroupNotification (void);
      FUNC(void, ADC_CODE) GetGroupStatus           (void);
      FUNC(void, ADC_CODE) GetStreamLastPointer     (void);
};

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

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

