/*******************************************************************************
* File Name: temperatur.h  
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

#if !defined(CY_PINS_temperatur_H) /* Pins temperatur_H */
#define CY_PINS_temperatur_H

#include "cytypes.h"
#include "cyfitter.h"
#include "temperatur_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    temperatur_Write(uint8 value) ;
void    temperatur_SetDriveMode(uint8 mode) ;
uint8   temperatur_ReadDataReg(void) ;
uint8   temperatur_Read(void) ;
uint8   temperatur_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define temperatur_DRIVE_MODE_BITS        (3)
#define temperatur_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - temperatur_DRIVE_MODE_BITS))

#define temperatur_DM_ALG_HIZ         (0x00u)
#define temperatur_DM_DIG_HIZ         (0x01u)
#define temperatur_DM_RES_UP          (0x02u)
#define temperatur_DM_RES_DWN         (0x03u)
#define temperatur_DM_OD_LO           (0x04u)
#define temperatur_DM_OD_HI           (0x05u)
#define temperatur_DM_STRONG          (0x06u)
#define temperatur_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define temperatur_MASK               temperatur__MASK
#define temperatur_SHIFT              temperatur__SHIFT
#define temperatur_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define temperatur_PS                     (* (reg32 *) temperatur__PS)
/* Port Configuration */
#define temperatur_PC                     (* (reg32 *) temperatur__PC)
/* Data Register */
#define temperatur_DR                     (* (reg32 *) temperatur__DR)
/* Input Buffer Disable Override */
#define temperatur_INP_DIS                (* (reg32 *) temperatur__PC2)


#if defined(temperatur__INTSTAT)  /* Interrupt Registers */

    #define temperatur_INTSTAT                (* (reg32 *) temperatur__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define temperatur_DRIVE_MODE_SHIFT       (0x00u)
#define temperatur_DRIVE_MODE_MASK        (0x07u << temperatur_DRIVE_MODE_SHIFT)


#endif /* End Pins temperatur_H */


/* [] END OF FILE */
