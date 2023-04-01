#pragma once
/******************************************************************************/
/* File   : csa.hpp                                                           */
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
      CSA_GAIN_10  = 0
   ,  CSA_GAIN_20  = 1
   ,  CSA_GAIN_40  = 2
   ,  CSA_GAIN_60  = 3
}TCSA_Gain;

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
extern void   CSA_Init                                                   (void);
extern uint16 CSA_Offset_Get                                             (void);
extern void   CSA_Power_On                                               (void);
extern void   CSA_Power_Off                                              (void);
extern void   CSA_Gain_Set                                        (uint32 gain);
extern uint32 CSA_Gain_Get                                               (void);
extern void   CSA_Set_Gain                                         (uint8 gain);
extern void   CSA_ClearVZERO                                             (void);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

