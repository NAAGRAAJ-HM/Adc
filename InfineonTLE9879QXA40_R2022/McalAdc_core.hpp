#pragma once
/******************************************************************************/
/* File   : McalAdc_core.hpp                                                      */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_McalAdc.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define MCALADC_CORE_FUNCTIONALITIES                                               \
              FUNC(void, MCALADC_CODE) SetupResultBuffer        (void);            \
              FUNC(void, MCALADC_CODE) StartGroupConversion     (McalAdc_TypeChannelGroup* lpstChannelGroup);     \
              FUNC(void, MCALADC_CODE) StopGroupConversion      (McalAdc_TypeChannelGroup* lpstChannelGroup);     \
              FUNC(void, MCALADC_CODE) ReadGroup                (McalAdc_TypeChannelGroup* lpstChannelGroup);     \
              FUNC(void, MCALADC_CODE) EnableHardwareTrigger    (McalAdc_TypeChannelGroup* lpstChannelGroup);     \
              FUNC(void, MCALADC_CODE) DisableHardwareTrigger   (McalAdc_TypeChannelGroup* lpstChannelGroup);     \
              FUNC(void, MCALADC_CODE) EnableGroupNotification  (void); /*McalAdc_TypeChannelGroup* lpstChannelGroup);*/ \
              FUNC(void, MCALADC_CODE) DisableGroupNotification (void); /*McalAdc_TypeChannelGroup* lpstChannelGroup);*/ \
              FUNC(void, MCALADC_CODE) GetGroupStatus           (void);            \
              FUNC(void, MCALADC_CODE) GetStreamLastPointer     (McalAdc_TypeChannelGroup* lpstChannelGroup);     \

#define MCALADC_CORE_FUNCTIONALITIES_VIRTUAL                                       \
      virtual FUNC(void, MCALADC_CODE) SetupResultBuffer        (void) = 0;        \
      virtual FUNC(void, MCALADC_CODE) StartGroupConversion     (McalAdc_TypeChannelGroup* lpstChannelGroup) = 0; \
      virtual FUNC(void, MCALADC_CODE) StopGroupConversion      (McalAdc_TypeChannelGroup* lpstChannelGroup) = 0; \
      virtual FUNC(void, MCALADC_CODE) ReadGroup                (McalAdc_TypeChannelGroup* lpstChannelGroup) = 0; \
      virtual FUNC(void, MCALADC_CODE) EnableHardwareTrigger    (McalAdc_TypeChannelGroup* lpstChannelGroup) = 0; \
      virtual FUNC(void, MCALADC_CODE) DisableHardwareTrigger   (McalAdc_TypeChannelGroup* lpstChannelGroup) = 0; \
      virtual FUNC(void, MCALADC_CODE) EnableGroupNotification  (void) = 0; /*McalAdc_TypeChannelGroup* lpstChannelGroup) = 0;*/ \
      virtual FUNC(void, MCALADC_CODE) DisableGroupNotification (void) = 0; /*McalAdc_TypeChannelGroup* lpstChannelGroup) = 0;*/ \
      virtual FUNC(void, MCALADC_CODE) GetGroupStatus           (void) = 0;        \
      virtual FUNC(void, MCALADC_CODE) GetStreamLastPointer     (McalAdc_TypeChannelGroup* lpstChannelGroup) = 0; \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_McalAdc_Functionality{
   public:
      MCALADC_CORE_FUNCTIONALITIES_VIRTUAL
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

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

