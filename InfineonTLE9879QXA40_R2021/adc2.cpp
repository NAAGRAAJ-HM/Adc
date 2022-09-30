/******************************************************************************/
/* File   : Template.hpp                                                      */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "types.hpp"

#include "adc2.hpp"

#include "tle987x.hpp"
#include "sfr_access.hpp"

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
ADC2_Type ADC2 = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
void ADC2_Init(void){
#if((ADC2_CTRL2 & 1u) != 0u)
   ADC2->CTRL1.reg = (uint32) ADC2_CTRL1;
   ADC2->CTRL2.reg = (uint32) ADC2_CTRL2;
   ADC2->CTRL4.reg = (uint32) ADC2_CTRL4;
   ADC2->CTRL_STS.reg = (uint32)(ADC2_CTRL_STS | 1u);
   ADC2->TH0_3_LOWER.reg = (uint32) ADC2_TH0_3_LOWER;
   ADC2->TH0_3_UPPER.reg = (uint32) ADC2_TH0_3_UPPER;
   ADC2->TH4_5_LOWER.reg = (uint32) ADC2_TH4_5_LOWER;
   ADC2->TH4_5_UPPER.reg = (uint32) ADC2_TH4_5_UPPER;
   ADC2->TH6_9_LOWER.reg = (uint32) ADC2_TH6_9_LOWER;
   ADC2->FILT_LO_CTRL.reg = ADC2_FILT_LO_CTRL;
   ADC2->FILT_UP_CTRL.reg = ADC2_FILT_UP_CTRL;
   ADC2->FILTCOEFF0_5.reg = (uint32) ADC2_FILTCOEFF0_5;
#if(ADC2_XML_VERSION >= 10300)
   ADC2->CNT0_3_LOWER.reg = (uint32) ADC2_CNT0_3_LOWER;
   ADC2->CNT0_3_UPPER.reg = (uint32) ADC2_CNT0_3_UPPER;
   ADC2->CNT4_5_LOWER.reg = (uint32) ADC2_CNT4_5_LOWER;
   ADC2->CNT4_5_UPPER.reg = (uint32) ADC2_CNT4_5_UPPER;
   ADC2->MMODE0_5.reg = (uint32) ADC2_MMODE0_5;
#endif
#endif
}
/*
#if(UC_SERIES == TLE986)
void ADC2_VBat_Attenuator_Range_3_28V_Set(void){
  Field_Mod32(&ADC2->CTRL_STS.reg, ADC2_CTRL_STS_VBAT_RANGE_Pos, ADC2_CTRL_STS_VBAT_RANGE_Msk, 1u);
}

void ADC2_VBat_Attenuator_Range_3_22V_Set(void){
  Field_Mod32(&ADC2->CTRL_STS.reg, ADC2_CTRL_STS_VBAT_RANGE_Pos, ADC2_CTRL_STS_VBAT_RANGE_Msk, 0u);
}

uint8 ADC2_VBat_Attenuator_Range_Get(void){
   return( u8_Field_Rd32(&ADC2->CTRL_STS.reg, ADC2_CTRL_STS_VBAT_RANGE_Pos, ADC2_CTRL_STS_VBAT_RANGE_Msk) );
}
#endif

void ADC2_VS_Attenuator_Range_3_28V_Set(void){
  Field_Mod32(&ADC2->CTRL_STS.reg, ADC2_CTRL_STS_VS_RANGE_Pos, ADC2_CTRL_STS_VS_RANGE_Msk, 1u);
}

void ADC2_VS_Attenuator_Range_3_22V_Set(void){
  Field_Mod32(&ADC2->CTRL_STS.reg, ADC2_CTRL_STS_VS_RANGE_Pos, ADC2_CTRL_STS_VS_RANGE_Msk, 0u);
}

uint8 ADC2_VS_Attenuator_Range_Get(void){
   return( u8_Field_Rd32(&ADC2->CTRL_STS.reg, ADC2_CTRL_STS_VS_RANGE_Pos, ADC2_CTRL_STS_VS_RANGE_Msk) );
}

void ADC2_VS_OV_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_SUPPLY_IRQ_CLR.reg, SCUPM_SYS_SUPPLY_IRQ_CLR_VS_OV_ICLR_Pos, SCUPM_SYS_SUPPLY_IRQ_CLR_VS_OV_ICLR_Msk, 1u);
}

void ADC2_VS_UV_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_SUPPLY_IRQ_CLR.reg, SCUPM_SYS_SUPPLY_IRQ_CLR_VS_UV_ICLR_Pos, SCUPM_SYS_SUPPLY_IRQ_CLR_VS_UV_ICLR_Msk, 1u);
}

void ADC2_VDDP_OV_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_SUPPLY_IRQ_CLR.reg, SCUPM_SYS_SUPPLY_IRQ_CLR_VDD5V_OV_ICLR_Pos, SCUPM_SYS_SUPPLY_IRQ_CLR_VDD5V_OV_ICLR_Msk, 1u);
}

void ADC2_VDDP_UV_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_SUPPLY_IRQ_CLR.reg, SCUPM_SYS_SUPPLY_IRQ_CLR_VDD5V_UV_ICLR_Pos, SCUPM_SYS_SUPPLY_IRQ_CLR_VDD5V_UV_ICLR_Msk, 1u);
}

void ADC2_VDDC_OV_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_SUPPLY_IRQ_CLR.reg, SCUPM_SYS_SUPPLY_IRQ_CLR_VDD1V5_OV_ICLR_Pos, SCUPM_SYS_SUPPLY_IRQ_CLR_VDD1V5_OV_ICLR_Msk, 1u);
}

void ADC2_VDDC_UV_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_SUPPLY_IRQ_CLR.reg, SCUPM_SYS_SUPPLY_IRQ_CLR_VDD1V5_UV_ICLR_Pos, SCUPM_SYS_SUPPLY_IRQ_CLR_VDD1V5_UV_ICLR_Msk, 1u);
}

void ADC2_VSD_OV_Int_Clr(void){
  Field_Wrt32(&SCUPM.BDRV_ISCLR.reg, SCUPM_BDRV_ISCLR_VSD_UPTH_ICLR_Pos, SCUPM_BDRV_ISCLR_VSD_UPTH_ICLR_Msk, 1u);
}

void ADC2_VSD_UV_Int_Clr(void){
  Field_Wrt32(&SCUPM.BDRV_ISCLR.reg, SCUPM_BDRV_ISCLR_VSD_LOWTH_ICLR_Pos, SCUPM_BDRV_ISCLR_VSD_LOWTH_ICLR_Msk, 1u);
}

void ADC2_VCP_OV_Int_Clr(void){
  Field_Wrt32(&SCUPM.BDRV_ISCLR.reg, SCUPM_BDRV_ISCLR_VCP_UPTH_ICLR_Pos, SCUPM_BDRV_ISCLR_VCP_UPTH_ICLR_Msk, 1u);
}

void ADC2_VCP_UV_Int_Clr(void){
  Field_Wrt32(&SCUPM.BDRV_ISCLR.reg, SCUPM_BDRV_ISCLR_VCP_LOWTH1_ICLR_Pos, SCUPM_BDRV_ISCLR_VCP_LOWTH1_ICLR_Msk, 1u);
}

#if(UC_SERIES == TLE986)
void ADC2_VBAT_OV_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_SUPPLY_IRQ_CLR.reg, SCUPM_SYS_SUPPLY_IRQ_CLR_VBAT_OV_ICLR_Pos, SCUPM_SYS_SUPPLY_IRQ_CLR_VBAT_OV_ICLR_Msk, 1u);
}

void ADC2_VBAT_UV_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_SUPPLY_IRQ_CLR.reg, SCUPM_SYS_SUPPLY_IRQ_CLR_VBAT_UV_ICLR_Pos, SCUPM_SYS_SUPPLY_IRQ_CLR_VBAT_UV_ICLR_Msk, 1u);
}
#endif

#if(UC_SERIES == TLE987)
void ADC2_MON_OV_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_SUPPLY_IRQ_CLR.reg, SCUPM_SYS_SUPPLY_IRQ_CLR_MON_OV_ICLR_Pos, SCUPM_SYS_SUPPLY_IRQ_CLR_MON_OV_ICLR_Msk, 1u);
}

void ADC2_MON_UV_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_SUPPLY_IRQ_CLR.reg, SCUPM_SYS_SUPPLY_IRQ_CLR_MON_UV_ICLR_Pos, SCUPM_SYS_SUPPLY_IRQ_CLR_MON_UV_ICLR_Msk, 1u);
}
#endif

void ADC2_VBG_OV_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_ISCLR.reg, SCUPM_SYS_ISCLR_REFBG_UPTHWARN_ICLR_Pos, SCUPM_SYS_ISCLR_REFBG_UPTHWARN_ICLR_Msk, 1u);
}

void ADC2_VBG_UV_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_ISCLR.reg, SCUPM_SYS_ISCLR_REFBG_LOTHWARN_ICLR_Pos, SCUPM_SYS_ISCLR_REFBG_LOTHWARN_ICLR_Msk, 1u);
}

#if((ADC2_CTRL2 &(1u << 2u)) == 0u)
void ADC2_TEMP_OT_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_ISCLR.reg, SCUPM_SYS_ISCLR_SYS_OT_ICLR_Pos, SCUPM_SYS_ISCLR_SYS_OT_ICLR_Msk, 1u);
}

void ADC2_TEMP_WARN_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_ISCLR.reg, SCUPM_SYS_ISCLR_SYS_OTWARN_ICLR_Pos, SCUPM_SYS_ISCLR_SYS_OTWARN_ICLR_Msk, 1u);
}
#else
void ADC2_TEMP_OT_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_ISCLR.reg, SCUPM_SYS_ISCLR_PMU_OT_ICLR_Pos, SCUPM_SYS_ISCLR_PMU_OT_ICLR_Msk, 1u);
}

void ADC2_TEMP_WARN_Int_Clr(void){
  Field_Wrt32(&SCUPM.SYS_ISCLR.reg, SCUPM_SYS_ISCLR_PMU_OTWARN_ICLR_Pos, SCUPM_SYS_ISCLR_PMU_OTWARN_ICLR_Msk, 1u);
}
#endif

void ADC2_VS_OV_Int_En(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VS_OV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VS_OV_IE_Msk, 1u);
}

void ADC2_VS_OV_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VS_OV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VS_OV_IE_Msk, 0u);
}

void ADC2_VS_UV_Int_En(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VS_UV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VS_UV_IE_Msk, 1u);
}

void ADC2_VS_UV_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VS_UV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VS_UV_IE_Msk, 0u);
}

void ADC2_VDDP_OV_Int_En(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD5V_OV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD5V_OV_IE_Msk, 1u);
}

void ADC2_VDDP_OV_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD5V_OV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD5V_OV_IE_Msk, 0u);
}

void ADC2_VDDP_UV_Int_En(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD5V_UV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD5V_UV_IE_Msk, 1u);
}

void ADC2_VDDP_UV_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD5V_UV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD5V_UV_IE_Msk, 0u);
}

void ADC2_VDDC_OV_Int_En(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD1V5_OV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD1V5_OV_IE_Msk, 1u);
}

void ADC2_VDDC_OV_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD1V5_OV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD1V5_OV_IE_Msk, 0u);
}

void ADC2_VDDC_UV_Int_En(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD1V5_UV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD1V5_UV_IE_Msk, 1u);
}

void ADC2_VDDC_UV_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD1V5_UV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD1V5_UV_IE_Msk, 0u);
}

void ADC2_VSD_OV_Int_En(void){
  Field_Mod32(&SCUPM.BDRV_IRQ_CTRL.reg, SCUPM_BDRV_IRQ_CTRL_VSD_UPTH_IE_Pos, SCUPM_BDRV_IRQ_CTRL_VSD_UPTH_IE_Msk, 1u);
}

void ADC2_VSD_OV_Int_Dis(void){
  Field_Mod32(&SCUPM.BDRV_IRQ_CTRL.reg, SCUPM_BDRV_IRQ_CTRL_VSD_UPTH_IE_Pos, SCUPM_BDRV_IRQ_CTRL_VSD_UPTH_IE_Msk, 0u);
}

void ADC2_VSD_UV_Int_En(void){
  Field_Mod32(&SCUPM.BDRV_IRQ_CTRL.reg, SCUPM_BDRV_IRQ_CTRL_VSD_LOWTH_IE_Pos, SCUPM_BDRV_IRQ_CTRL_VSD_LOWTH_IE_Msk, 1u);
}

void ADC2_VSD_UV_Int_Dis(void){
  Field_Mod32(&SCUPM.BDRV_IRQ_CTRL.reg, SCUPM_BDRV_IRQ_CTRL_VSD_LOWTH_IE_Pos, SCUPM_BDRV_IRQ_CTRL_VSD_LOWTH_IE_Msk, 0u);
}

void ADC2_VCP_OV_Int_En(void){
  Field_Mod32(&SCUPM.BDRV_IRQ_CTRL.reg, SCUPM_BDRV_IRQ_CTRL_VCP_UPTH_IE_Pos, SCUPM_BDRV_IRQ_CTRL_VCP_UPTH_IE_Msk, 1u);
}

void ADC2_VCP_OV_Int_Dis(void){
  Field_Mod32(&SCUPM.BDRV_IRQ_CTRL.reg, SCUPM_BDRV_IRQ_CTRL_VCP_UPTH_IE_Pos, SCUPM_BDRV_IRQ_CTRL_VCP_UPTH_IE_Msk, 0u);
}

void ADC2_VCP_UV_Int_En(void){
  Field_Mod32(&SCUPM.BDRV_IRQ_CTRL.reg, SCUPM_BDRV_IRQ_CTRL_VCP_LOWTH1_IE_Pos, SCUPM_BDRV_IRQ_CTRL_VCP_LOWTH1_IE_Msk, 1u);
}

void ADC2_VCP_UV_Int_Dis(void){
  Field_Mod32(&SCUPM.BDRV_IRQ_CTRL.reg, SCUPM_BDRV_IRQ_CTRL_VCP_LOWTH1_IE_Pos, SCUPM_BDRV_IRQ_CTRL_VCP_LOWTH1_IE_Msk, 0u);
}

#if(UC_SERIES == TLE986)
void ADC2_VBAT_OV_Int_En(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VBAT_OV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VBAT_OV_IE_Msk, 1u);
}

void ADC2_VBAT_OV_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VBAT_OV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VBAT_OV_IE_Msk, 0u);
}

void ADC2_VBAT_UV_Int_En(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VBAT_UV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VBAT_UV_IE_Msk, 1u);
}

void ADC2_VBAT_UV_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_VBAT_UV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_VBAT_UV_IE_Msk, 0u);
}
#endif

#if(UC_SERIES == TLE987)
void ADC2_MON_OV_Int_En(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_MON_OV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_MON_OV_IE_Msk, 1u);
}

void ADC2_MON_OV_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_MON_OV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_MON_OV_IE_Msk, 0u);
}

void ADC2_MON_UV_Int_En(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_MON_UV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_MON_UV_IE_Msk, 1u);
}

void ADC2_MON_UV_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_SUPPLY_IRQ_CTRL.reg, SCUPM_SYS_SUPPLY_IRQ_CTRL_MON_UV_IE_Pos, SCUPM_SYS_SUPPLY_IRQ_CTRL_MON_UV_IE_Msk, 0u);
}
#endif

void ADC2_VBG_OV_Int_En(void){
  Field_Mod32(&SCUPM.SYS_IRQ_CTRL.reg, SCUPM_SYS_IRQ_CTRL_REFBG_UPTHWARN_IE_Pos, SCUPM_SYS_IRQ_CTRL_REFBG_UPTHWARN_IE_Msk, 1u);
}

void ADC2_VBG_OV_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_IRQ_CTRL.reg, SCUPM_SYS_IRQ_CTRL_REFBG_UPTHWARN_IE_Pos, SCUPM_SYS_IRQ_CTRL_REFBG_UPTHWARN_IE_Msk, 0u);
}

void ADC2_VBG_UV_Int_En(void){
  Field_Mod32(&SCUPM.SYS_IRQ_CTRL.reg, SCUPM_SYS_IRQ_CTRL_REFBG_LOTHWARN_IE_Pos, SCUPM_SYS_IRQ_CTRL_REFBG_LOTHWARN_IE_Msk, 1u);
}

void ADC2_VBG_UV_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_IRQ_CTRL.reg, SCUPM_SYS_IRQ_CTRL_REFBG_LOTHWARN_IE_Pos, SCUPM_SYS_IRQ_CTRL_REFBG_LOTHWARN_IE_Msk, 0u);
}

#if((ADC2_CTRL2 &(1u << 2u)) == 0u)
void ADC2_Temp_OT_Int_En(void){
  Field_Mod32(&SCUPM.SYS_IRQ_CTRL.reg, SCUPM_SYS_IRQ_CTRL_SYS_OT_IE_Pos, SCUPM_SYS_IRQ_CTRL_SYS_OT_IE_Msk, 1u);
}

void ADC2_Temp_OT_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_IRQ_CTRL.reg, SCUPM_SYS_IRQ_CTRL_SYS_OT_IE_Pos, SCUPM_SYS_IRQ_CTRL_SYS_OT_IE_Msk, 0u);
}

void ADC2_Temp_Warn_Int_En(void){
  Field_Mod32(&SCUPM.SYS_IRQ_CTRL.reg, SCUPM_SYS_IRQ_CTRL_SYS_OTWARN_IE_Pos, SCUPM_SYS_IRQ_CTRL_SYS_OTWARN_IE_Msk, 1u);
}

void ADC2_Temp_Warn_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_IRQ_CTRL.reg, SCUPM_SYS_IRQ_CTRL_SYS_OTWARN_IE_Pos, SCUPM_SYS_IRQ_CTRL_SYS_OTWARN_IE_Msk, 0u);
}
#else
void ADC2_Temp_OT_Int_En(void){
  Field_Mod32(&SCUPM.SYS_IRQ_CTRL.reg, SCUPM_SYS_IRQ_CTRL_PMU_OT_IE_Pos, SCUPM_SYS_IRQ_CTRL_PMU_OT_IE_Msk, 1u);
}

void ADC2_Temp_OT_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_IRQ_CTRL.reg, SCUPM_SYS_IRQ_CTRL_PMU_OT_IE_Pos, SCUPM_SYS_IRQ_CTRL_PMU_OT_IE_Msk, 0u);
}

void ADC2_Temp_Warn_Int_En(void){
  Field_Mod32(&SCUPM.SYS_IRQ_CTRL.reg, SCUPM_SYS_IRQ_CTRL_PMU_OTWARN_IE_Pos, SCUPM_SYS_IRQ_CTRL_PMU_OTWARN_IE_Msk, 1u);
}

void ADC2_Temp_Warn_Int_Dis(void){
  Field_Mod32(&SCUPM.SYS_IRQ_CTRL.reg, SCUPM_SYS_IRQ_CTRL_PMU_OTWARN_IE_Pos, SCUPM_SYS_IRQ_CTRL_PMU_OTWARN_IE_Msk, 0u);
}
#endif

uint16 ADC2_GetChResult(uint8 channel){
   const uint32 *pBaseAddr;
   uint16 Var;
   uint32* addr;
   uint16 idx;
   if((uint8)ADC2_TEMP >= channel){
      addr = &ADC2->FILT_OUT0.reg;
      idx = (uint16)((uint16)channel << 2u);
      addr += idx;
      pBaseAddr = (uint32*) addr;
      Var = (uint16)((*pBaseAddr) & (uint32)0x000003FF);
   }
   else{
      Var = 0;
   }
   return(Var);
}
#if(UC_SERIES == TLE986)
uint16 ADC2_VBat_Result_mV(void){
  uint16 value;
  value = ADC2_GetChResult(ADC2_VBAT);
  if(ADC2_VBat_Attenuator_Range_Get() == ADC2_VS_Attenuator_Range_3_28V){
    value = (uint16)(((value * ((uint32)ADC2_VREF_mV * (uint16)VS_ATTEN_CONV_NOMIN_MAX28V)) / (uint16)ADC2_FILTOUT_MAX) / (uint8)VS_ATTEN_CONV_DENOM_MAX28V);
  }
  else{
    value = (uint16)(((value * ((uint32)ADC2_VREF_mV * (uint16)VS_ATTEN_CONV_NOMIN_MAX22V)) / (uint16)ADC2_FILTOUT_MAX) / (uint8)VS_ATTEN_CONV_DENOM_MAX22V);
  }

   return(value);
}
#endif

uint16 ADC2_VS_Result_mV(void){
  uint16 value;
  value = ADC2_GetChResult(ADC2_VS);
  if(ADC2_VS_Attenuator_Range_Get() == ADC2_VS_Attenuator_Range_3_28V){
    value = (uint16)(((value * (uint32)((uint16)ADC2_VREF_mV * (uint16)VS_ATTEN_CONV_NOMIN_MAX28V)) / (uint16)ADC2_FILTOUT_MAX) / (uint8)VS_ATTEN_CONV_DENOM_MAX28V);
  }
  else{
    value = (uint16)(((value * (uint32)((uint16)ADC2_VREF_mV * (uint16)VS_ATTEN_CONV_NOMIN_MAX22V)) / (uint16)ADC2_FILTOUT_MAX) / (uint8)VS_ATTEN_CONV_DENOM_MAX22V);
  }

   return(value);
}

uint16 ADC2_VSD_Result_mV(void){
  uint16 value;
  value = ADC2_GetChResult(ADC2_VSD);
  value = (uint16)(((value * (uint32)((uint16)ADC2_VREF_mV * (uint16)VSD_ATTEN_CONV_NOMIN)) / (uint16)ADC2_FILTOUT_MAX) / (uint8)VSD_ATTEN_CONV_DENOM);
   return(value);
}

uint16 ADC2_VCP_Result_mV(void){
  uint16 value;
  value = ADC2_GetChResult((uint8)ADC2_VCP);
  value = (uint16)(((value * ((uint32)ADC2_VREF_mV * (uint16)VCP_ATTEN_CONV_NOMIN)) / (uint16)ADC2_FILTOUT_MAX) / (uint8)VCP_ATTEN_CONV_DENOM);
   return(value);
}

uint16 ADC2_MON_Result_mV(void){
  uint16 value;
  value = ADC2_GetChResult((uint8)ADC2_MON);
  value = (uint16)(((value * ((uint32)ADC2_VREF_mV * (uint16)MON_ATTEN_CONV_NOMIN)) / (uint16)ADC2_FILTOUT_MAX) / (uint8)MON_ATTEN_CONV_DENOM);
   return(value);
}

uint16 ADC2_VDDP_Result_mV(void){
  uint16 value;
  value = ADC2_GetChResult((uint8)ADC2_VDDP);
  value = (uint16)(((value * ((uint32)ADC2_VREF_mV * (uint16)VDDP_ATTEN_CONV_NOMIN)) / (uint16)ADC2_FILTOUT_MAX) / (uint8)VDDP_ATTEN_CONV_DENOM);
   return(value);
}

uint16 ADC2_VAREF_Result_mV(void){
  uint16 value;
  value = ADC2_GetChResult((uint8)ADC2_VAREF);
  value = (uint16)(((value * ((uint32)ADC2_VREF_mV * (uint16)VAREF_ATTEN_CONV_NOMIN)) / (uint16)ADC2_FILTOUT_MAX) / (uint8)VAREF_ATTEN_CONV_DENOM);
   return(value);
}

uint16 ADC2_VBG_Result_mV(void){
  uint16 value;
  value = ADC2_GetChResult((uint8)ADC2_VBG);
  value = (uint16)(((value * ((uint32)ADC2_VREF_mV * (uint16)VBG_ATTEN_CONV_NOMIN)) / (uint16)ADC2_FILTOUT_MAX) / (uint8)VBG_ATTEN_CONV_DENOM);
   return(value);
}

uint16 ADC2_VDDC_Result_mV(void){
  uint16 value;
  value = ADC2_GetChResult((uint8)ADC2_VDDC);
  value = (uint16)(((value * ((uint32)ADC2_VREF_mV * (uint16)VDDC_ATTEN_CONV_NOMIN)) / (uint16)ADC2_FILTOUT_MAX) / (uint8)VDDC_ATTEN_CONV_DENOM);
   return(value);
}

sint16 ADC2_Temp_Result_C(void){
  uint16 value;
  uint16 V_Temp_mV;
  sint16 Temperature;
  value = ADC2_GetChResult((uint8)ADC2_TEMP);
  V_Temp_mV = (uint16)(((uint32)value * (uint32)ADC2_VREF_mV) / (uint16)1023);
  Temperature = (sint16)((((sint16)V_Temp_mV - (sint16)V_TEMP_REF_OFFSET_mV) * (sint16)V_TEMP_SCALE_FACT) / (sint16)CONV_COEFF_mV_TO_degC);
   return(Temperature);
}
*/
/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

