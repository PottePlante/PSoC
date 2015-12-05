/*******************************************************************************
* File Name: Rotor_motor2_minus_BLU.h  
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

#if !defined(CY_PINS_Rotor_motor2_minus_BLU_H) /* Pins Rotor_motor2_minus_BLU_H */
#define CY_PINS_Rotor_motor2_minus_BLU_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Rotor_motor2_minus_BLU_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Rotor_motor2_minus_BLU_Write(uint8 value) ;
void    Rotor_motor2_minus_BLU_SetDriveMode(uint8 mode) ;
uint8   Rotor_motor2_minus_BLU_ReadDataReg(void) ;
uint8   Rotor_motor2_minus_BLU_Read(void) ;
uint8   Rotor_motor2_minus_BLU_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Rotor_motor2_minus_BLU_DRIVE_MODE_BITS        (3)
#define Rotor_motor2_minus_BLU_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Rotor_motor2_minus_BLU_DRIVE_MODE_BITS))

#define Rotor_motor2_minus_BLU_DM_ALG_HIZ         (0x00u)
#define Rotor_motor2_minus_BLU_DM_DIG_HIZ         (0x01u)
#define Rotor_motor2_minus_BLU_DM_RES_UP          (0x02u)
#define Rotor_motor2_minus_BLU_DM_RES_DWN         (0x03u)
#define Rotor_motor2_minus_BLU_DM_OD_LO           (0x04u)
#define Rotor_motor2_minus_BLU_DM_OD_HI           (0x05u)
#define Rotor_motor2_minus_BLU_DM_STRONG          (0x06u)
#define Rotor_motor2_minus_BLU_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Rotor_motor2_minus_BLU_MASK               Rotor_motor2_minus_BLU__MASK
#define Rotor_motor2_minus_BLU_SHIFT              Rotor_motor2_minus_BLU__SHIFT
#define Rotor_motor2_minus_BLU_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Rotor_motor2_minus_BLU_PS                     (* (reg32 *) Rotor_motor2_minus_BLU__PS)
/* Port Configuration */
#define Rotor_motor2_minus_BLU_PC                     (* (reg32 *) Rotor_motor2_minus_BLU__PC)
/* Data Register */
#define Rotor_motor2_minus_BLU_DR                     (* (reg32 *) Rotor_motor2_minus_BLU__DR)
/* Input Buffer Disable Override */
#define Rotor_motor2_minus_BLU_INP_DIS                (* (reg32 *) Rotor_motor2_minus_BLU__PC2)


#if defined(Rotor_motor2_minus_BLU__INTSTAT)  /* Interrupt Registers */

    #define Rotor_motor2_minus_BLU_INTSTAT                (* (reg32 *) Rotor_motor2_minus_BLU__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Rotor_motor2_minus_BLU_DRIVE_MODE_SHIFT       (0x00u)
#define Rotor_motor2_minus_BLU_DRIVE_MODE_MASK        (0x07u << Rotor_motor2_minus_BLU_DRIVE_MODE_SHIFT)


#endif /* End Pins Rotor_motor2_minus_BLU_H */


/* [] END OF FILE */
