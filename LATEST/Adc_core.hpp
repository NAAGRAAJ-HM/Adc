#pragma once
/******************************************************************************/
/* File   : Adc_core.hpp                                                      */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_Adc.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define ADC_CORE_FUNCTIONALITIES                                               \
              FUNC(void, ADC_CODE) SetupResultBuffer        (void);            \
              FUNC(void, ADC_CODE) StartGroupConversion     (Adc_TypeChannelGroup* lpstChannelGroup);     \
              FUNC(void, ADC_CODE) StopGroupConversion      (Adc_TypeChannelGroup* lpstChannelGroup);     \
              FUNC(void, ADC_CODE) ReadGroup                (void);            \
              FUNC(void, ADC_CODE) EnableHardwareTrigger    (Adc_TypeChannelGroup* lpstChannelGroup);     \
              FUNC(void, ADC_CODE) DisableHardwareTrigger   (Adc_TypeChannelGroup* lpstChannelGroup);     \
              FUNC(void, ADC_CODE) EnableGroupNotification  (Adc_TypeChannelGroup* lpstChannelGroup);     \
              FUNC(void, ADC_CODE) DisableGroupNotification (Adc_TypeChannelGroup* lpstChannelGroup);     \
              FUNC(void, ADC_CODE) GetGroupStatus           (void);            \
              FUNC(void, ADC_CODE) GetStreamLastPointer     (void);            \

#define ADC_CORE_FUNCTIONALITIES_VIRTUAL                                       \
      virtual FUNC(void, ADC_CODE) SetupResultBuffer        (void) = 0;        \
      virtual FUNC(void, ADC_CODE) StartGroupConversion     (Adc_TypeChannelGroup* lpstChannelGroup) = 0; \
      virtual FUNC(void, ADC_CODE) StopGroupConversion      (Adc_TypeChannelGroup* lpstChannelGroup) = 0; \
      virtual FUNC(void, ADC_CODE) ReadGroup                (void) = 0;        \
      virtual FUNC(void, ADC_CODE) EnableHardwareTrigger    (Adc_TypeChannelGroup* lpstChannelGroup) = 0; \
      virtual FUNC(void, ADC_CODE) DisableHardwareTrigger   (Adc_TypeChannelGroup* lpstChannelGroup) = 0; \
      virtual FUNC(void, ADC_CODE) EnableGroupNotification  (Adc_TypeChannelGroup* lpstChannelGroup) = 0; \
      virtual FUNC(void, ADC_CODE) DisableGroupNotification (Adc_TypeChannelGroup* lpstChannelGroup) = 0; \
      virtual FUNC(void, ADC_CODE) GetGroupStatus           (void) = 0;        \
      virtual FUNC(void, ADC_CODE) GetStreamLastPointer     (void) = 0;        \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_Adc_Functionality{
   public:
      ADC_CORE_FUNCTIONALITIES_VIRTUAL
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

