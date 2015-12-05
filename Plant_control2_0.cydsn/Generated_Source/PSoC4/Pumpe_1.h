/*******************************************************************************
* File Name: Pumpe_1.h  
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

#if !defined(CY_PINS_Pumpe_1_H) /* Pins Pumpe_1_H */
#define CY_PINS_Pumpe_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Pumpe_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Pumpe_1_Write(uint8 value) ;
void    Pumpe_1_SetDriveMode(uint8 mode) ;
uint8   Pumpe_1_ReadDataReg(void) ;
uint8   Pumpe_1_Read(void) ;
uint8   Pumpe_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pumpe_1_DRIVE_MODE_BITS        (3)
#define Pumpe_1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Pumpe_1_DRIVE_MODE_BITS))

#define Pumpe_1_DM_ALG_HIZ         (0x00u)
#define Pumpe_1_DM_DIG_HIZ         (0x01u)
#define Pumpe_1_DM_RES_UP          (0x02u)
#define Pumpe_1_DM_RES_DWN         (0x03u)
#define Pumpe_1_DM_OD_LO           (0x04u)
#define Pumpe_1_DM_OD_HI           (0x05u)
#define Pumpe_1_DM_STRONG          (0x06u)
#define Pumpe_1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Pumpe_1_MASK               Pumpe_1__MASK
#define Pumpe_1_SHIFT              Pumpe_1__SHIFT
#define Pumpe_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pumpe_1_PS                     (* (reg32 *) Pumpe_1__PS)
/* Port Configuration */
#define Pumpe_1_PC                     (* (reg32 *) Pumpe_1__PC)
/* Data Register */
#define Pumpe_1_DR                     (* (reg32 *) Pumpe_1__DR)
/* Input Buffer Disable Override */
#define Pumpe_1_INP_DIS                (* (reg32 *) Pumpe_1__PC2)


#if defined(Pumpe_1__INTSTAT)  /* Interrupt Registers */

    #define Pumpe_1_INTSTAT                (* (reg32 *) Pumpe_1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Pumpe_1_DRIVE_MODE_SHIFT       (0x00u)
#define Pumpe_1_DRIVE_MODE_MASK        (0x07u << Pumpe_1_DRIVE_MODE_SHIFT)


#endif /* End Pins Pumpe_1_H */


/* [] END OF FILE */
