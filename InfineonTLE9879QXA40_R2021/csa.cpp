/******************************************************************************/
/* File   : Template.hpp                                                      */
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
#include "types.hpp"

#include "csa.hpp"

#include "uC_Csa.hpp"
#include "uC_Mf.hpp"

#include "sfr_access.hpp"
#include "adc1.hpp"
#include "RTE_Components.hpp"

#include "csa_defines.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

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
CSA_Type CSA = {
      0, 0, 0, 0
};

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
void CSA_ClearVZERO(void){ // CSA_Power_Off ?
   CSA.CTRL.bit.VZERO = 0;
}

void CSA_Init(void){
#if(CONFIGWIZARD == 1)
   CSA.CTRL.reg = (uint32) CSA_CTRL;
#else
   CSA.CTRL.reg = (uint32) MF_CSA_CTRL;
#endif
   MF.P2_ADCSEL_CTRL.bit.ADC1_CH1_SEL = 1u;
}
/*
uint16 CSA_Offset_Get(void){
   uint16 offset;
   uint32 adc1_dwsel;
   uint32 adc1_sq_fb;
   uint32 adc1_stc_0_3;
   uint32 adc1_globctr;
   uint32 adc1_ie;
   uint32 adc1_ctrl_sts;
   adc1_dwsel    = ADC1.DWSEL.reg;
   adc1_sq_fb    = ADC1.SQ_FB.reg;
   adc1_stc_0_3  = ADC1.STC_0_3.reg;
   adc1_globctr  = ADC1.GLOBCTR.reg;
   adc1_ie       = ADC1.IE.reg;
   adc1_ctrl_sts = ADC1.CTRL_STS.reg;
   CSA.CTRL.bit.VZERO = 0u;
   ADC1_Ch1_Int_Dis();
   ADC1_Power_On();
   ADC1_ANON_Set((uint8)ADC1_ANON_NORMAL);
   if(SystemFrequency > 24000000u){
      ADC1_DIVA_Set(1);
   }
   else{
      ADC1_DIVA_Set(0);
   }
   ADC1_Ch1_DataWidth_10bit_Set();
   ADC1_Ch1_Sample_Time_Set(10);
   ADC1_Software_Mode_Sel();
   while(ADC1_Busy() == true){}
   ADC1_SW_Ch_Sel(ADC1_CSA);
   ADC1_SOC_Set();
   while(ADC1_isEndOfConversion() == false) {}
   offset = ADC1_Ch1_Result_Get();
   ADC1_Ch1_Int_Clr();
   ADC1.DWSEL.reg    = adc1_dwsel;
   ADC1.SQ_FB.reg    = adc1_sq_fb;
   ADC1.STC_0_3.reg  = adc1_stc_0_3;
   ADC1.GLOBCTR.reg  = adc1_globctr;
   ADC1.IE.reg       = adc1_ie;
   ADC1.CTRL_STS.reg = adc1_ctrl_sts;
   return(offset);
}

void CSA_Power_On(void){
   Field_Mod32(&CSA.CTRL.reg, MF_CSA_CTRL_EN_Pos, MF_CSA_CTRL_EN_Msk, 1u);
}

void CSA_Power_Off(void){
   Field_Mod32(&CSA.CTRL.reg, MF_CSA_CTRL_EN_Pos, MF_CSA_CTRL_EN_Msk, 0u);
}

void CSA_Gain_Set(uint32 gain){
   Field_Mod32(&CSA.CTRL.reg, MF_CSA_CTRL_GAIN_Pos, MF_CSA_CTRL_GAIN_Msk, (gain));
}

uint32 CSA_Gain_Get(void){
   return u32_Field_Rd32(&CSA.CTRL.reg, MF_CSA_CTRL_GAIN_Pos, MF_CSA_CTRL_GAIN_Msk);
}
*/

void CSA_Set_Gain(uint8 gain){
   Field_Mod32(&CSA.CTRL.reg, MF_CSA_CTRL_GAIN_Pos, MF_CSA_CTRL_GAIN_Msk, gain);
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

