/*******************************************************************************
* File Name: Rotor_motor1_plus_BLK.h  
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

#if !defined(CY_PINS_Rotor_motor1_plus_BLK_H) /* Pins Rotor_motor1_plus_BLK_H */
#define CY_PINS_Rotor_motor1_plus_BLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Rotor_motor1_plus_BLK_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Rotor_motor1_plus_BLK_Write(uint8 value) ;
void    Rotor_motor1_plus_BLK_SetDriveMode(uint8 mode) ;
uint8   Rotor_motor1_plus_BLK_ReadDataReg(void) ;
uint8   Rotor_motor1_plus_BLK_Read(void) ;
uint8   Rotor_motor1_plus_BLK_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Rotor_motor1_plus_BLK_DRIVE_MODE_BITS        (3)
#define Rotor_motor1_plus_BLK_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Rotor_motor1_plus_BLK_DRIVE_MODE_BITS))

#define Rotor_motor1_plus_BLK_DM_ALG_HIZ         (0x00u)
#define Rotor_motor1_plus_BLK_DM_DIG_HIZ         (0x01u)
#define Rotor_motor1_plus_BLK_DM_RES_UP          (0x02u)
#define Rotor_motor1_plus_BLK_DM_RES_DWN         (0x03u)
#define Rotor_motor1_plus_BLK_DM_OD_LO           (0x04u)
#define Rotor_motor1_plus_BLK_DM_OD_HI           (0x05u)
#define Rotor_motor1_plus_BLK_DM_STRONG          (0x06u)
#define Rotor_motor1_plus_BLK_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Rotor_motor1_plus_BLK_MASK               Rotor_motor1_plus_BLK__MASK
#define Rotor_motor1_plus_BLK_SHIFT              Rotor_motor1_plus_BLK__SHIFT
#define Rotor_motor1_plus_BLK_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Rotor_motor1_plus_BLK_PS                     (* (reg32 *) Rotor_motor1_plus_BLK__PS)
/* Port Configuration */
#define Rotor_motor1_plus_BLK_PC                     (* (reg32 *) Rotor_motor1_plus_BLK__PC)
/* Data Register */
#define Rotor_motor1_plus_BLK_DR                     (* (reg32 *) Rotor_motor1_plus_BLK__DR)
/* Input Buffer Disable Override */
#define Rotor_motor1_plus_BLK_INP_DIS                (* (reg32 *) Rotor_motor1_plus_BLK__PC2)


#if defined(Rotor_motor1_plus_BLK__INTSTAT)  /* Interrupt Registers */

    #define Rotor_motor1_plus_BLK_INTSTAT                (* (reg32 *) Rotor_motor1_plus_BLK__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Rotor_motor1_plus_BLK_DRIVE_MODE_SHIFT       (0x00u)
#define Rotor_motor1_plus_BLK_DRIVE_MODE_MASK        (0x07u << Rotor_motor1_plus_BLK_DRIVE_MODE_SHIFT)


#endif /* End Pins Rotor_motor1_plus_BLK_H */


/* [] END OF FILE */
