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
#define ADC_COREFUNCTIONALITIES                                                \
              FUNC(void, ADC_CODE) SetupResultBuffer        (void);            \
              FUNC(void, ADC_CODE) StartGroupConversion     (Adc_TypeChannelGroup* lpstChannelGroup);     \
              FUNC(void, ADC_CODE) StopGroupConversion      (Adc_TypeChannelGroup* lpstChannelGroup);     \
              FUNC(void, ADC_CODE) ReadGroup                (void);            \
              FUNC(void, ADC_CODE) EnableHardwareTrigger    (void);            \
              FUNC(void, ADC_CODE) DisableHardwareTrigger   (void);            \
              FUNC(void, ADC_CODE) EnableGroupNotification  (void);            \
              FUNC(void, ADC_CODE) DisableGroupNotification (void);            \
              FUNC(void, ADC_CODE) GetGroupStatus           (void);            \
              FUNC(void, ADC_CODE) GetStreamLastPointer     (void);            \

//TBD: to be moved to additional class?
#if(STD_ON == Adc_SupportStatePowerLow)
              FUNC(void,               ADC_CODE) PreparePowerState    (Adc_TypeStatePower lstStatePowerTargetRequested);     \
              FUNC(void,               ADC_CODE) SetPowerState        (void);     \
              FUNC(Adc_TypeStatePower, ADC_CODE) GetCurrentPowerState (void);     \
              FUNC(Adc_TypeStatePower, ADC_CODE) GetTargetPowerState  (void);     \
#endif

#define ADC_COREFUNCTIONALITIES_VIRTUAL                                        \
      virtual FUNC(void, ADC_CODE) SetupResultBuffer        (void) = 0;        \
      virtual FUNC(void, ADC_CODE) StartGroupConversion     (Adc_TypeChannelGroup* lpstChannelGroup) = 0; \
      virtual FUNC(void, ADC_CODE) StopGroupConversion      (Adc_TypeChannelGroup* lpstChannelGroup) = 0; \
      virtual FUNC(void, ADC_CODE) ReadGroup                (void) = 0;        \
      virtual FUNC(void, ADC_CODE) EnableHardwareTrigger    (void) = 0;        \
      virtual FUNC(void, ADC_CODE) DisableHardwareTrigger   (void) = 0;        \
      virtual FUNC(void, ADC_CODE) EnableGroupNotification  (void) = 0;        \
      virtual FUNC(void, ADC_CODE) DisableGroupNotification (void) = 0;        \
      virtual FUNC(void, ADC_CODE) GetGroupStatus           (void) = 0;        \
      virtual FUNC(void, ADC_CODE) GetStreamLastPointer     (void) = 0;        \

//TBD: to be moved to additional class?
#if(STD_ON == Adc_SupportStatePowerLow)
      virtual FUNC(void,               ADC_CODE) PreparePowerState    (Adc_TypeStatePower lstStatePowerTargetRequested) = 0; \
      virtual FUNC(void,               ADC_CODE) SetPowerState        (void) = 0; \
      virtual FUNC(Adc_TypeStatePower, ADC_CODE) GetCurrentPowerState (void) = 0; \
      virtual FUNC(Adc_TypeStatePower, ADC_CODE) GetTargetPowerState  (void) = 0; \
#endif

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
#include "CfgAdc.hpp"
#include "infAdc_Det.hpp"

class class_Adc_Functionality{
   public:
      ADC_COREFUNCTIONALITIES_VIRTUAL
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

