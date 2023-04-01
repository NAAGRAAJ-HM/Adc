#pragma once
/******************************************************************************/
/* File   : infMcalAdc_ServiceDet.hpp                                                    */
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
#include "CompilerCfg_McalAdc.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef enum{
      ADC_E_BUSY
   ,  ADC_E_IDLE
   ,  ADC_E_PARAM_GROUP
   ,  ADC_E_PARAM_POINTER
   ,  ADC_E_NOT_DISENGAGED
   ,  ADC_E_NOT_POSSIBLE_TRANSITION
   ,  ADC_E_NOT_PREPARED_PERIPHERAL
   ,  ADC_E_NOT_SUPPORTED_STATE_POWER
   ,  ADC_E_NOTIF_CAPABILITY
   ,  ADC_E_UNINIT
   ,  ADC_E_UNINIT_BUFFER
   ,  ADC_E_WRONG_SRC_TRIGG
   ,  ADC_E_WRONG_MODE_CONV
}McalAdc_TypeServiceDetErrorCode;

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

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

