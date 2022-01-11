#pragma once

#include "Std_Types.h"
#include "Compiler_Cfg_Adc.h"

class class_Adc{
   public:
      FUNC(void, ADC_CODE) InitFunction(void);
      FUNC(void, ADC_CODE) MainFunction(void);
};

extern class_Adc Adc;

