/******************************************************************************/
/* File   : Adc.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "Adc.hpp"
#include "infAdc_Imp.hpp"

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

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, ADC_CODE) module_Adc::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, ADC_CONFIG_DATA, ADC_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         lptrCfg = lptrCfgModule;
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
#if(STD_ON == Adc_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, ADC_CODE) module_Adc::DeInitFunction(
   void
){
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
            TRUE // No ongoing conversions
      ){
#if(STD_ON == Adc_InitCheck)
         IsInitDone = E_NOT_OK;
#endif
      }
      else{
#if(STD_ON == Adc_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  ADC_E_BUSY
         );
#endif
      }
#if(STD_ON == Adc_InitCheck)
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, ADC_CODE) module_Adc::MainFunction(
   void
){
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == Adc_InitCheck)
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, ADC_CODE) module_Adc::SetupResultBuffer(
   void
// Adc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
         if(
            TRUE
            //TBD: DataBufferPtr is NULL_PTR
         ){
            if(
               TRUE
               // || at least one group is in idle
            ){
            }
            else{
#if(STD_ON == Adc_DevErrorDetect)
               Det_ReportError(
                     0 //TBD: IdModule
                  ,  0 //TBD: IdInstance
                  ,  0 //TBD: IdApi
                  ,  ADC_E_BUSY
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
               ,  ADC_E_PARAM_POINTER
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
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, ADC_CODE) module_Adc::StartGroupConversion(
   Adc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
         if(
               eSourceTrigger_EventSoftware
            == lpstChannelGroup->SourceTrigger
         ){
            if(
                  NULL_PTR
               != lpstChannelGroup->BufferResults.ptrListResultsGroupConversion
            ){
               if(
                     eStatusGroup_Busy
                  != lpstChannelGroup->BufferResults.StatusGroup
                  // || at least one group is in idle
                  // || conversion request for the group is not already in queue
               ){
               }
               else{
#if(STD_ON == Adc_DevErrorDetect)
                  Det_ReportError(
                        0 //TBD: IdModule
                     ,  0 //TBD: IdInstance
                     ,  0 //TBD: IdApi
                     ,  ADC_E_BUSY
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
                  ,  ADC_E_UNINIT_BUFFER
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
               ,  ADC_E_WRONG_SRC_TRIGG
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
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, ADC_CODE) module_Adc::StopGroupConversion(
   Adc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
         if(
               eSourceTrigger_EventSoftware
            == lpstChannelGroup->SourceTrigger
         ){
            if(
                  eStatusGroup_Idle
               != lpstChannelGroup->BufferResults.StatusGroup
            ){
            }
            else{
#if(STD_ON == Adc_DevErrorDetect)
               Det_ReportError(
                     0 //TBD: IdModule
                  ,  0 //TBD: IdInstance
                  ,  0 //TBD: IdApi
                  ,  ADC_E_IDLE
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
               ,  ADC_E_WRONG_SRC_TRIGG
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
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, ADC_CODE) module_Adc::ReadGroup(
   Adc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
         if(
               eStatusGroup_Idle
            != lpstChannelGroup->BufferResults.StatusGroup
         ){
            // Adc_TypeBufferResults
         }
         else{
#if(STD_ON == Adc_DevErrorDetect)
            Det_ReportError(
                  0 //TBD: IdModule
               ,  0 //TBD: IdInstance
               ,  0 //TBD: IdApi
               ,  ADC_E_IDLE
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
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, ADC_CODE) module_Adc::EnableHardwareTrigger(
   Adc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
         if(
               eSourceTrigger_EventSoftware
            == lpstChannelGroup->SourceTrigger
         ){
            if(
                  eModeConversion_OneShot
               == lpstChannelGroup->ModeConversion
            ){
               if(
                     NULL_PTR
                  != lpstChannelGroup->BufferResults.ptrListResultsGroupConversion
               ){
                  if(
                     TRUE
                     //    in the state idle !?!
                     // || Trigger already enabled
                     // || Maximum number of hardware triggers already enabled
                  ){
                  }
                  else{
#if(STD_ON == Adc_DevErrorDetect)
                     Det_ReportError(
                           0 //TBD: IdModule
                        ,  0 //TBD: IdInstance
                        ,  0 //TBD: IdApi
                        ,  ADC_E_BUSY
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
                     ,  ADC_E_UNINIT_BUFFER
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
                  ,  ADC_E_WRONG_MODE_CONV
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
               ,  ADC_E_WRONG_SRC_TRIGG
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
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, ADC_CODE) module_Adc::DisableHardwareTrigger(
   Adc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
         if(
               eSourceTrigger_EventSoftware
            == lpstChannelGroup->SourceTrigger
         ){
            if(
                  eModeConversion_OneShot
               == lpstChannelGroup->ModeConversion
            ){
               if(
                  TRUE
                  // Trigger already not enabled
               ){
               }
               else{
#if(STD_ON == Adc_DevErrorDetect)
                  Det_ReportError(
                        0 //TBD: IdModule
                     ,  0 //TBD: IdInstance
                     ,  0 //TBD: IdApi
                     ,  ADC_E_IDLE
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
                  ,  ADC_E_WRONG_MODE_CONV
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
               ,  ADC_E_WRONG_SRC_TRIGG
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
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, ADC_CODE) module_Adc::EnableGroupNotification(
   void
// Adc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
         //TBD: ADC_E_NOTIF_CAPABILITY, notification function pointer is NULL_PTR
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
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, ADC_CODE) module_Adc::DisableGroupNotification(
   void
// Adc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
         //TBD: ADC_E_NOTIF_CAPABILITY, notification function pointer is NULL_PTR
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
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, ADC_CODE) module_Adc::GetGroupStatus(
   void
){
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
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
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, ADC_CODE) module_Adc::GetStreamLastPointer(
   Adc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
         if(
               eStatusGroup_Idle
            != lpstChannelGroup->BufferResults.StatusGroup
         ){
            // Adc_TypeBufferResults
         }
         else{
#if(STD_ON == Adc_DevErrorDetect)
            Det_ReportError(
                  0 //TBD: IdModule
               ,  0 //TBD: IdInstance
               ,  0 //TBD: IdApi
               ,  ADC_E_IDLE
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
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
}

#if(STD_ON == Adc_SupportStatePowerLow)
//TBD: to be moved to additional class?
typedef enum{
      eStatePower_Full = 0
   ,  eStatePower_Maximum
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

FUNC(void, ADC_CODE) module_Adc::PreparePowerState(
   Adc_TypeStatePower lstStatePowerTargetRequested
){
   if(
         eStatePower_Maximum
      >  lstStatePowerTargetRequested
   ){
      if(
            E_NOT_OK
         == StateRequestActive
      ){
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
            ,  ADC_E_NOT_POSSIBLE_TRANSITION
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
         ,  ADC_E_NOT_SUPPORTED_STATE_POWER
      );
#endif
   }
}

FUNC(void, ADC_CODE) module_Adc::SetPowerState(
   void
// Adc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
         TRUE
         // check ADC_E_NOT_PREPARED_PERIPHERAL
      ){
         if(
            TRUE
            // All channel/group are in Idle status
         ){
            if(
                  E_OK
               == StateRequestActive
            ){
               Adc_gstContextLowPower.StatePowerCurrent = Adc_gstContextLowPower.StatePowerTarget;
               StateRequestActive = E_NOT_OK;
            }
            else{
#if(STD_ON == Adc_DevErrorDetect)
               Det_ReportError(
                     0 //TBD: IdModule
                  ,  0 //TBD: IdInstance
                  ,  0 //TBD: IdApi
                  ,  ADC_E_NOT_POSSIBLE_TRANSITION
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
               ,  ADC_E_NOT_DISENGAGED
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
            ,  ADC_E_NOT_PREPARED_PERIPHERAL
         );
#endif
      }
#if(STD_ON == Adc_InitCheck)
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(Adc_TypeStatePower, ADC_CODE) module_Adc::GetCurrentPowerState(
   void
// Adc_TypeChannelGroup* lpstChannelGroup
){
   Adc_TypeStatePower lReturnValue = eStatePower_Maximum;
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
   lReturnValue = Adc_gstContextLowPower.StatePowerCurrent;
#if(STD_ON == Adc_InitCheck)
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
   return lReturnValue;
}

FUNC(Adc_TypeStatePower, ADC_CODE) module_Adc::GetTargetPowerState(
   void
// Adc_TypeChannelGroup* lpstChannelGroup
){
   Adc_TypeStatePower lReturnValue = eStatePower_Maximum;
#if(STD_ON == Adc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
   lReturnValue = Adc_gstContextLowPower.StatePowerTarget;
#if(STD_ON == Adc_InitCheck)
   }
   else{
#if(STD_ON == Adc_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ADC_E_UNINIT
      );
#endif
   }
#endif
   return lReturnValue;
}
#endif

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

