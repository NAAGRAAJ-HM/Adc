#pragma once

#include "Std_Types.h"

class class_Adc{
   public:
      FUNC(void, ADC_CODE) InitFunction(void);
      FUNC(void, ADC_CODE) MainFunction(void);
};

extern class_Adc Adc;

