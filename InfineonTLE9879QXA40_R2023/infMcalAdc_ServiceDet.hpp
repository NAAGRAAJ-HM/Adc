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
      MCALADC_E_BUSY
   ,  MCALADC_E_IDLE
   ,  MCALADC_E_PARAM_GROUP
   ,  MCALADC_E_PARAM_POINTER
   ,  MCALADC_E_NOT_DISENGAGED
   ,  MCALADC_E_NOT_PSERVICEOSSIBLE_TRANSITION
   ,  MCALADC_E_NOT_PREPARED_PERIPHERAL
   ,  MCALADC_E_NOT_SUPMCALPORTED_STATE_POWER
   ,  MCALADC_E_NOTIF_CAPABILITY
   ,  MCALADC_E_UNINIT
   ,  MCALADC_E_UNINIT_BUFFER
   ,  MCALADC_E_WRONG_SRC_TRIGG
   ,  MCALADC_E_WRONG_MODE_CONV
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

