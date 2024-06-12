/******************************************************************************/
/* File   : adc1.cpp                                                          */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "types.hpp"

#include "uC_Adc.hpp"
#include "uC_Mf.hpp"
#include "uC_Scu.hpp"
#include "adc1.hpp"
#include "adc1_defines.hpp"
#include "wdt1.hpp"
#include "sfr_access.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define VAREF_4750mV ((uint32)(((4.750F * 0.219F) * 1023.0F) / ADC2_VREF))

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

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
ADC1_Type ADC1 = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0
};

ADC34_Type ADC34 = {
      0
   ,  0
};

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
bool ADC1_GetVF1(void){
   return ADC1.RES_OUT1.bit.VF1;
}

bool ADC1_GetOUT_CH1(void){
   return ADC1.RES_OUT1.bit.OUT_CH1;
}

uint32 ADC1_GetRES_OUT6(void){
   return ADC1.RES_OUT6.reg;
}

void ADC1_Init(void){
   ADC1.GLOBCTR.reg        = (uint32) ADC1_GLOBCTR;
   ADC1.SQ1_4.reg          = (uint32) ADC1_SQ1_4;
   ADC1.SQ5_8.reg          = (uint32) ADC1_SQ5_8;
   ADC1.SQ_FB.reg          = (uint32) ADC1_SQ_FB;
   ADC1.CHx_EIM.reg        = (uint32) ADC1_CHx_EIM;
   ADC1.CHx_ESM.reg        = (uint32) ADC1_CHx_ESM;
   ADC1.DWSEL.reg          = (uint32) ADC1_DWSEL;
   ADC1.STC_0_3.reg        = (uint32) ADC1_STC_0_3;
   ADC1.STC_4_7.reg        = (uint32) ADC1_STC_4_7;
   ADC1.RES_OUT0.reg       = (uint32) ADC1_RES_OUT0;
   ADC1.RES_OUT1.reg       = (uint32) ADC1_RES_OUT1;
   ADC1.RES_OUT2.reg       = (uint32) ADC1_RES_OUT2;
   ADC1.RES_OUT3.reg       = (uint32) ADC1_RES_OUT3;
   ADC1.RES_OUT4.reg       = (uint32) ADC1_RES_OUT4;
   ADC1.RES_OUT5.reg       = (uint32) ADC1_RES_OUT5;
   ADC1.RES_OUT6.reg       = (uint32) ADC1_RES_OUT6;
   ADC1.RES_OUT_EIM.reg    = (uint32) ADC1_RES_OUT_EIM;
   ADC1.IE.reg             = (uint32) ADC1_IE;
   MF.VMON_SEN_CTRL.reg    = MF_VMON_SEN_CTRL;
   MF.REF2_CTRL.reg        = MF_REF2_CTRL;
   SCU.PMCON1.bit.ADC1_DIS = 0;

   ADC1_ANON_Set((uint8)ADC1_ANON_NORMAL);
   ADC1_Power_On();
#if(ADC1_XML_VERSION >= 10302)
   MF.P2_ADCSEL_CTRL.reg = MF_P2_ADCSEL_CTRL;
#endif
}
/*
bool VAREF_Enable(void){
  uint16 timeout;
  uint32 temp;
  bool res;

  res = false;

  MF.REF2_CTRL.bit.VREF5V_PD_N = 0u;

  temp = ADC2->TH6_9_LOWER.reg;

  ADC2->TH6_9_LOWER.bit.CH6 = 0u;

  timeout = 5u;

  while(((SCUPM.SYS_IS.reg & (uint32)0x5000u) != 0u) && (timeout > (uint16)0)){
    SCUPM.SYS_ISCLR.reg = (uint32)0x5000u;
    Delay_us(100u);
    timeout--;
  }

  if(timeout > (uint16)0){
    MF.REF2_CTRL.bit.VREF5V_PD_N = 1u;

    timeout = 10u;

    while((ADC2->FILT_OUT6.reg < VAREF_4750mV) && (timeout > (uint16)0)){
      Delay_us(100u);
      timeout--;
    }

    if(timeout > (uint16)0){
      res = true;
    }
  }

  ADC2->TH6_9_LOWER.reg = temp;
   return(res);
}
*/

#if(STD_ON == _ReSIM)
uint16 ReSim_ChResult  = 1001;
bool   ReSim_bRes      = true;
bool   ReSim_SocSwMode = false;
bool   ReSim_Busy      = false;
#else
#endif

bool ADC1_GetChResult(
      uint16* pVar
   ,  uint8   channel
){
   const uint32* pBaseAddr = &(ADC1.RES_OUT0.reg) - (channel << 2u);
         bool    res       = false;
   if(
         (uint8)1
      == u1_Field_Rd32(pBaseAddr, ADC1_RES_OUT0_VF0_Pos, ADC1_RES_OUT0_VF0_Msk)
   ){
      *pVar = u16_Field_Rd32(pBaseAddr, ADC1_RES_OUT0_OUT_CH0_Pos, ADC1_RES_OUT0_OUT_CH0_Msk);
      *pVar >>= 2u;
      res = true;
   }
#if(STD_ON == _ReSIM)
   *pVar = ReSim_ChResult;
   res   = ReSim_bRes;
#else
#endif
   return(res);
}

bool ADC1_GetChResult_mV(
      uint16* pVar_mV
   ,  uint8   channel
){
   uint16 var;
   bool   res = ADC1_GetChResult(
                     &var
                  ,  channel
               );

   if(
         true
      == res
   ){
      if(
            (uint8)ADC1_CH6
         == channel
      ){
         if(
               (uint8)ADC1_VDH_Attenuator_Range_0_20V
            == ADC1_VDH_Attenuator_Range_Get()
         ){
            *pVar_mV = (uint16)((var * (uint16)ADC1_VREF_22000mV) / (uint16)1023);
         }
         else{
            *pVar_mV = (uint16)((var * (uint16)ADC1_VREF_30000mV) / (uint16)1023);
         }
      }
      else{
         *pVar_mV = (uint16)((var * (uint16)ADC1_VREF_5000mV) / (uint16)1023);
      }
   }

   return(res);
}

/*
bool ADC1_GetEIMResult(uint16 *pVar){
  uint8 vf;
  bool res;
  res = false;
  vf = u1_Field_Rd32(&ADC1.RES_OUT_EIM.reg, ADC1_RES_OUT_EIM_VF8_Pos, ADC1_RES_OUT_EIM_VF8_Msk);
  if(vf == (uint8)1){
    *pVar = u16_Field_Rd32(&ADC1.RES_OUT_EIM.reg, ADC1_RES_OUT_EIM_OUT_CH_EIM_Pos, ADC1_RES_OUT_EIM_OUT_CH_EIM_Msk);
    *pVar >>= 2u;
    res = true;
  }
   return(res);
}

bool ADC1_GetEIMResult_mV(uint16 *pVar_mV){
  uint16 var;
  bool res;
  uint8 eim_ch;
  res = false;

  if(ADC1_GetEIMResult(&var) == true){
    *pVar_mV = (uint16)((var * (uint16)ADC1_VREF_5000mV) / (uint16)1023);

    eim_ch = u8_Field_Rd32(&ADC1.CHx_EIM.reg, ADC1_CHx_EIM_CHx_Pos, ADC1_CHx_EIM_CHx_Msk);

    if(eim_ch == (uint8)ADC1_CH6){
      if(ADC1_VDH_Attenuator_Range_Get() == (uint8)ADC1_VDH_Attenuator_Range_0_20V){
        *pVar_mV = (uint16)((var * (uint16)ADC1_VREF_22000mV) / (uint16)1023);
      }
      else{
        *pVar_mV = (uint16)((var * (uint16)ADC1_VREF_30000mV) / (uint16)1023);
      }
    }

    res = true;
  }

   return(res);
}
*/
void ADC1_Power_On(void){
   Field_Mod32(
         &ADC1.CTRL_STS.reg
      ,  ADC1_CTRL_STS_PD_N_Pos
      ,  ADC1_CTRL_STS_PD_N_Msk
      ,  1u
   );
}
/*
void ADC1_Power_Off(void){
   Field_Mod32(
         &ADC1.CTRL_STS.reg
      ,  ADC1_CTRL_STS_PD_N_Pos
      ,  ADC1_CTRL_STS_PD_N_Msk
      ,  0u
   );
}
*/
void ADC1_SOC_Set(void){
   Field_Mod32(
         &ADC1.CTRL_STS.reg
      ,  ADC1_CTRL_STS_SOC_Pos
      ,  ADC1_CTRL_STS_SOC_Msk
      ,  1u
   );
}

void ADC1_SW_Ch_Sel(uint32 a){
   Field_Mod32(
         &ADC1.CTRL_STS.reg
      ,  ADC1_CTRL_STS_IN_MUX_SEL_Pos
      ,  ADC1_CTRL_STS_IN_MUX_SEL_Msk
      ,  a
   );
}
/*
void ADC1_DIVA_Set(uint32 a){
   Field_Mod32(
         &ADC1.GLOBCTR.reg
      ,  ADC1_GLOBCTR_DIVA_Pos
      ,  ADC1_GLOBCTR_DIVA_Msk
      ,  a
   );
}
*/
void ADC1_ANON_Set(uint32 a){
   Field_Mod32(
         &ADC1.GLOBCTR.reg
      ,  ADC1_GLOBCTR_ANON_Pos
      ,  ADC1_GLOBCTR_ANON_Msk
      ,  a
   );
}
/*
void ADC1_Sequencer_Mode_Sel(void){
   Field_Mod32(
         &ADC1.SQ_FB.reg
      ,  ADC1_SQ_FB_SQ_RUN_Pos
      ,  ADC1_SQ_FB_SQ_RUN_Msk
      ,  1u
   );
}

void ADC1_Software_Mode_Sel(void){
   Field_Mod32(
         &ADC1.SQ_FB.reg
      ,  ADC1_SQ_FB_SQ_RUN_Pos
      ,  ADC1_SQ_FB_SQ_RUN_Msk
      ,  0u
   );
}
*/
uint8 ADC1_EOC_Sts(void){
   return(
      u1_Field_Rd32(
            &ADC1.CTRL_STS.reg
         ,  ADC1_CTRL_STS_EOC_Pos
         ,  ADC1_CTRL_STS_EOC_Msk
      )
   );
}
/*
uint8 ADC1_Current_Ch_Sts(void){
   return(
      u8_Field_Rd32(
            &ADC1.GLOBSTR.reg
         ,  ADC1_GLOBSTR_CHNR_Pos
         ,  ADC1_GLOBSTR_CHNR_Msk
      )
   );
}

uint8 ADC1_Sample_Sts(void){
   return(
      u1_Field_Rd32(
            &ADC1.GLOBSTR.reg
         ,  ADC1_GLOBSTR_SAMPLE_Pos
         ,  ADC1_GLOBSTR_SAMPLE_Msk
      )
   );
}
*/
uint8 ADC1_Busy_Sts(void){
   return(
      u1_Field_Rd32(
            &ADC1.GLOBSTR.reg
         ,  ADC1_GLOBSTR_BUSY_Pos
         ,  ADC1_GLOBSTR_BUSY_Msk
      )
   );
}
/*
uint8 ADC1_EIM_Active_Sts(void){
   return(
      u1_Field_Rd32(
            &ADC1.SQ_FB.reg
         ,  ADC1_SQ_FB_EIM_ACTIVE_Pos
         ,  ADC1_SQ_FB_EIM_ACTIVE_Msk
      )
   );
}

uint8 ADC1_ESM_Active_Sts(void){
   return(
      u1_Field_Rd32(
            &ADC1.SQ_FB.reg
         ,  ADC1_SQ_FB_ESM_ACTIVE_Pos
         ,  ADC1_SQ_FB_ESM_ACTIVE_Msk
      )
   );
}

uint8 ADC1_Current_Active_Sequence_Sts(void){
   return(
      u8_Field_Rd32(
            &ADC1.SQ_FB.reg
         ,  ADC1_SQ_FB_SQx_Pos
         ,  ADC1_SQ_FB_SQx_Msk
      )
   );
}

uint8 ADC1_Current_Active_Channel_Sts(void){
   return(
      u8_Field_Rd32(
            &ADC1.SQ_FB.reg
         ,  ADC1_SQ_FB_CHx_Pos
         ,  ADC1_SQ_FB_CHx_Msk
      )
   );
}

void ADC1_Sequence0_Set(uint32 mask_ch){
   Field_Mod32(
         &ADC1.SQ1_4.reg
      ,  ADC1_SQ1_4_SQ1_Pos
      ,  ADC1_SQ1_4_SQ1_Msk
      ,  (mask_ch)
   );
}

void ADC1_Sequence1_Set(uint32 mask_ch){
   Field_Mod32(
         &ADC1.SQ1_4.reg
      ,  ADC1_SQ1_4_SQ2_Pos
      ,  ADC1_SQ1_4_SQ2_Msk
      ,  (mask_ch)
   );
}

void ADC1_Sequence2_Set(uint32 mask_ch){
   Field_Mod32(
         &ADC1.SQ1_4.reg
      ,  ADC1_SQ1_4_SQ3_Pos
      ,  ADC1_SQ1_4_SQ3_Msk
      ,  (mask_ch)
   );
}

void ADC1_Sequence3_Set(uint32 mask_ch){
   Field_Mod32(
         &ADC1.SQ1_4.reg
      ,  ADC1_SQ1_4_SQ4_Pos
      ,  ADC1_SQ1_4_SQ4_Msk
      ,  (mask_ch)
   );
}

void ADC1_Sequence4_Set(uint32 mask_ch){
   Field_Mod32(
         &ADC1.SQ5_8.reg
      ,  ADC1_SQ5_8_SQ5_Pos
      ,  ADC1_SQ5_8_SQ5_Msk
      ,  (mask_ch)
   );
}

void ADC1_Sequence5_Set(uint32 mask_ch){
   Field_Mod32(
         &ADC1.SQ5_8.reg
      ,  ADC1_SQ5_8_SQ6_Pos
      ,  ADC1_SQ5_8_SQ6_Msk
      ,  (mask_ch)
   );
}

void ADC1_Sequence6_Set(uint32 mask_ch){
   Field_Mod32(
         &ADC1.SQ5_8.reg
      ,  ADC1_SQ5_8_SQ7_Pos
      ,  ADC1_SQ5_8_SQ7_Msk
      ,  (mask_ch)
   );
}

void ADC1_Sequence7_Set(uint32 mask_ch){
   Field_Mod32(
         &ADC1.SQ5_8.reg
      ,  ADC1_SQ5_8_SQ8_Pos
      ,  ADC1_SQ5_8_SQ8_Msk
      ,  (mask_ch)
   );
}

uint16 ADC1_Ch0_Result_Get(void){
   return(
      u16_Field_Rd32(
            &ADC1.RES_OUT0.reg
         ,  ADC1_RES_OUT0_OUT_CH0_Pos
         ,  ADC1_RES_OUT0_OUT_CH0_Msk
      )
   );
}
*/
uint16 ADC1_Ch1_Result_Get(void){
   return(
      u16_Field_Rd32(
            &ADC1.RES_OUT1.reg
         ,  ADC1_RES_OUT1_OUT_CH1_Pos
         ,  ADC1_RES_OUT1_OUT_CH1_Msk
      )
   );
}

uint8 ADC1_Ch1_ResultValid_Get(void){
   return(
      u1_Field_Rd32(
            &ADC1.RES_OUT1.reg
         ,  ADC1_RES_OUT1_VF1_Pos
         ,  ADC1_RES_OUT1_VF1_Msk
      )
   );
}
/*
uint16 ADC1_Ch2_Result_Get(void){
   return(
      u16_Field_Rd32(
            &ADC1.RES_OUT2.reg
         ,  ADC1_RES_OUT2_OUT_CH2_Pos
         ,  ADC1_RES_OUT2_OUT_CH2_Msk
      )
   );
}

uint16 ADC1_Ch3_Result_Get(void){
   return(
      u16_Field_Rd32(
            &ADC1.RES_OUT3.reg
         ,  ADC1_RES_OUT3_OUT_CH3_Pos
         ,  ADC1_RES_OUT3_OUT_CH3_Msk
      )
   );
}

uint16 ADC1_Ch4_Result_Get(void){
   return(
      u16_Field_Rd32(
            &ADC1.RES_OUT4.reg
         ,  ADC1_RES_OUT4_OUT_CH4_Pos
         ,  ADC1_RES_OUT4_OUT_CH4_Msk
      )
   );
}

uint16 ADC1_Ch5_Result_Get(void){
   return(
      u16_Field_Rd32(
            &ADC1.RES_OUT5.reg
         ,  ADC1_RES_OUT5_OUT_CH5_Pos
         ,  ADC1_RES_OUT5_OUT_CH5_Msk
      )
   );
}

uint16 ADC1_Ch6_Result_Get(void){
   return(
      u16_Field_Rd32(
            &ADC1.RES_OUT6.reg
         ,  ADC1_RES_OUT6_OUT_CH6_Pos
         ,  ADC1_RES_OUT6_OUT_CH6_Msk
      )
   );
}

uint16 ADC1_EIM_Result_Get(void){
   return(
      u16_Field_Rd32(
            &ADC1.RES_OUT_EIM.reg
         ,  ADC1_RES_OUT_EIM_OUT_CH_EIM_Pos
         ,  ADC1_RES_OUT_EIM_OUT_CH_EIM_Msk
      )
   );
}

uint16 ADC1_P20_Result_Get(void){return(ADC1_Ch0_Result_Get());}
uint16 ADC1_CSA_Result_Get(void){return(ADC1_Ch1_Result_Get());}
uint16 ADC1_P22_Result_Get(void){return(ADC1_Ch2_Result_Get());}
uint16 ADC1_P23_Result_Get(void){return(ADC1_Ch3_Result_Get());}
uint16 ADC1_P24_Result_Get(void){return(ADC1_Ch4_Result_Get());}
uint16 ADC1_P25_Result_Get(void){return(ADC1_Ch5_Result_Get());}
uint16 ADC1_VDH_Result_Get(void){return(ADC1_Ch6_Result_Get());}

uint8 ADC1_Ch0_ResultValid_Get(void){
   return(
      u1_Field_Rd32(
            &ADC1.RES_OUT0.reg
         ,  ADC1_RES_OUT0_VF0_Pos
         ,  ADC1_RES_OUT0_VF0_Msk
      )
   );
}

uint8 ADC1_Ch2_ResultValid_Get(void){
   return(
      u1_Field_Rd32(
            &ADC1.RES_OUT2.reg
         ,  ADC1_RES_OUT2_VF2_Pos
         ,  ADC1_RES_OUT2_VF2_Msk
      )
   );
}

uint8 ADC1_Ch3_ResultValid_Get(void){
   return(
      u1_Field_Rd32(
            &ADC1.RES_OUT3.reg
         ,  ADC1_RES_OUT3_VF3_Pos
         ,  ADC1_RES_OUT3_VF3_Msk
      )
   );
}

uint8 ADC1_Ch4_ResultValid_Get(void){
   return(
      u1_Field_Rd32(
            &ADC1.RES_OUT4.reg
         ,  ADC1_RES_OUT4_VF4_Pos
         ,  ADC1_RES_OUT4_VF4_Msk
      )
   );
}

uint8 ADC1_Ch5_ResultValid_Get(void){
   return(
      u1_Field_Rd32(
            &ADC1.RES_OUT5.reg
         ,  ADC1_RES_OUT5_VF5_Pos
         ,  ADC1_RES_OUT5_VF5_Msk
      )
   );
}

uint8 ADC1_Ch6_ResultValid_Get(void){
   return(
      u1_Field_Rd32(
            &ADC1.RES_OUT6.reg
         ,  ADC1_RES_OUT6_VF6_Pos
         ,  ADC1_RES_OUT6_VF6_Msk
      )
   );
}

uint8 ADC1_EIM_ResultValid_Get(void){
   return(
      u1_Field_Rd32(
            &ADC1.RES_OUT_EIM.reg
         ,  ADC1_RES_OUT_EIM_VF8_Pos
         ,  ADC1_RES_OUT_EIM_VF8_Msk
      )
   );
}

void ADC1_Ch0_DataWidth_8bit_Set(void){
   Field_Mod32(
         &ADC1.DWSEL.reg
      ,  ADC1_DWSEL_ch0_Pos
      ,  ADC1_DWSEL_ch0_Msk
      ,  1u
   );
}

void ADC1_Ch0_DataWidth_10bit_Set(void){
   Field_Mod32(
         &ADC1.DWSEL.reg
      ,  ADC1_DWSEL_ch0_Pos
      ,  ADC1_DWSEL_ch0_Msk
      ,  0u
   );
}

void ADC1_Ch1_DataWidth_8bit_Set(void){
   Field_Mod32(
         &ADC1.DWSEL.reg
      ,  ADC1_DWSEL_ch1_Pos
      ,  ADC1_DWSEL_ch1_Msk
      ,  1u
   );
}

void ADC1_Ch1_DataWidth_10bit_Set(void){
   Field_Mod32(
         &ADC1.DWSEL.reg
      ,  ADC1_DWSEL_ch1_Pos
      ,  ADC1_DWSEL_ch1_Msk
      ,  0u
   );
}

void ADC1_Ch2_DataWidth_8bit_Set(void){
   Field_Mod32(
         &ADC1.DWSEL.reg
      ,  ADC1_DWSEL_ch2_Pos
      ,  ADC1_DWSEL_ch2_Msk
      ,  1u
   );
}

void ADC1_Ch2_DataWidth_10bit_Set(void){
   Field_Mod32(
         &ADC1.DWSEL.reg
      ,  ADC1_DWSEL_ch2_Pos
      ,  ADC1_DWSEL_ch2_Msk
      ,  0u
   );
}

void ADC1_Ch3_DataWidth_8bit_Set(void){
   Field_Mod32(
         &ADC1.DWSEL.reg
      ,  ADC1_DWSEL_ch3_Pos
      ,  ADC1_DWSEL_ch3_Msk
      ,  1u
   );
}

void ADC1_Ch3_DataWidth_10bit_Set(void){
   Field_Mod32(
         &ADC1.DWSEL.reg
      ,  ADC1_DWSEL_ch3_Pos
      ,  ADC1_DWSEL_ch3_Msk
      ,  0u
   );
}

void ADC1_Ch4_DataWidth_8bit_Set(void){
   Field_Mod32(
         &ADC1.DWSEL.reg
      ,  ADC1_DWSEL_ch4_Pos
      ,  ADC1_DWSEL_ch4_Msk
      ,  1u
   );
}

void ADC1_Ch4_DataWidth_10bit_Set(void){
   Field_Mod32(
         &ADC1.DWSEL.reg
      ,  ADC1_DWSEL_ch4_Pos
      ,  ADC1_DWSEL_ch4_Msk
      ,  0u
   );
}

void ADC1_Ch5_DataWidth_8bit_Set(void){
   Field_Mod32(
         &ADC1.DWSEL.reg
      ,  ADC1_DWSEL_ch5_Pos
      ,  ADC1_DWSEL_ch5_Msk
      ,  1u
   );
}

void ADC1_Ch5_DataWidth_10bit_Set(void){
   Field_Mod32(
         &ADC1.DWSEL.reg
      ,  ADC1_DWSEL_ch5_Pos
      ,  ADC1_DWSEL_ch5_Msk
      ,  0u
   );
}

void ADC1_Ch6_DataWidth_8bit_Set(void){
   Field_Mod32(
         &ADC1.DWSEL.reg
      ,  ADC1_DWSEL_ch6_Pos
      ,  ADC1_DWSEL_ch6_Msk
      ,  1u
   );
}

void ADC1_Ch6_DataWidth_10bit_Set(void){
   Field_Mod32(
         &ADC1.DWSEL.reg
      ,  ADC1_DWSEL_ch6_Pos
      ,  ADC1_DWSEL_ch6_Msk
      ,  0u
   );
}

void ADC1_Ch0_Sample_Time_Set(uint32 stc){
   Field_Mod32(
         &ADC1.STC_0_3.reg
      ,  ADC1_STC_0_3_ch0_Pos
      ,  ADC1_STC_0_3_ch0_Msk
      ,  stc
   );
}

void ADC1_Ch1_Sample_Time_Set(uint32 stc){
   Field_Mod32(
         &ADC1.STC_0_3.reg
      ,  ADC1_STC_0_3_ch1_Pos
      ,  ADC1_STC_0_3_ch1_Msk
      ,  stc
   );
}

void ADC1_Ch2_Sample_Time_Set(uint32 stc){
   Field_Mod32(
         &ADC1.STC_0_3.reg
      ,  ADC1_STC_0_3_ch2_Pos
      ,  ADC1_STC_0_3_ch2_Msk
      ,  stc
   );
}

void ADC1_Ch3_Sample_Time_Set(uint32 stc){
   Field_Mod32(
         &ADC1.STC_0_3.reg
      ,  ADC1_STC_0_3_ch3_Pos
      ,  ADC1_STC_0_3_ch3_Msk
      ,  stc
   );
}

void ADC1_Ch4_Sample_Time_Set(uint32 stc){
   Field_Mod32(
         &ADC1.STC_4_7.reg
      ,  ADC1_STC_4_7_ch4_Pos
      ,  ADC1_STC_4_7_ch4_Msk
      ,  stc
   );
}

void ADC1_Ch5_Sample_Time_Set(uint32 stc){
   Field_Mod32(
         &ADC1.STC_4_7.reg
      ,  ADC1_STC_4_7_ch5_Pos
      ,  ADC1_STC_4_7_ch5_Msk
      ,  stc
   );
}

void ADC1_Ch6_Sample_Time_Set(uint32 stc){
   Field_Mod32(
         &ADC1.STC_4_7.reg
      ,  ADC1_STC_4_7_ch6_Pos
      ,  ADC1_STC_4_7_ch6_Msk
      ,  stc
   );
}

void ADC1_Ch0_WaitForRead_Set(void){
   Field_Mod32(
         &ADC1.RES_OUT0.reg
      ,  ADC1_RES_OUT0_WFR0_Pos
      ,  ADC1_RES_OUT0_WFR0_Msk
      ,  1u
   );
}

void ADC1_Ch0_Overwrite_Set(void){
   Field_Mod32(
         &ADC1.RES_OUT0.reg
      ,  ADC1_RES_OUT0_WFR0_Pos
      ,  ADC1_RES_OUT0_WFR0_Msk
      ,  0u
   );
}

void ADC1_Ch1_WaitForRead_Set(void){
   Field_Mod32(
         &ADC1.RES_OUT1.reg
      ,  ADC1_RES_OUT1_WFR1_Pos
      ,  ADC1_RES_OUT1_WFR1_Msk
      ,  1u
   );
}

void ADC1_Ch1_Overwrite_Set(void){
   Field_Mod32(
         &ADC1.RES_OUT1.reg
      ,  ADC1_RES_OUT1_WFR1_Pos
      ,  ADC1_RES_OUT1_WFR1_Msk
      ,  0u
   );
}

void ADC1_Ch2_WaitForRead_Set(void){
   Field_Mod32(
         &ADC1.RES_OUT2.reg
      ,  ADC1_RES_OUT2_WFR2_Pos
      ,  ADC1_RES_OUT2_WFR2_Msk
      ,  1u
   );
}

void ADC1_Ch2_Overwrite_Set(void){
   Field_Mod32(
         &ADC1.RES_OUT2.reg
      ,  ADC1_RES_OUT2_WFR2_Pos
      ,  ADC1_RES_OUT2_WFR2_Msk
      ,  0u
   );
}

void ADC1_Ch3_WaitForRead_Set(void){
   Field_Mod32(
         &ADC1.RES_OUT3.reg
      ,  ADC1_RES_OUT3_WFR3_Pos
      ,  ADC1_RES_OUT3_WFR3_Msk
      ,  1u
   );
}

void ADC1_Ch3_Overwrite_Set(void){
   Field_Mod32(
         &ADC1.RES_OUT3.reg
      ,  ADC1_RES_OUT3_WFR3_Pos
      ,  ADC1_RES_OUT3_WFR3_Msk
      ,  0u
   );
}

void ADC1_Ch4_WaitForRead_Set(void){
   Field_Mod32(
         &ADC1.RES_OUT4.reg
      ,  ADC1_RES_OUT4_WFR4_Pos
      ,  ADC1_RES_OUT4_WFR4_Msk
      ,  1u
   );
}

void ADC1_Ch4_Overwrite_Set(void){
   Field_Mod32(
         &ADC1.RES_OUT4.reg
      ,  ADC1_RES_OUT4_WFR4_Pos
      ,  ADC1_RES_OUT4_WFR4_Msk
      ,  0u
   );
}

void ADC1_Ch5_WaitForRead_Set(void){
   Field_Mod32(
         &ADC1.RES_OUT5.reg
      ,  ADC1_RES_OUT5_WFR5_Pos
      ,  ADC1_RES_OUT5_WFR5_Msk
      ,  1u
   );
}

void ADC1_Ch5_Overwrite_Set(void){
   Field_Mod32(
         &ADC1.RES_OUT5.reg
      ,  ADC1_RES_OUT5_WFR5_Pos
      ,  ADC1_RES_OUT5_WFR5_Msk
      ,  0u
   );
}

void ADC1_Ch6_WaitForRead_Set(void){
   Field_Mod32(
         &ADC1.RES_OUT6.reg
      ,  ADC1_RES_OUT6_WFR6_Pos
      ,  ADC1_RES_OUT6_WFR6_Msk
      ,  1u
   );
}

void ADC1_Ch6_Overwrite_Set(void){
   Field_Mod32(
         &ADC1.RES_OUT6.reg
      ,  ADC1_RES_OUT6_WFR6_Pos
      ,  ADC1_RES_OUT6_WFR6_Msk
      ,  0u
   );
}

void ADC1_EIM_Channel_Set(uint32 ch){
   Field_Mod32(
         &ADC1.CHx_EIM.reg
      ,  ADC1_CHx_EIM_CHx_Pos
      ,  ADC1_CHx_EIM_CHx_Msk
      ,  ch
   );
}

void ADC1_ESM_Channel_Set(uint32 mask_ch){
   Field_Mod32(
         &ADC1.CHx_ESM.reg
      ,  ADC1_CHx_ESM_ESM_0_Pos
      ,  ADC1_CHx_ESM_ESM_0_Msk
      ,  (mask_ch
   ));
}

void ADC1_VDH_Attenuator_On(void){
   Field_Mod32(
         &MF.VMON_SEN_CTRL.reg
      ,  MF_VMON_SEN_CTRL_VMON_SEN_PD_N_Pos
      ,  MF_VMON_SEN_CTRL_VMON_SEN_PD_N_Msk
      ,  1u
   );
}

void ADC1_VDH_Attenuator_Off(void){
   Field_Mod32(
         &MF.VMON_SEN_CTRL.reg
      ,  MF_VMON_SEN_CTRL_VMON_SEN_PD_N_Pos
      ,  MF_VMON_SEN_CTRL_VMON_SEN_PD_N_Msk
      ,  0u
   );
}

void ADC1_VDH_Attenuator_Zhigh_Set(void){
   Field_Mod32(
         &MF.VMON_SEN_CTRL.reg
      ,  MF_VMON_SEN_CTRL_VMON_SEN_HRESO_5V_Pos
      ,  MF_VMON_SEN_CTRL_VMON_SEN_HRESO_5V_Msk
      ,  1u
   );
}

void ADC1_VDH_Attenuator_Zlow_Set(void){
   Field_Mod32(
         &MF.VMON_SEN_CTRL.reg
      ,  MF_VMON_SEN_CTRL_VMON_SEN_HRESO_5V_Pos
      ,  MF_VMON_SEN_CTRL_VMON_SEN_HRESO_5V_Msk
      ,  0u
   );
}

void ADC1_Ch0_Int_Clr(void){
   Field_Wrt32(
         &ADC1.ICLR.reg
      ,  ADC1_ICLR_CH0_ICLR_Pos
      ,  ADC1_ICLR_CH0_ICLR_Msk
      ,  1u
   );
}

void ADC1_Ch1_Int_Clr(void){
   Field_Wrt32(
         &ADC1.ICLR.reg
      ,  ADC1_ICLR_CH1_ICLR_Pos
      ,  ADC1_ICLR_CH1_ICLR_Msk
      ,  1u
   );
}

void ADC1_Ch2_Int_Clr(void){
   Field_Wrt32(
         &ADC1.ICLR.reg
      ,  ADC1_ICLR_CH2_ICLR_Pos
      ,  ADC1_ICLR_CH2_ICLR_Msk
      ,  1u
   );
}

void ADC1_Ch3_Int_Clr(void){
   Field_Wrt32(
         &ADC1.ICLR.reg
      ,  ADC1_ICLR_CH3_ICLR_Pos
      ,  ADC1_ICLR_CH3_ICLR_Msk
      ,  1u
   );
}

void ADC1_Ch4_Int_Clr(void){
   Field_Wrt32(
         &ADC1.ICLR.reg
      ,  ADC1_ICLR_CH4_ICLR_Pos
      ,  ADC1_ICLR_CH4_ICLR_Msk
      ,  1u
   );
}

void ADC1_Ch5_Int_Clr(void){
   Field_Wrt32(
         &ADC1.ICLR.reg
      ,  ADC1_ICLR_CH5_ICLR_Pos
      ,  ADC1_ICLR_CH5_ICLR_Msk
      ,  1u
   );
}

void ADC1_Ch6_Int_Clr(void){
   Field_Wrt32(
         &ADC1.ICLR.reg
      ,  ADC1_ICLR_CH6_ICLR_Pos
      ,  ADC1_ICLR_CH6_ICLR_Msk
      ,  1u
   );
}

void ADC1_EIM_Int_Clr(void){
   Field_Wrt32(
         &ADC1.ICLR.reg
      ,  ADC1_ICLR_EIM_ICLR_Pos
      ,  ADC1_ICLR_EIM_ICLR_Msk
      ,  1u
   );
}

void ADC1_ESM_Int_Clr(void){
   Field_Wrt32(
         &ADC1.ICLR.reg
      ,  ADC1_ICLR_ESM_ICLR_Pos
      ,  ADC1_ICLR_ESM_ICLR_Msk
      ,  1u
   );
}

void ADC1_Ch0_Int_En(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_CH0_IE_Pos
      ,  ADC1_IE_CH0_IE_Msk
      ,  1u
   );
}

void ADC1_Ch0_Int_Dis(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_CH0_IE_Pos
      ,  ADC1_IE_CH0_IE_Msk
      ,  0u
   );
}

void ADC1_Ch1_Int_En(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_CH1_IE_Pos
      ,  ADC1_IE_CH1_IE_Msk
      ,  1u
   );
}

void ADC1_Ch1_Int_Dis(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_CH1_IE_Pos
      ,  ADC1_IE_CH1_IE_Msk
      ,  0u
   );
}

void ADC1_Ch2_Int_En(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_CH2_IE_Pos
      ,  ADC1_IE_CH2_IE_Msk
      ,  1u
   );
}

void ADC1_Ch2_Int_Dis(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_CH2_IE_Pos
      ,  ADC1_IE_CH2_IE_Msk
      ,  0u
   );
}

void ADC1_Ch3_Int_En(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_CH3_IE_Pos
      ,  ADC1_IE_CH3_IE_Msk
      ,  1u
   );
}

void ADC1_Ch3_Int_Dis(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_CH3_IE_Pos
      ,  ADC1_IE_CH3_IE_Msk
      ,  0u
   );
}

void ADC1_Ch4_Int_En(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_CH4_IE_Pos
      ,  ADC1_IE_CH4_IE_Msk
      ,  1u
   );
}

void ADC1_Ch4_Int_Dis(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_CH4_IE_Pos
      ,  ADC1_IE_CH4_IE_Msk
      ,  0u
   );
}

void ADC1_Ch5_Int_En(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_CH5_IE_Pos
      ,  ADC1_IE_CH5_IE_Msk
      ,  1u
   );
}

void ADC1_Ch5_Int_Dis(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_CH5_IE_Pos
      ,  ADC1_IE_CH5_IE_Msk
      ,  0u
   );
}

void ADC1_Ch6_Int_En(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_CH6_IE_Pos
      ,  ADC1_IE_CH6_IE_Msk
      ,  1u
   );
}

void ADC1_Ch6_Int_Dis(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_CH6_IE_Pos
      ,  ADC1_IE_CH6_IE_Msk
      ,  0u
   );
}

void ADC1_EIM_Int_En(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_EIM_IE_Pos
      ,  ADC1_IE_EIM_IE_Msk
      ,  1u
   );
}

void ADC1_EIM_Int_Dis(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_EIM_IE_Pos
      ,  ADC1_IE_EIM_IE_Msk
      ,  0u
   );
}

void ADC1_ESM_Int_En(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_ESM_IE_Pos
      ,  ADC1_IE_ESM_IE_Msk
      ,  1u
   );
}

void ADC1_ESM_Int_Dis(void){
   Field_Mod32(
         &ADC1.IE.reg
      ,  ADC1_IE_ESM_IE_Pos
      ,  ADC1_IE_ESM_IE_Msk
      ,  0u
   );
}

void ADC1_VDH_Attenuator_Range_0_30V_Set(void){
   Field_Mod32(
         &MF.VMON_SEN_CTRL.reg
      ,  MF_VMON_SEN_CTRL_VMON_SEN_SEL_INRANGE_Pos
      ,  MF_VMON_SEN_CTRL_VMON_SEN_SEL_INRANGE_Msk
      ,  ADC1_VDH_Attenuator_Range_0_30V
   );
}

void ADC1_VDH_Attenuator_Range_0_20V_Set(void){
   Field_Mod32(
         &MF.VMON_SEN_CTRL.reg
      ,  MF_VMON_SEN_CTRL_VMON_SEN_SEL_INRANGE_Pos
      ,  MF_VMON_SEN_CTRL_VMON_SEN_SEL_INRANGE_Msk
      ,  ADC1_VDH_Attenuator_Range_0_20V
   );
}
*/
uint8 ADC1_VDH_Attenuator_Range_Get(void){
   return(
      u8_Field_Rd32(
            &MF.VMON_SEN_CTRL.reg
         ,  MF_VMON_SEN_CTRL_VMON_SEN_SEL_INRANGE_Pos
         ,  MF_VMON_SEN_CTRL_VMON_SEN_SEL_INRANGE_Msk
      )
   );
}
/*
void ADC1_SetEIMChannel(uint8 channel){ADC1_EIM_Channel_Set(channel);}
void ADC1_SetSwMode_Channel(uint8 channel){ADC1_SW_Ch_Sel(channel);}
*/

void ADC1_SetMode(uint8 mode){
   Field_Mod32(
         &ADC1.SQ_FB.reg
      ,  ADC1_SQ_FB_SQ_RUN_Pos
      ,  ADC1_SQ_FB_SQ_RUN_Msk
      ,  mode
   );
#if(STD_ON == _ReSIM)
   if(SW_MODE == mode){
      ReSim_Busy = false;
   }
   else if(SEQ_MODE == mode){
      ReSim_Busy = true;
   }
#else
#endif
}

void ADC1_SetSocSwMode(uint8 Ch){
   ADC1_SW_Ch_Sel(Ch);
   ADC1_SOC_Set();
#if(STD_ON == _ReSIM)
   ReSim_SocSwMode = true;
   ADC1.RES_OUT1.bit.VF1 = 1;
   ADC1.RES_OUT1.bit.OUT_CH1 = 1650;
#else
#endif
}

bool ADC1_GetEocSwMode(void){
   bool res = false;
   if(ADC1_EOC_Sts() == (uint8)1){
      res = true;
   }
#if(STD_ON == _ReSIM)
   res = ReSim_SocSwMode;
#else
#endif
   return(res);
}
/*
bool ADC1_GetSwModeResult(uint16 *pVar){
   uint8 channel = u8_Field_Rd32(
         &ADC1.CTRL_STS.reg
      ,  ADC1_CTRL_STS_IN_MUX_SEL_Pos
      ,  ADC1_CTRL_STS_IN_MUX_SEL_Msk
   );

   return(ADC1_GetChResult(pVar, channel));
}

bool ADC1_GetSwModeResult_mV(uint16 *pVar_mV){
   uint8 channel = u8_Field_Rd32(
         &ADC1.CTRL_STS.reg
      ,  ADC1_CTRL_STS_IN_MUX_SEL_Pos
      ,  ADC1_CTRL_STS_IN_MUX_SEL_Msk
   );

   return(ADC1_GetChResult_mV(pVar_mV, channel));
}
*/
bool ADC1_Busy(void){
   bool res = false;
   if(ADC1_Busy_Sts() == (uint8)1){
      res = true;
   }
#if(STD_ON == _ReSIM)
   res = ReSim_Busy;
#else
#endif
   return(res);
}
/*
void ADC1_EIM_Trigger_Select(TADC1_TRIGG_SEL trigsel){
   Field_Mod32(
         &ADC1.CHx_EIM.reg
      ,  ADC1_CHx_EIM_TRIG_SEL_Pos
      ,  ADC1_CHx_EIM_TRIG_SEL_Msk
      ,  (uint8)trigsel
   );
}

void ADC1_EIM_Repeat_Counter_Set(TADC1_EIM_REP_CNT repcnt){
   Field_Mod32(
         &ADC1.CHx_EIM.reg
      ,  ADC1_CHx_EIM_REP_Pos
      ,  ADC1_CHx_EIM_REP_Msk
      ,  (uint8)repcnt
   );
}

void ADC1_ESM_Trigger_Select(TADC1_TRIGG_SEL trigsel){
   Field_Mod32(
         &ADC1.CHx_ESM.reg
      ,  ADC1_CHx_ESM_TRIG_SEL_Pos
      ,  ADC1_CHx_ESM_TRIG_SEL_Msk
      ,  (uint8)trigsel
   );
}

bool ADC1_isEndOfConversion(void){
   bool res = false;
   if(ADC1_EOC_Sts() == (uint8)1){
      res = true;
   }
   return(res);
}

bool ADC1_isEIMactive(void){
   bool res = false;
   if(ADC1_EIM_Active_Sts() == (uint8)1){
      res = true;
   }
   return(res);
}

bool ADC1_isESMactive(void){
   bool res = false;
   if(ADC1_ESM_Active_Sts() == (uint8)1){
      res = true;
   }
   return(res);
}

TADC1_ANON ADC1_ANON_Sts(void){
   TADC1_ANON_U res;

   res.dword = u32_Field_Rd32(
         &ADC1.GLOBSTR.reg
      ,  ADC1_GLOBSTR_ANON_ST_Pos
      ,  ADC1_GLOBSTR_ANON_ST_Msk
   );

   return(res.adc1_anon);
}
*/

extern void RteWrite_AdcResult(  //TBD: move to destination module specific Rte interface
   sint16* lptrInput
);
void Emo_HandleAdc1(void){
   static uint32 lu32AdcResult[2u];
   static sint16 ls16AdcResult[3u];
   ADC1.IE.bit.ESM_IE = 0; lu32AdcResult[0u] = ADC1.RES_OUT1.reg; ADC1.ICLR.bit.ESM_ICLR = 1;
   ADC1.IE.bit.ESM_IE = 1; lu32AdcResult[1u] = ADC1.RES_OUT1.reg;
   ls16AdcResult[0u] = lu32AdcResult[0u] & 0x0FFFu;
   ls16AdcResult[1u] = lu32AdcResult[1u] & 0x0FFFu;
   ls16AdcResult[2u] = ls16AdcResult[0u]
                     + ls16AdcResult[1u];
   RteWrite_AdcResult(&ls16AdcResult[0u]);
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

