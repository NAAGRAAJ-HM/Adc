#pragma once
/*****************************************************/
/* File   : Adc_Unused.h                             */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "Std_Types.h"
#include "Compiler_Cfg_Adc.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class class_Adc_Unused{
   public:
/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
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
      FUNC(void, ADC_CODE) GetVersionInfo           (void);
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
//extern class_Adc Adc;

/*****************************************************/
/* EOF                                               */
/*****************************************************/

