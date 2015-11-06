/*******************************************************************************
* File Name: Pumpe.h  
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

#if !defined(CY_PINS_Pumpe_H) /* Pins Pumpe_H */
#define CY_PINS_Pumpe_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Pumpe_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Pumpe_Write(uint8 value) ;
void    Pumpe_SetDriveMode(uint8 mode) ;
uint8   Pumpe_ReadDataReg(void) ;
uint8   Pumpe_Read(void) ;
uint8   Pumpe_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pumpe_DRIVE_MODE_BITS        (3)
#define Pumpe_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Pumpe_DRIVE_MODE_BITS))

#define Pumpe_DM_ALG_HIZ         (0x00u)
#define Pumpe_DM_DIG_HIZ         (0x01u)
#define Pumpe_DM_RES_UP          (0x02u)
#define Pumpe_DM_RES_DWN         (0x03u)
#define Pumpe_DM_OD_LO           (0x04u)
#define Pumpe_DM_OD_HI           (0x05u)
#define Pumpe_DM_STRONG          (0x06u)
#define Pumpe_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Pumpe_MASK               Pumpe__MASK
#define Pumpe_SHIFT              Pumpe__SHIFT
#define Pumpe_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pumpe_PS                     (* (reg32 *) Pumpe__PS)
/* Port Configuration */
#define Pumpe_PC                     (* (reg32 *) Pumpe__PC)
/* Data Register */
#define Pumpe_DR                     (* (reg32 *) Pumpe__DR)
/* Input Buffer Disable Override */
#define Pumpe_INP_DIS                (* (reg32 *) Pumpe__PC2)


#if defined(Pumpe__INTSTAT)  /* Interrupt Registers */

    #define Pumpe_INTSTAT                (* (reg32 *) Pumpe__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Pumpe_DRIVE_MODE_SHIFT       (0x00u)
#define Pumpe_DRIVE_MODE_MASK        (0x07u << Pumpe_DRIVE_MODE_SHIFT)


#endif /* End Pins Pumpe_H */


/* [] END OF FILE */
