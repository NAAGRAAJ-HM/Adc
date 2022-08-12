#pragma once
/******************************************************************************/
/* File   : Template.hpp                                                      */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
//#include "tle987x.hpp"
//#include "types.hpp"
//#include "adc2_defines.hpp"
//#include "tle_variants.hpp"
//#include "sfr_access.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define ADC2_VREF (1.211F)
#define ADC2_VREF_mV (1211)
#define ADC2_FILTOUT_MAX (1023u)
#define VS_ATTEN_CONV_NOMIN_MAX28V  (1000u)
#define VS_ATTEN_CONV_DENOM_MAX28V  (39u)
#define VS_ATTEN_CONV_NOMIN_MAX22V  (200u)
#define VS_ATTEN_CONV_DENOM_MAX22V  (11u)
#define VSD_ATTEN_CONV_NOMIN    (1000u)
#define VSD_ATTEN_CONV_DENOM    (39u)
#define VCP_ATTEN_CONV_NOMIN    (1000u)
#define VCP_ATTEN_CONV_DENOM    (23u)
#define MON_ATTEN_CONV_NOMIN    (1000u)
#define MON_ATTEN_CONV_DENOM    (39u)
#define VDDP_ATTEN_CONV_NOMIN   (250u)
#define VDDP_ATTEN_CONV_DENOM   (41u)
#define VAREF_ATTEN_CONV_NOMIN  (1000u)
#define VAREF_ATTEN_CONV_DENOM  (219u)
#define VBG_ATTEN_CONV_NOMIN    (4u)
#define VBG_ATTEN_CONV_DENOM    (3u)
#define VDDC_ATTEN_CONV_NOMIN   (4u)
#define VDDC_ATTEN_CONV_DENOM   (3u)
#define V_TEMP_REF_OFFSET_mV    (666u)
#define V_TEMP_SCALE_FACT   (100u)
#define CONV_COEFF_mV_TO_degC    (231u)
#define ADC2_VBAT       (0)
#define ADC2_VS         (1)
#define ADC2_VSD        (2)
#define ADC2_VCP        (3)
#define ADC2_MON        (4)
#define ADC2_VDDP       (5)
#define ADC2_VAREF      (6)
#define ADC2_VBG        (7)
#define ADC2_VDDC       (8)
#define ADC2_TEMP       (9)
#define ADC2_VBat_Attenuator_Range_3_28V (1u)
#define ADC2_VBat_Attenuator_Range_3_22V (0u)
#define ADC2_VS_Attenuator_Range_3_28V (1u)
#define ADC2_VS_Attenuator_Range_3_22V (0u)

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

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
extern void   ADC2_Init                            (void);
extern void   ADC2_VBat_Attenuator_Range_3_28V_Set (void);
extern void   ADC2_VBat_Attenuator_Range_3_22V_Set (void);
extern uint8  ADC2_VBat_Attenuator_Range_Get       (void);
extern void   ADC2_VS_Attenuator_Range_3_28V_Set   (void);
extern void   ADC2_VS_Attenuator_Range_3_22V_Set   (void);
extern uint8  ADC2_VS_Attenuator_Range_Get         (void);
extern void   ADC2_VS_OV_Int_Clr                   (void);
extern void   ADC2_VS_UV_Int_Clr                   (void);
extern void   ADC2_VDDP_OV_Int_Clr                 (void);
extern void   ADC2_VDDP_UV_Int_Clr                 (void);
extern void   ADC2_VDDC_OV_Int_Clr                 (void);
extern void   ADC2_VDDC_UV_Int_Clr                 (void);
extern void   ADC2_VSD_OV_Int_Clr                  (void);
extern void   ADC2_VSD_UV_Int_Clr                  (void);
extern void   ADC2_VCP_OV_Int_Clr                  (void);
extern void   ADC2_VCP_UV_Int_Clr                  (void);
extern void   ADC2_VBAT_OV_Int_Clr                 (void);
extern void   ADC2_VBAT_UV_Int_Clr                 (void);
extern void   ADC2_MON_OV_Int_Clr                  (void);
extern void   ADC2_MON_UV_Int_Clr                  (void);
extern void   ADC2_VBG_OV_Int_Clr                  (void);
extern void   ADC2_VBG_UV_Int_Clr                  (void);
extern void   ADC2_TEMP_OT_Int_Clr                 (void);
extern void   ADC2_TEMP_WARN_Int_Clr               (void);
extern void   ADC2_VS_OV_Int_En                    (void);
extern void   ADC2_VS_OV_Int_Dis                   (void);
extern void   ADC2_VS_UV_Int_En                    (void);
extern void   ADC2_VS_UV_Int_Dis                   (void);
extern void   ADC2_VDDP_OV_Int_En                  (void);
extern void   ADC2_VDDP_OV_Int_Dis                 (void);
extern void   ADC2_VDDP_UV_Int_En                  (void);
extern void   ADC2_VDDP_UV_Int_Dis                 (void);
extern void   ADC2_VDDC_OV_Int_En                  (void);
extern void   ADC2_VDDC_OV_Int_Dis                 (void);
extern void   ADC2_VDDC_UV_Int_En                  (void);
extern void   ADC2_VDDC_UV_Int_Dis                 (void);
extern void   ADC2_VSD_OV_Int_En                   (void);
extern void   ADC2_VSD_OV_Int_Dis                  (void);
extern void   ADC2_VSD_UV_Int_En                   (void);
extern void   ADC2_VSD_UV_Int_Dis                  (void);
extern void   ADC2_VCP_OV_Int_En                   (void);
extern void   ADC2_VCP_OV_Int_Dis                  (void);
extern void   ADC2_VCP_UV_Int_En                   (void);
extern void   ADC2_VCP_UV_Int_Dis                  (void);
extern void   ADC2_VBAT_OV_Int_En                  (void);
extern void   ADC2_VBAT_OV_Int_Dis                 (void);
extern void   ADC2_VBAT_UV_Int_En                  (void);
extern void   ADC2_VBAT_UV_Int_Dis                 (void);
extern void   ADC2_MON_OV_Int_En                   (void);
extern void   ADC2_MON_OV_Int_Dis                  (void);
extern void   ADC2_MON_UV_Int_En                   (void);
extern void   ADC2_MON_UV_Int_Dis                  (void);
extern void   ADC2_VBG_OV_Int_En                   (void);
extern void   ADC2_VBG_OV_Int_Dis                  (void);
extern void   ADC2_VBG_UV_Int_En                   (void);
extern void   ADC2_VBG_UV_Int_Dis                  (void);
extern void   ADC2_Temp_OT_Int_En                  (void);
extern void   ADC2_Temp_OT_Int_Dis                 (void);
extern void   ADC2_Temp_Warn_Int_En                (void);
extern void   ADC2_Temp_Warn_Int_Dis               (void);
extern uint16 ADC2_GetChResult                     (uint8 channel);
extern uint16 ADC2_VBat_Result_mV                  (void);
extern uint16 ADC2_VS_Result_mV                    (void);
extern uint16 ADC2_VSD_Result_mV                   (void);
extern uint16 ADC2_VCP_Result_mV                   (void);
extern uint16 ADC2_MON_Result_mV                   (void);
extern uint16 ADC2_VDDP_Result_mV                  (void);
extern uint16 ADC2_VAREF_Result_mV                 (void);
extern uint16 ADC2_VBG_Result_mV                   (void);
extern uint16 ADC2_VDDC_Result_mV                  (void);
extern sint16 ADC2_Temp_Result_C                   (void);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

