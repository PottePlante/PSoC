/*******************************************************************************
* File Name: Fugt.h  
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

#if !defined(CY_PINS_Fugt_H) /* Pins Fugt_H */
#define CY_PINS_Fugt_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Fugt_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Fugt_Write(uint8 value) ;
void    Fugt_SetDriveMode(uint8 mode) ;
uint8   Fugt_ReadDataReg(void) ;
uint8   Fugt_Read(void) ;
uint8   Fugt_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Fugt_DRIVE_MODE_BITS        (3)
#define Fugt_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Fugt_DRIVE_MODE_BITS))

#define Fugt_DM_ALG_HIZ         (0x00u)
#define Fugt_DM_DIG_HIZ         (0x01u)
#define Fugt_DM_RES_UP          (0x02u)
#define Fugt_DM_RES_DWN         (0x03u)
#define Fugt_DM_OD_LO           (0x04u)
#define Fugt_DM_OD_HI           (0x05u)
#define Fugt_DM_STRONG          (0x06u)
#define Fugt_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Fugt_MASK               Fugt__MASK
#define Fugt_SHIFT              Fugt__SHIFT
#define Fugt_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Fugt_PS                     (* (reg32 *) Fugt__PS)
/* Port Configuration */
#define Fugt_PC                     (* (reg32 *) Fugt__PC)
/* Data Register */
#define Fugt_DR                     (* (reg32 *) Fugt__DR)
/* Input Buffer Disable Override */
#define Fugt_INP_DIS                (* (reg32 *) Fugt__PC2)


#if defined(Fugt__INTSTAT)  /* Interrupt Registers */

    #define Fugt_INTSTAT                (* (reg32 *) Fugt__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Fugt_DRIVE_MODE_SHIFT       (0x00u)
#define Fugt_DRIVE_MODE_MASK        (0x07u << Fugt_DRIVE_MODE_SHIFT)


#endif /* End Pins Fugt_H */


/* [] END OF FILE */
