/*******************************************************************************
* File Name: Lysfoler.h  
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

#if !defined(CY_PINS_Lysfoler_H) /* Pins Lysfoler_H */
#define CY_PINS_Lysfoler_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Lysfoler_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Lysfoler_Write(uint8 value) ;
void    Lysfoler_SetDriveMode(uint8 mode) ;
uint8   Lysfoler_ReadDataReg(void) ;
uint8   Lysfoler_Read(void) ;
uint8   Lysfoler_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Lysfoler_DRIVE_MODE_BITS        (3)
#define Lysfoler_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Lysfoler_DRIVE_MODE_BITS))

#define Lysfoler_DM_ALG_HIZ         (0x00u)
#define Lysfoler_DM_DIG_HIZ         (0x01u)
#define Lysfoler_DM_RES_UP          (0x02u)
#define Lysfoler_DM_RES_DWN         (0x03u)
#define Lysfoler_DM_OD_LO           (0x04u)
#define Lysfoler_DM_OD_HI           (0x05u)
#define Lysfoler_DM_STRONG          (0x06u)
#define Lysfoler_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Lysfoler_MASK               Lysfoler__MASK
#define Lysfoler_SHIFT              Lysfoler__SHIFT
#define Lysfoler_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Lysfoler_PS                     (* (reg32 *) Lysfoler__PS)
/* Port Configuration */
#define Lysfoler_PC                     (* (reg32 *) Lysfoler__PC)
/* Data Register */
#define Lysfoler_DR                     (* (reg32 *) Lysfoler__DR)
/* Input Buffer Disable Override */
#define Lysfoler_INP_DIS                (* (reg32 *) Lysfoler__PC2)


#if defined(Lysfoler__INTSTAT)  /* Interrupt Registers */

    #define Lysfoler_INTSTAT                (* (reg32 *) Lysfoler__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Lysfoler_DRIVE_MODE_SHIFT       (0x00u)
#define Lysfoler_DRIVE_MODE_MASK        (0x07u << Lysfoler_DRIVE_MODE_SHIFT)


#endif /* End Pins Lysfoler_H */


/* [] END OF FILE */
