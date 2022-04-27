/******************************************************************************/
/* File   : Adc.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "infAdc_EcuM.hpp"
#include "infAdc_Dcm.hpp"
#include "infAdc_SchM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define ADC_AR_RELEASE_VERSION_MAJOR                                           4
#define ADC_AR_RELEASE_VERSION_MINOR                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(ADC_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible ADC_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(ADC_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible ADC_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_Adc:
      public abstract_module
   ,  public class_Adc_Functionality
{
   public:
      module_Adc(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, ADC_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, ADC_CONFIG_DATA, ADC_APPL_CONST) lptrCfgModule
      );
      FUNC(void, ADC_CODE) DeInitFunction (void);
      FUNC(void, ADC_CODE) MainFunction   (void);
};

extern VAR(module_Adc, ADC_VAR) Adc;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, ADC_VAR, ADC_CONST) gptrinfEcuMClient_Adc = &Adc;
CONSTP2VAR(infDcmClient,  ADC_VAR, ADC_CONST) gptrinfDcmClient_Adc  = &Adc;
CONSTP2VAR(infSchMClient, ADC_VAR, ADC_CONST) gptrinfSchMClient_Adc = &Adc;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/
#include "CfgAdc.hpp"

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Adc, ADC_VAR) Adc(
   {
         ADC_AR_RELEASE_VERSION_MAJOR
      ,  ADC_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, ADC_CODE) module_Adc::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, ADC_CONFIG_DATA, ADC_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Adc_InitCheck)
   if(E_OK == GetStatusInit()){
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == Adc_DevErrorDetect)
         Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  0 //TBD: IdError
         );
#endif
      }
      else{
         if(STD_LOW){
// check lptrCfgModule for memory faults
            lptrCfg = lptrCfgModule;
         }
         else{
// use PBcfgCanIf as back-up configuration
            lptrCfg = &PBcfgAdc;
         }
      }
      SetStatusInit(E_OK);
#if(STD_ON == Adc_InitCheck)
   }
#endif
}

FUNC(void, ADC_CODE) module_Adc::DeInitFunction(void){
#if(STD_ON == Adc_InitCheck)
   if(E_OK != GetStatusInit()){
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      SetStatusInit(E_NOT_OK);
#if(STD_ON == Adc_InitCheck)
   }
#endif
}

FUNC(void, ADC_CODE) module_Adc::MainFunction(void){
#if(STD_ON == Adc_InitCheck)
   if(E_OK != GetStatusInit()){
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
#if(STD_ON == Adc_InitCheck)
   }
#endif
}

FUNC(void, ADC_CODE) class_Adc_Functionality::SetupResultBuffer(void){
}

FUNC(void, ADC_CODE) class_Adc_Functionality::StartGroupConversion(
   Adc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == Adc_InitCheck)
//TBD:    if(E_OK != GetStatusInit()){
/*
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
   else{
*/
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
         if(
            eSourceTrigger_EventSoftware == lpstChannelGroup->SourceTrigger
         ){
            //TBD: DET error check for ADC_E_BUFFER_UNINIT
         }
         else{
#if(STD_ON == Adc_DevErrorDetect)
            Det_ReportError(
                  0 //TBD: IdModule
               ,  0 //TBD: IdInstance
               ,  0 //TBD: IdApi
               ,  ADC_E_WRONG_TRIGG_SRC //hardware
            );
#endif
         }
      }
      else{
#if(STD_ON == Adc_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  ADC_E_PARAM_GROUP
         );
#endif
      }
#if(STD_ON == Adc_InitCheck)
//TBD:    }
#endif
}

FUNC(void, ADC_CODE) class_Adc_Functionality::StopGroupConversion(
   Adc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == Adc_InitCheck)
//TBD:    if(E_OK != GetStatusInit()){
/*
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
   else{
*/
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
         if(
            eSourceTrigger_EventSoftware == lpstChannelGroup->SourceTrigger
         ){
         }
         else{
#if(STD_ON == Adc_DevErrorDetect)
            Det_ReportError(
                  0 //TBD: IdModule
               ,  0 //TBD: IdInstance
               ,  0 //TBD: IdApi
               ,  ADC_E_WRONG_TRIGG_SRC //hardware
            );
#endif
         }
      }
      else{
#if(STD_ON == Adc_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  ADC_E_PARAM_GROUP
         );
#endif
      }
#if(STD_ON == Adc_InitCheck)
//TBD:    }
#endif
}

FUNC(void, ADC_CODE) class_Adc_Functionality::ReadGroup(void){
// Adc_TypeBufferResults

#if(STD_ON == Adc_InitCheck)
//TBD:    if(E_OK != GetStatusInit()){
/*
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
   else{
*/
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
      }
      else{
#if(STD_ON == Adc_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  ADC_E_PARAM_GROUP
         );
#endif
      }
#if(STD_ON == Adc_InitCheck)
//TBD:    }
#endif
}

FUNC(void, ADC_CODE) class_Adc_Functionality::EnableHardwareTrigger(void){
}

FUNC(void, ADC_CODE) class_Adc_Functionality::DisableHardwareTrigger(void){
}

FUNC(void, ADC_CODE) class_Adc_Functionality::EnableGroupNotification(void){
}

FUNC(void, ADC_CODE) class_Adc_Functionality::DisableGroupNotification(void){
}

FUNC(void, ADC_CODE) class_Adc_Functionality::GetGroupStatus(void){
#if(STD_ON == Adc_InitCheck)
//TBD:    if(E_OK != GetStatusInit()){
/*
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
   else{
*/
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
      }
      else{
#if(STD_ON == Adc_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  ADC_E_PARAM_GROUP
         );
#endif
      }
#if(STD_ON == Adc_InitCheck)
//TBD:    }
#endif
}

FUNC(void, ADC_CODE) class_Adc_Functionality::GetStreamLastPointer(void){
// Adc_TypeBufferResults
}

#if(STD_ON == Adc_SupportStatePowerLow)
//TBD: to be moved to additional class?
typedef enum{
      eStatePower_Full
   ,  eStatePower_
}Adc_TypeStatePower;

typedef struct{
   Adc_TypeStatePower StatePowerCurrent;
   Adc_TypeStatePower StatePowerTarget;
   Std_TypeReturn     StateRequestActive;
}Adc_TypeContextLowPower;

Adc_TypeContextLowPower Adc_gstContextLowPower = {
      eStatePower_Full // TBD: InitFunction, takecare of Adc_SupportStatePowerLow
   ,  eStatePower_Full
   ,  E_NOT_OK
};

FUNC(void, ADC_CODE) class_Adc_Functionality::PreparePowerState(
   Adc_TypeStatePower lstStatePowerTargetRequested
){
   if(E_NOT_OK == StateRequestActive){
      Adc_gstContextLowPower.StatePowerTarget = lstStatePowerTargetRequested;
      StateRequestActive = E_OK;
#if(STD_OFF == Adc_StatePowerModeTransitionAsynch)
      SetPowerState();
      // TBD: handle in MainFunction, take care of Adc_SupportStatePowerLow, Adc_StatePowerModeTransitionAsynch
#endif
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  0 //TBD: IdError
      );
#endif
   }
}

FUNC(void, ADC_CODE) class_Adc_Functionality::SetPowerState(void){
   if(E_OK == StateRequestActive){
      Adc_gstContextLowPower.StatePowerCurrent = Adc_gstContextLowPower.StatePowerTarget;
      StateRequestActive = E_NOT_OK;
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  0 //TBD: IdError
      );
#endif
   }
}

FUNC(Adc_TypeStatePower, ADC_CODE) class_Adc_Functionality::GetCurrentPowerState(void){
   return Adc_gstContextLowPower.StatePowerCurrent;
}

FUNC(Adc_TypeStatePower, ADC_CODE) class_Adc_Functionality::GetTargetPowerState(void){
   return Adc_gstContextLowPower.StatePowerTarget;
}
#endif

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

