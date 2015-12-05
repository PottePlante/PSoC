/*******************************************************************************
* File Name: Pumpe_4.h  
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

#if !defined(CY_PINS_Pumpe_4_H) /* Pins Pumpe_4_H */
#define CY_PINS_Pumpe_4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Pumpe_4_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Pumpe_4_Write(uint8 value) ;
void    Pumpe_4_SetDriveMode(uint8 mode) ;
uint8   Pumpe_4_ReadDataReg(void) ;
uint8   Pumpe_4_Read(void) ;
uint8   Pumpe_4_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pumpe_4_DRIVE_MODE_BITS        (3)
#define Pumpe_4_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Pumpe_4_DRIVE_MODE_BITS))

#define Pumpe_4_DM_ALG_HIZ         (0x00u)
#define Pumpe_4_DM_DIG_HIZ         (0x01u)
#define Pumpe_4_DM_RES_UP          (0x02u)
#define Pumpe_4_DM_RES_DWN         (0x03u)
#define Pumpe_4_DM_OD_LO           (0x04u)
#define Pumpe_4_DM_OD_HI           (0x05u)
#define Pumpe_4_DM_STRONG          (0x06u)
#define Pumpe_4_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Pumpe_4_MASK               Pumpe_4__MASK
#define Pumpe_4_SHIFT              Pumpe_4__SHIFT
#define Pumpe_4_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pumpe_4_PS                     (* (reg32 *) Pumpe_4__PS)
/* Port Configuration */
#define Pumpe_4_PC                     (* (reg32 *) Pumpe_4__PC)
/* Data Register */
#define Pumpe_4_DR                     (* (reg32 *) Pumpe_4__DR)
/* Input Buffer Disable Override */
#define Pumpe_4_INP_DIS                (* (reg32 *) Pumpe_4__PC2)


#if defined(Pumpe_4__INTSTAT)  /* Interrupt Registers */

    #define Pumpe_4_INTSTAT                (* (reg32 *) Pumpe_4__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Pumpe_4_DRIVE_MODE_SHIFT       (0x00u)
#define Pumpe_4_DRIVE_MODE_MASK        (0x07u << Pumpe_4_DRIVE_MODE_SHIFT)


#endif /* End Pins Pumpe_4_H */


/* [] END OF FILE */
