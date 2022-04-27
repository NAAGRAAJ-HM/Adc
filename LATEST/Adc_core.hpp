#pragma once
/******************************************************************************/
/* File   : Adc_core.hpp                                                      */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

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
      FUNC(void, ADC_CODE) SetupResultBuffer        (void);
      FUNC(void, ADC_CODE) StartGroupConversion     (Adc_TypeChannelGroup* lpstChannelGroup);
      FUNC(void, ADC_CODE) StopGroupConversion      (Adc_TypeChannelGroup* lpstChannelGroup);
      FUNC(void, ADC_CODE) ReadGroup                (void);
      FUNC(void, ADC_CODE) EnableHardwareTrigger    (void);
      FUNC(void, ADC_CODE) DisableHardwareTrigger   (void);
      FUNC(void, ADC_CODE) EnableGroupNotification  (void);
      FUNC(void, ADC_CODE) DisableGroupNotification (void);
      FUNC(void, ADC_CODE) GetGroupStatus           (void);
      FUNC(void, ADC_CODE) GetStreamLastPointer     (void);

//TBD: to be moved to additional class?
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

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

