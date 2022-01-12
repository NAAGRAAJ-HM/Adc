#pragma once

#include "Std_Types.h"
#include "Compiler_Cfg_Adc.h"

class class_Adc{
   public:
      FUNC(void, ADC_CODE) InitFunction             (void);
      FUNC(void, ADC_CODE) MainFunction             (void);
      FUNC(void, ADC_CODE) DeInitFunction           (void);
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

extern class_Adc Adc;

