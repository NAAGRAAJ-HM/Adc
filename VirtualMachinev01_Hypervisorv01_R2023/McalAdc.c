/******************************************************************************/
/* File   : McalAdc.c                                                         */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.h"

#include "CfgMcalAdc.h"
#include "infMcalAdcSwcApplDem.h"
#include "infMcalAdcSwcApplOs.h"
#include "infMcalAdcSwcServiceEcuM.h"
#include "LibAutosar_MovingAverage.h"
#include "uC_Adc.h"

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
static LibAutosar_typeContextMovingAverage stContextChannel2;
static uint16 McalAdc_lau16BufferChannel2[CfgMcalAdc_cLenBufferChannel2];

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
static void AP2_vInit(void){
   APM0 |= 1u << 2;
}

static void ADC_vInitChannel2(void){
   ADCA0VCR02   = CfgMcalAdc_cADCA0VCR02; //TBD: Optimization possible?
   ADCA0ADCR    = CfgMcalAdc_cADCA0ADCR;
   ADCA0SMPCR   = CfgMcalAdc_cADCA0SMPCR;
   ADCA0SFTCR   = CfgMcalAdc_cADCA0SFTCR;
   ADCA0SGCR1   = CfgMcalAdc_cADCA0SGCR1;
   ADCA0SGVCSP1 = CfgMcalAdc_cADCA0SGVCSP1;
   ADCA0SGVCEP1 = CfgMcalAdc_cADCA0SGVCEP1;
   LibAutosarInitMovingAverage(
         &stContextChannel2
      ,  &McalAdc_lau16BufferChannel2[0]
      ,  CfgMcalAdc_cLenBufferChannel2
   );
}

static void ADC_vInterruptSG1(uint8 u8SetMKP){
   TBADCA0I0 = 1;
   RFADCA0I0 = 0;
   if(1 == u8SetMKP){MKADCA0I0 = 0;}
   else             {MKADCA0I0 = 1;}
}

FUNC(void, MCALADC_CODE) infMcalAdcSwcServiceEcuM_vInitFunction(void){
   AP2_vInit();
   ADC_vInitChannel2();
   ADC_vInterruptSG1(0);
}

FUNC(void, MCALADC_CODE) infMcalAdcSwcApplOs_vRunnableConversionStartSG1(void){
   ADCA0SGSTCR1 = 1u;
}

FUNC(void, MCALADC_CODE) infMcalAdcSwcApplOs_vRunnableConversionCompleteChannel2(void){
   uint16 lu16AdConversionValue = (uint16)ADCA0DIR02 & CfgMcalAdc_cMaskBits16;
   uint16 lu16VoltageBattery = (
         lu16AdConversionValue * CfgMcalAdc_cValueGain_mV
      +  CfgMcalAdc_cValueCompensationErrorNonLinearityDiodeDS3
      +  CfgMcalAdc_cValueCompensationErrorRounding
   )
   / 106;
   LibAutosarCalcMovingAverage(//TBD: Move to IoHwAb
         &stContextChannel2
      ,  lu16VoltageBattery
   );
   if(CfgMcalAdc_cValueMaxDefault < stContextChannel2.u16MovingAverage){
      stContextChannel2.u16MovingAverage = CfgMcalAdc_cValueMaxDefault;
   }
}

FUNC(uint8, MCALADC_CODE) infMcalAdcSwcApplDem_u8GetVoltageKl30(void){//TBD: Move to Rte ==> IoHwAb
   return (uint8)stContextChannel2.u16MovingAverage;
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

