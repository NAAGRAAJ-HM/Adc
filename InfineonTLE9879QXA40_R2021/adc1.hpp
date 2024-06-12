#pragma once
/******************************************************************************/
/* File   : Template.hpp                                                      */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define ADC1_VDH_Attenuator_Range_0_30V                                     (1u)
#define ADC1_VDH_Attenuator_Range_0_20V                                     (0u)
#define SW_MODE                                                               0u
#define SEQ_MODE                                                              1u
#define SKIP                                                                  0u
#define MEAS                                                                  1u
#define BIT10                                                                 0u
#define BIT8                                                                  1u
#define INTDIS                                                                0u
#define INTEN                                                                 1u
#define OVERWRITE                                                             0u
#define WFR                                                                   1u
#define ADC1_CH0                                                             (0)
#define ADC1_CH1                                                             (1)
#define ADC1_CH2                                                             (2)
#define ADC1_CH3                                                             (3)
#define ADC1_CH4                                                             (4)
#define ADC1_CH5                                                             (5)
#define ADC1_CH6                                                             (6)
#define ADC1_EIM                                                             (8)
#define ADC1_P20                                                        ADC1_CH0
#define ADC1_CSA                                                        ADC1_CH1
#define ADC1_P22                                                        ADC1_CH2
#define ADC1_P23                                                        ADC1_CH3
#define ADC1_P24                                                        ADC1_CH4
#define ADC1_P25                                                        ADC1_CH5
#define ADC1_VDH                                                        ADC1_CH6
#define ADC1_MASK_CH0                                   ((uint32)1u << ADC1_CH0)
#define ADC1_MASK_CH1                                   ((uint32)1u << ADC1_CH1)
#define ADC1_MASK_CH2                                   ((uint32)1u << ADC1_CH2)
#define ADC1_MASK_CH3                                   ((uint32)1u << ADC1_CH3)
#define ADC1_MASK_CH4                                   ((uint32)1u << ADC1_CH4)
#define ADC1_MASK_CH5                                   ((uint32)1u << ADC1_CH5)
#define ADC1_MASK_CH6                                   ((uint32)1u << ADC1_CH6)
#define ADC1_MASK_P20                                            (ADC1_MASK_CH0)
#define ADC1_MASK_CSA                                            (ADC1_MASK_CH1)
#define ADC1_MASK_P22                                            (ADC1_MASK_CH2)
#define ADC1_MASK_P23                                            (ADC1_MASK_CH3)
#define ADC1_MASK_P24                                            (ADC1_MASK_CH4)
#define ADC1_MASK_P25                                            (ADC1_MASK_CH5)
#define ADC1_MASK_VDH                                            (ADC1_MASK_CH6)
#define ADC1_VREF_5000mV                                                   5000u
#define ADC1_VREF_22000mV                                                 22000u
#define ADC1_VREF_30000mV                                                 30000u

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef enum{
      ADC1_ANON_OFF       = 0
   ,  ADC1_ANON_S_STANDBY = 1
   ,  ADC1_ANON_F_STANDBY = 2
   ,  ADC1_ANON_NORMAL    = 3
}TADC1_ANON;

typedef union{
  uint32 dword;
  TADC1_ANON  adc1_anon;
}TADC1_ANON_U;

typedef enum{
      ADC1_Trigg_None      = 0
   ,  ADC1_Trigg_CCU6_Ch3  = 1
   ,  ADC1_Trigg_GPT12E_T6 = 2
   ,  ADC1_Trigg_GPT12E_T3 = 3
   ,  ADC1_Trigg_Timer2    = 4
   ,  ADC1_Trigg_Timer21   = 5
   ,  ADC1_Trigg_Timer3    = 6
}TADC1_TRIGG_SEL;

typedef enum{
      ADC1_1_Meas   = 0
   ,  ADC1_2_Meas   = 1
   ,  ADC1_4_Meas   = 2
   ,  ADC1_8_Meas   = 3
   ,  ADC1_16_Meas  = 4
   ,  ADC1_32_Meas  = 5
   ,  ADC1_64_Meas  = 6
   ,  ADC1_128_Meas = 7
}TADC1_EIM_REP_CNT;

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
extern void       ADC1_Init                           (void);
extern bool       VAREF_Enable                        (void);
extern bool       ADC1_GetChResult                    (uint16 *pVar, uint8 channel);
extern bool       ADC1_GetChResult_mV                 (uint16 *pVar_mV, uint8 channel);
extern bool       ADC1_GetEIMResult                   (uint16 *pVar);
extern bool       ADC1_GetEIMResult_mV                (uint16 *pVar_mV);
extern void       ADC1_Power_On                       (void);
extern void       ADC1_Power_Off                      (void);
extern void       ADC1_SOC_Set                        (void);
extern void       ADC1_SW_Ch_Sel                      (uint32 a);
extern void       ADC1_DIVA_Set                       (uint32 a);
extern void       ADC1_ANON_Set                       (uint32 a);
extern void       ADC1_Sequencer_Mode_Sel             (void);
extern void       ADC1_Software_Mode_Sel              (void);
extern uint8      ADC1_EOC_Sts                        (void);
extern uint8      ADC1_Current_Ch_Sts                 (void);
extern uint8      ADC1_Sample_Sts                     (void);
extern uint8      ADC1_Busy_Sts                       (void);
extern uint8      ADC1_EIM_Active_Sts                 (void);
extern uint8      ADC1_ESM_Active_Sts                 (void);
extern uint8      ADC1_Current_Active_Sequence_Sts    (void);
extern uint8      ADC1_Current_Active_Channel_Sts     (void);
extern void       ADC1_Sequence0_Set                  (uint32 mask_ch);
extern void       ADC1_Sequence1_Set                  (uint32 mask_ch);
extern void       ADC1_Sequence2_Set                  (uint32 mask_ch);
extern void       ADC1_Sequence3_Set                  (uint32 mask_ch);
extern void       ADC1_Sequence4_Set                  (uint32 mask_ch);
extern void       ADC1_Sequence5_Set                  (uint32 mask_ch);
extern void       ADC1_Sequence6_Set                  (uint32 mask_ch);
extern void       ADC1_Sequence7_Set                  (uint32 mask_ch);
extern uint16     ADC1_Ch0_Result_Get                 (void);
extern uint16     ADC1_Ch1_Result_Get                 (void);
extern uint16     ADC1_Ch2_Result_Get                 (void);
extern uint16     ADC1_Ch3_Result_Get                 (void);
extern uint16     ADC1_Ch4_Result_Get                 (void);
extern uint16     ADC1_Ch5_Result_Get                 (void);
extern uint16     ADC1_Ch6_Result_Get                 (void);
extern uint16     ADC1_EIM_Result_Get                 (void);
extern uint16     ADC1_P20_Result_Get                 (void);
extern uint16     ADC1_CSA_Result_Get                 (void);
extern uint16     ADC1_P22_Result_Get                 (void);
extern uint16     ADC1_P23_Result_Get                 (void);
extern uint16     ADC1_P24_Result_Get                 (void);
extern uint16     ADC1_P25_Result_Get                 (void);
extern uint16     ADC1_VDH_Result_Get                 (void);
extern uint8      ADC1_Ch0_ResultValid_Get            (void);
extern uint8      ADC1_Ch1_ResultValid_Get            (void);
extern uint8      ADC1_Ch2_ResultValid_Get            (void);
extern uint8      ADC1_Ch3_ResultValid_Get            (void);
extern uint8      ADC1_Ch5_ResultValid_Get            (void);
extern uint8      ADC1_Ch6_ResultValid_Get            (void);
extern uint8      ADC1_EIM_ResultValid_Get            (void);
extern void       ADC1_Ch0_DataWidth_8bit_Set         (void);
extern void       ADC1_Ch0_DataWidth_10bit_Set        (void);
extern void       ADC1_Ch1_DataWidth_8bit_Set         (void);
extern void       ADC1_Ch1_DataWidth_10bit_Set        (void);
extern void       ADC1_Ch2_DataWidth_8bit_Set         (void);
extern void       ADC1_Ch2_DataWidth_10bit_Set        (void);
extern void       ADC1_Ch3_DataWidth_8bit_Set         (void);
extern void       ADC1_Ch3_DataWidth_10bit_Set        (void);
extern void       ADC1_Ch4_DataWidth_8bit_Set         (void);
extern void       ADC1_Ch4_DataWidth_10bit_Set        (void);
extern void       ADC1_Ch5_DataWidth_8bit_Set         (void);
extern void       ADC1_Ch5_DataWidth_10bit_Set        (void);
extern void       ADC1_Ch6_DataWidth_8bit_Set         (void);
extern void       ADC1_Ch6_DataWidth_10bit_Set        (void);
extern void       ADC1_Ch0_Sample_Time_Set            (uint32 stc);
extern void       ADC1_Ch1_Sample_Time_Set            (uint32 stc);
extern void       ADC1_Ch2_Sample_Time_Set            (uint32 stc);
extern void       ADC1_Ch3_Sample_Time_Set            (uint32 stc);
extern void       ADC1_Ch4_Sample_Time_Set            (uint32 stc);
extern void       ADC1_Ch5_Sample_Time_Set            (uint32 stc);
extern void       ADC1_Ch6_Sample_Time_Set            (uint32 stc);
extern void       ADC1_Ch0_WaitForRead_Set            (void);
extern void       ADC1_Ch0_Overwrite_Set              (void);
extern void       ADC1_Ch1_WaitForRead_Set            (void);
extern void       ADC1_Ch1_Overwrite_Set              (void);
extern void       ADC1_Ch2_WaitForRead_Set            (void);
extern void       ADC1_Ch2_Overwrite_Set              (void);
extern void       ADC1_Ch3_WaitForRead_Set            (void);
extern void       ADC1_Ch3_Overwrite_Set              (void);
extern void       ADC1_Ch4_WaitForRead_Set            (void);
extern void       ADC1_Ch4_Overwrite_Set              (void);
extern void       ADC1_Ch5_WaitForRead_Set            (void);
extern void       ADC1_Ch5_Overwrite_Set              (void);
extern void       ADC1_Ch6_WaitForRead_Set            (void);
extern void       ADC1_Ch6_Overwrite_Set              (void);
extern void       ADC1_EIM_Channel_Set                (uint32 ch);
extern void       ADC1_ESM_Channel_Set                (uint32 mask_ch);
extern void       ADC1_VDH_Attenuator_On              (void);
extern void       ADC1_VDH_Attenuator_Off             (void);
extern void       ADC1_VDH_Attenuator_Zhigh_Set       (void);
extern void       ADC1_VDH_Attenuator_Zlow_Set        (void);
extern void       ADC1_Ch0_Int_Clr                    (void);
extern void       ADC1_Ch1_Int_Clr                    (void);
extern void       ADC1_Ch2_Int_Clr                    (void);
extern void       ADC1_Ch3_Int_Clr                    (void);
extern void       ADC1_Ch4_Int_Clr                    (void);
extern void       ADC1_Ch5_Int_Clr                    (void);
extern void       ADC1_Ch6_Int_Clr                    (void);
extern void       ADC1_EIM_Int_Clr                    (void);
extern void       ADC1_ESM_Int_Clr                    (void);
extern void       ADC1_Ch0_Int_En                     (void);
extern void       ADC1_Ch0_Int_Dis                    (void);
extern void       ADC1_Ch1_Int_En                     (void);
extern void       ADC1_Ch1_Int_Dis                    (void);
extern void       ADC1_Ch2_Int_En                     (void);
extern void       ADC1_Ch2_Int_Dis                    (void);
extern void       ADC1_Ch3_Int_En                     (void);
extern void       ADC1_Ch3_Int_Dis                    (void);
extern void       ADC1_Ch4_Int_En                     (void);
extern void       ADC1_Ch4_Int_Dis                    (void);
extern void       ADC1_Ch5_Int_En                     (void);
extern void       ADC1_Ch5_Int_Dis                    (void);
extern void       ADC1_Ch6_Int_En                     (void);
extern void       ADC1_Ch6_Int_Dis                    (void);
extern void       ADC1_EIM_Int_En                     (void);
extern void       ADC1_EIM_Int_Dis                    (void);
extern void       ADC1_ESM_Int_En                     (void);
extern void       ADC1_ESM_Int_Dis                    (void);
extern void       ADC1_VDH_Attenuator_Range_0_30V_Set (void);
extern void       ADC1_VDH_Attenuator_Range_0_20V_Set (void);
extern uint8      ADC1_VDH_Attenuator_Range_Get       (void);
extern void       ADC1_SetEIMChannel                  (uint8 channel);
extern void       ADC1_SetSwMode_Channel              (uint8 channel);
extern void       ADC1_SetMode                        (uint8 mode);
extern void       ADC1_SetSocSwMode                   (uint8 Ch);
extern bool       ADC1_GetEocSwMode                   (void);
extern bool       ADC1_GetSwModeResult                (uint16 *pVar);
extern bool       ADC1_GetSwModeResult_mV             (uint16 *pVar_mV);
extern bool       ADC1_Busy                           (void);
extern void       ADC1_EIM_Trigger_Select             (TADC1_TRIGG_SEL trigsel);
extern void       ADC1_EIM_Repeat_Counter_Set         (TADC1_EIM_REP_CNT repcnt);
extern void       ADC1_ESM_Trigger_Select             (TADC1_TRIGG_SEL trigsel);
extern bool       ADC1_isEndOfConversion              (void);
extern bool       ADC1_isEIMactive                    (void);
extern bool       ADC1_isESMactive                    (void);
extern TADC1_ANON ADC1_ANON_Sts                       (void);

extern bool       ADC1_GetVF1                         (void);
extern bool       ADC1_GetOUT_CH1                     (void);
extern uint32     ADC1_GetRES_OUT6                    (void);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

