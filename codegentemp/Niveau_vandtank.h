/*******************************************************************************
* File Name: Niveau_vandtank.h  
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

#if !defined(CY_PINS_Niveau_vandtank_H) /* Pins Niveau_vandtank_H */
#define CY_PINS_Niveau_vandtank_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Niveau_vandtank_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Niveau_vandtank_Write(uint8 value) ;
void    Niveau_vandtank_SetDriveMode(uint8 mode) ;
uint8   Niveau_vandtank_ReadDataReg(void) ;
uint8   Niveau_vandtank_Read(void) ;
uint8   Niveau_vandtank_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Niveau_vandtank_DRIVE_MODE_BITS        (3)
#define Niveau_vandtank_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Niveau_vandtank_DRIVE_MODE_BITS))

#define Niveau_vandtank_DM_ALG_HIZ         (0x00u)
#define Niveau_vandtank_DM_DIG_HIZ         (0x01u)
#define Niveau_vandtank_DM_RES_UP          (0x02u)
#define Niveau_vandtank_DM_RES_DWN         (0x03u)
#define Niveau_vandtank_DM_OD_LO           (0x04u)
#define Niveau_vandtank_DM_OD_HI           (0x05u)
#define Niveau_vandtank_DM_STRONG          (0x06u)
#define Niveau_vandtank_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Niveau_vandtank_MASK               Niveau_vandtank__MASK
#define Niveau_vandtank_SHIFT              Niveau_vandtank__SHIFT
#define Niveau_vandtank_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Niveau_vandtank_PS                     (* (reg32 *) Niveau_vandtank__PS)
/* Port Configuration */
#define Niveau_vandtank_PC                     (* (reg32 *) Niveau_vandtank__PC)
/* Data Register */
#define Niveau_vandtank_DR                     (* (reg32 *) Niveau_vandtank__DR)
/* Input Buffer Disable Override */
#define Niveau_vandtank_INP_DIS                (* (reg32 *) Niveau_vandtank__PC2)


#if defined(Niveau_vandtank__INTSTAT)  /* Interrupt Registers */

    #define Niveau_vandtank_INTSTAT                (* (reg32 *) Niveau_vandtank__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Niveau_vandtank_DRIVE_MODE_SHIFT       (0x00u)
#define Niveau_vandtank_DRIVE_MODE_MASK        (0x07u << Niveau_vandtank_DRIVE_MODE_SHIFT)


#endif /* End Pins Niveau_vandtank_H */


/* [] END OF FILE */
