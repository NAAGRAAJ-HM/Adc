/******************************************************************************/
/* File   : McalAdc.cpp                                                       */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/NagarajaHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "McalAdc.hpp"
#include "infMcalAdc_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define MCALADC_AR_RELEASE_VERSION_MAJOR                                       4
#define MCALADC_AR_RELEASE_VERSION_MINOR                                       3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(MCALADC_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible MCALADC_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(MCALADC_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible MCALADC_AR_RELEASE_VERSION_MINOR!"
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
VAR(module_McalAdc, MCALADC_VAR) McalAdc;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, MCALADC_CODE) module_McalAdc::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, MCALADC_CONST,       MCALADC_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   MCALADC_CONFIG_DATA, MCALADC_APPL_CONST) lptrCfgModule
){
#if(STD_ON == McalAdc_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = (const ConstMcalAdc_Type*)lptrConstModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == McalAdc_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == McalAdc_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALADC_CODE) module_McalAdc::DeInitFunction(
   void
){
#if(STD_ON == McalAdc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
            TRUE // No ongoing conversions
      ){
#if(STD_ON == McalAdc_InitCheck)
         IsInitDone = E_NOT_OK;
#endif
      }
      else{
#if(STD_ON == McalAdc_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  MCALADC_E_BUSY
         );
#endif
      }
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALADC_CODE) module_McalAdc::MainFunction(
   void
){
#if(STD_ON == McalAdc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALADC_CODE) module_McalAdc::SetupResultBuffer(
   void
// McalAdc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == McalAdc_InitCheck)
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
#if(STD_ON == McalAdc_DevErrorDetect)
               ServiceDet_ReportError(
                     0 //TBD: IdModule
                  ,  0 //TBD: IdInstance
                  ,  0 //TBD: IdApi
                  ,  MCALADC_E_BUSY
               );
#endif
            }
         }
         else{
#if(STD_ON == McalAdc_DevErrorDetect)
            ServiceDet_ReportError(
                  0 //TBD: IdModule
               ,  0 //TBD: IdInstance
               ,  0 //TBD: IdApi
               ,  MCALADC_E_PARAM_POINTER
            );
#endif
         }
      }
      else{
#if(STD_ON == McalAdc_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  MCALADC_E_PARAM_GROUP
         );
#endif
      }
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALADC_CODE) module_McalAdc::StartGroupConversion(
   McalAdc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == McalAdc_InitCheck)
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
#if(STD_ON == McalAdc_DevErrorDetect)
                  ServiceDet_ReportError(
                        0 //TBD: IdModule
                     ,  0 //TBD: IdInstance
                     ,  0 //TBD: IdApi
                     ,  MCALADC_E_BUSY
                  );
#endif
               }
            }
            else{
#if(STD_ON == McalAdc_DevErrorDetect)
               ServiceDet_ReportError(
                     0 //TBD: IdModule
                  ,  0 //TBD: IdInstance
                  ,  0 //TBD: IdApi
                  ,  MCALADC_E_UNINIT_BUFFER
               );
#endif
            }
         }
         else{
#if(STD_ON == McalAdc_DevErrorDetect)
            ServiceDet_ReportError(
                  0 //TBD: IdModule
               ,  0 //TBD: IdInstance
               ,  0 //TBD: IdApi
               ,  MCALADC_E_WRONG_SRC_TRIGG
            );
#endif
         }
      }
      else{
#if(STD_ON == McalAdc_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  MCALADC_E_PARAM_GROUP
         );
#endif
      }
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALADC_CODE) module_McalAdc::StopGroupConversion(
   McalAdc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == McalAdc_InitCheck)
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
#if(STD_ON == McalAdc_DevErrorDetect)
               ServiceDet_ReportError(
                     0 //TBD: IdModule
                  ,  0 //TBD: IdInstance
                  ,  0 //TBD: IdApi
                  ,  MCALADC_E_IDLE
               );
#endif
            }
         }
         else{
#if(STD_ON == McalAdc_DevErrorDetect)
            ServiceDet_ReportError(
                  0 //TBD: IdModule
               ,  0 //TBD: IdInstance
               ,  0 //TBD: IdApi
               ,  MCALADC_E_WRONG_SRC_TRIGG
            );
#endif
         }
      }
      else{
#if(STD_ON == McalAdc_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  MCALADC_E_PARAM_GROUP
         );
#endif
      }
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALADC_CODE) module_McalAdc::ReadGroup(
   McalAdc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == McalAdc_InitCheck)
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
            // McalAdc_TypeBufferResults
         }
         else{
#if(STD_ON == McalAdc_DevErrorDetect)
            ServiceDet_ReportError(
                  0 //TBD: IdModule
               ,  0 //TBD: IdInstance
               ,  0 //TBD: IdApi
               ,  MCALADC_E_IDLE
            );
#endif
         }
      }
      else{
#if(STD_ON == McalAdc_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  MCALADC_E_PARAM_GROUP
         );
#endif
      }
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALADC_CODE) module_McalAdc::EnableHardwareTrigger(
   McalAdc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == McalAdc_InitCheck)
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
#if(STD_ON == McalAdc_DevErrorDetect)
                     ServiceDet_ReportError(
                           0 //TBD: IdModule
                        ,  0 //TBD: IdInstance
                        ,  0 //TBD: IdApi
                        ,  MCALADC_E_BUSY
                     );
#endif
                  }
               }
               else{
#if(STD_ON == McalAdc_DevErrorDetect)
                  ServiceDet_ReportError(
                        0 //TBD: IdModule
                     ,  0 //TBD: IdInstance
                     ,  0 //TBD: IdApi
                     ,  MCALADC_E_UNINIT_BUFFER
                  );
#endif
               }
            }
            else{
#if(STD_ON == McalAdc_DevErrorDetect)
               ServiceDet_ReportError(
                     0 //TBD: IdModule
                  ,  0 //TBD: IdInstance
                  ,  0 //TBD: IdApi
                  ,  MCALADC_E_WRONG_MODE_CONV
               );
#endif
            }
         }
         else{
#if(STD_ON == McalAdc_DevErrorDetect)
            ServiceDet_ReportError(
                  0 //TBD: IdModule
               ,  0 //TBD: IdInstance
               ,  0 //TBD: IdApi
               ,  MCALADC_E_WRONG_SRC_TRIGG
            );
#endif
         }
      }
      else{
#if(STD_ON == McalAdc_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  MCALADC_E_PARAM_GROUP
         );
#endif
      }
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALADC_CODE) module_McalAdc::DisableHardwareTrigger(
   McalAdc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == McalAdc_InitCheck)
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
#if(STD_ON == McalAdc_DevErrorDetect)
                  ServiceDet_ReportError(
                        0 //TBD: IdModule
                     ,  0 //TBD: IdInstance
                     ,  0 //TBD: IdApi
                     ,  MCALADC_E_IDLE
                  );
#endif
               }
            }
            else{
#if(STD_ON == McalAdc_DevErrorDetect)
               ServiceDet_ReportError(
                     0 //TBD: IdModule
                  ,  0 //TBD: IdInstance
                  ,  0 //TBD: IdApi
                  ,  MCALADC_E_WRONG_MODE_CONV
               );
#endif
            }
         }
         else{
#if(STD_ON == McalAdc_DevErrorDetect)
            ServiceDet_ReportError(
                  0 //TBD: IdModule
               ,  0 //TBD: IdInstance
               ,  0 //TBD: IdApi
               ,  MCALADC_E_WRONG_SRC_TRIGG
            );
#endif
         }
      }
      else{
#if(STD_ON == McalAdc_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  MCALADC_E_PARAM_GROUP
         );
#endif
      }
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALADC_CODE) module_McalAdc::EnableGroupNotification(
   void
// McalAdc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == McalAdc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
         //TBD: MCALADC_E_NOTIF_CAPABILITY, notification function pointer is NULL_PTR
      }
      else{
#if(STD_ON == McalAdc_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  MCALADC_E_PARAM_GROUP
         );
#endif
      }
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALADC_CODE) module_McalAdc::DisableGroupNotification(
   void
// McalAdc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == McalAdc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
         TRUE
         //TBD: group check lpstChannelGroup
      ){
         //TBD: MCALADC_E_NOTIF_CAPABILITY, notification function pointer is NULL_PTR
      }
      else{
#if(STD_ON == McalAdc_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  MCALADC_E_PARAM_GROUP
         );
#endif
      }
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALADC_CODE) module_McalAdc::GetGroupStatus(
   void
){
#if(STD_ON == McalAdc_InitCheck)
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
#if(STD_ON == McalAdc_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  MCALADC_E_PARAM_GROUP
         );
#endif
      }
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALADC_CODE) module_McalAdc::GetStreamLastPointer(
   McalAdc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == McalAdc_InitCheck)
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
            // McalAdc_TypeBufferResults
         }
         else{
#if(STD_ON == McalAdc_DevErrorDetect)
            ServiceDet_ReportError(
                  0 //TBD: IdModule
               ,  0 //TBD: IdInstance
               ,  0 //TBD: IdApi
               ,  MCALADC_E_IDLE
            );
#endif
         }
      }
      else{
#if(STD_ON == McalAdc_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  MCALADC_E_PARAM_GROUP
         );
#endif
      }
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
}

#if(STD_ON == McalAdc_SupportStatePowerLow)
//TBD: to be moved to additional class?
typedef enum{
      eStatePower_Full = 0
   ,  eStatePower_Maximum
}McalAdc_TypeStatePower;

typedef struct{
   McalAdc_TypeStatePower StatePowerCurrent;
   McalAdc_TypeStatePower StatePowerTarget;
   Std_TypeReturn     StateRequestActive;
}McalAdc_TypeContextLowPower;

McalAdc_TypeContextLowPower McalAdc_gstContextLowPower = {
      eStatePower_Full // TBD: InitFunction, takecare of McalAdc_SupportStatePowerLow
   ,  eStatePower_Full
   ,  E_NOT_OK
};

FUNC(void, MCALADC_CODE) module_McalAdc::PreparePowerState(
   McalAdc_TypeStatePower lstStatePowerTargetRequested
){
   if(
         eStatePower_Maximum
      >  lstStatePowerTargetRequested
   ){
      if(
            E_NOT_OK
         == StateRequestActive
      ){
         McalAdc_gstContextLowPower.StatePowerTarget = lstStatePowerTargetRequested;
         StateRequestActive = E_OK;
#if(STD_OFF == McalAdc_StatePowerModeTransitionAsynch)
         SetPowerState();
         // TBD: handle in MainFunction, take care of McalAdc_SupportStatePowerLow, McalAdc_StatePowerModeTransitionAsynch
#endif
      }
      else{
#if(STD_ON == McalAdc_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  MCALADC_E_NOT_PSERVICEOSSIBLE_TRANSITION
         );
#endif
      }
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_NOT_SUPMCALPORTED_STATE_POWER
      );
#endif
   }
}

FUNC(void, MCALADC_CODE) module_McalAdc::SetPowerState(
   void
// McalAdc_TypeChannelGroup* lpstChannelGroup
){
#if(STD_ON == McalAdc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      if(
         TRUE
         // check MCALADC_E_NOT_PREPARED_PERIPHERAL
      ){
         if(
            TRUE
            // All channel/group are in Idle status
         ){
            if(
                  E_OK
               == StateRequestActive
            ){
               McalAdc_gstContextLowPower.StatePowerCurrent = McalAdc_gstContextLowPower.StatePowerTarget;
               StateRequestActive = E_NOT_OK;
            }
            else{
#if(STD_ON == McalAdc_DevErrorDetect)
               ServiceDet_ReportError(
                     0 //TBD: IdModule
                  ,  0 //TBD: IdInstance
                  ,  0 //TBD: IdApi
                  ,  MCALADC_E_NOT_PSERVICEOSSIBLE_TRANSITION
               );
#endif
            }
         }
         else{
#if(STD_ON == McalAdc_DevErrorDetect)
            ServiceDet_ReportError(
                  0 //TBD: IdModule
               ,  0 //TBD: IdInstance
               ,  0 //TBD: IdApi
               ,  MCALADC_E_NOT_DISENGAGED
            );
#endif
         }
      }
      else{
#if(STD_ON == McalAdc_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  MCALADC_E_NOT_PREPARED_PERIPHERAL
         );
#endif
      }
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(McalAdc_TypeStatePower, MCALADC_CODE) module_McalAdc::GetCurrentPowerState(
   void
// McalAdc_TypeChannelGroup* lpstChannelGroup
){
   McalAdc_TypeStatePower lReturnValue = eStatePower_Maximum;
#if(STD_ON == McalAdc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
   lReturnValue = McalAdc_gstContextLowPower.StatePowerCurrent;
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
      );
#endif
   }
#endif
   return lReturnValue;
}

FUNC(McalAdc_TypeStatePower, MCALADC_CODE) module_McalAdc::GetTargetPowerState(
   void
// McalAdc_TypeChannelGroup* lpstChannelGroup
){
   McalAdc_TypeStatePower lReturnValue = eStatePower_Maximum;
#if(STD_ON == McalAdc_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
   lReturnValue = McalAdc_gstContextLowPower.StatePowerTarget;
#if(STD_ON == McalAdc_InitCheck)
   }
   else{
#if(STD_ON == McalAdc_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALADC_E_UNINIT
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

