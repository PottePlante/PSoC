/*******************************************************************************
* File Name: Pump.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Pump_H) /* Pins Pump_H */
#define CY_PINS_Pump_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Pump_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Pump_Write(uint8 value) ;
void    Pump_SetDriveMode(uint8 mode) ;
uint8   Pump_ReadDataReg(void) ;
uint8   Pump_Read(void) ;
uint8   Pump_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pump_DRIVE_MODE_BITS        (3)
#define Pump_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Pump_DRIVE_MODE_BITS))

#define Pump_DM_ALG_HIZ         (0x00u)
#define Pump_DM_DIG_HIZ         (0x01u)
#define Pump_DM_RES_UP          (0x02u)
#define Pump_DM_RES_DWN         (0x03u)
#define Pump_DM_OD_LO           (0x04u)
#define Pump_DM_OD_HI           (0x05u)
#define Pump_DM_STRONG          (0x06u)
#define Pump_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Pump_MASK               Pump__MASK
#define Pump_SHIFT              Pump__SHIFT
#define Pump_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pump_PS                     (* (reg32 *) Pump__PS)
/* Port Configuration */
#define Pump_PC                     (* (reg32 *) Pump__PC)
/* Data Register */
#define Pump_DR                     (* (reg32 *) Pump__DR)
/* Input Buffer Disable Override */
#define Pump_INP_DIS                (* (reg32 *) Pump__PC2)


#if defined(Pump__INTSTAT)  /* Interrupt Registers */

    #define Pump_INTSTAT                (* (reg32 *) Pump__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Pump_DRIVE_MODE_SHIFT       (0x00u)
#define Pump_DRIVE_MODE_MASK        (0x07u << Pump_DRIVE_MODE_SHIFT)


#endif /* End Pins Pump_H */


/* [] END OF FILE */
