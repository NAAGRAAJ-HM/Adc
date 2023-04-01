#pragma once
/******************************************************************************/
/* File   : McalAdc.hpp                                                           */
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
#include "ConstMcalAdc.hpp"
#include "CfgMcalAdc.hpp"
#include "McalAdc_core.hpp"
#include "infMcalAdc_Exp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_McalAdc:
      INTERFACES_EXPORTED_MCALADC
      public abstract_module
   ,  public class_McalAdc_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
      const ConstMcalAdc_Type* lptrConst = (ConstMcalAdc_Type*)NULL_PTR;

   public:
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
      FUNC(void, MCALADC_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, MCALADC_CONST,       MCALADC_APPL_CONST) lptrConstModule
         ,  CONSTP2CONST(CfgModule_TypeAbstract,   MCALADC_CONFIG_DATA, MCALADC_APPL_CONST) lptrCfgModule
      );
      FUNC(void, MCALADC_CODE) DeInitFunction (void);
      FUNC(void, MCALADC_CODE) MainFunction   (void);
      MCALADC_CORE_FUNCTIONALITIES
#if(STD_ON == McalAdc_SupportStatePowerLow)
      FUNC(void,               MCALADC_CODE) PreparePowerState    (McalAdc_TypeStatePower lstStatePowerTargetRequested);
      FUNC(void,               MCALADC_CODE) SetPowerState        (void);
      FUNC(McalAdc_TypeStatePower, MCALADC_CODE) GetCurrentPowerState (void);
      FUNC(McalAdc_TypeStatePower, MCALADC_CODE) GetTargetPowerState  (void);
#endif
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
extern VAR(module_McalAdc, MCALADC_VAR) McalAdc;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

