/*******************************************************************************
* File Name: stromstyring_plus.h  
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

#if !defined(CY_PINS_stromstyring_plus_H) /* Pins stromstyring_plus_H */
#define CY_PINS_stromstyring_plus_H

#include "cytypes.h"
#include "cyfitter.h"
#include "stromstyring_plus_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    stromstyring_plus_Write(uint8 value) ;
void    stromstyring_plus_SetDriveMode(uint8 mode) ;
uint8   stromstyring_plus_ReadDataReg(void) ;
uint8   stromstyring_plus_Read(void) ;
uint8   stromstyring_plus_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define stromstyring_plus_DRIVE_MODE_BITS        (3)
#define stromstyring_plus_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - stromstyring_plus_DRIVE_MODE_BITS))

#define stromstyring_plus_DM_ALG_HIZ         (0x00u)
#define stromstyring_plus_DM_DIG_HIZ         (0x01u)
#define stromstyring_plus_DM_RES_UP          (0x02u)
#define stromstyring_plus_DM_RES_DWN         (0x03u)
#define stromstyring_plus_DM_OD_LO           (0x04u)
#define stromstyring_plus_DM_OD_HI           (0x05u)
#define stromstyring_plus_DM_STRONG          (0x06u)
#define stromstyring_plus_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define stromstyring_plus_MASK               stromstyring_plus__MASK
#define stromstyring_plus_SHIFT              stromstyring_plus__SHIFT
#define stromstyring_plus_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define stromstyring_plus_PS                     (* (reg32 *) stromstyring_plus__PS)
/* Port Configuration */
#define stromstyring_plus_PC                     (* (reg32 *) stromstyring_plus__PC)
/* Data Register */
#define stromstyring_plus_DR                     (* (reg32 *) stromstyring_plus__DR)
/* Input Buffer Disable Override */
#define stromstyring_plus_INP_DIS                (* (reg32 *) stromstyring_plus__PC2)


#if defined(stromstyring_plus__INTSTAT)  /* Interrupt Registers */

    #define stromstyring_plus_INTSTAT                (* (reg32 *) stromstyring_plus__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define stromstyring_plus_DRIVE_MODE_SHIFT       (0x00u)
#define stromstyring_plus_DRIVE_MODE_MASK        (0x07u << stromstyring_plus_DRIVE_MODE_SHIFT)


#endif /* End Pins stromstyring_plus_H */


/* [] END OF FILE */
