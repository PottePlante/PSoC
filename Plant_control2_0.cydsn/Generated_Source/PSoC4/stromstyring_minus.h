/*******************************************************************************
* File Name: stromstyring_minus.h  
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

#if !defined(CY_PINS_stromstyring_minus_H) /* Pins stromstyring_minus_H */
#define CY_PINS_stromstyring_minus_H

#include "cytypes.h"
#include "cyfitter.h"
#include "stromstyring_minus_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    stromstyring_minus_Write(uint8 value) ;
void    stromstyring_minus_SetDriveMode(uint8 mode) ;
uint8   stromstyring_minus_ReadDataReg(void) ;
uint8   stromstyring_minus_Read(void) ;
uint8   stromstyring_minus_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define stromstyring_minus_DRIVE_MODE_BITS        (3)
#define stromstyring_minus_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - stromstyring_minus_DRIVE_MODE_BITS))

#define stromstyring_minus_DM_ALG_HIZ         (0x00u)
#define stromstyring_minus_DM_DIG_HIZ         (0x01u)
#define stromstyring_minus_DM_RES_UP          (0x02u)
#define stromstyring_minus_DM_RES_DWN         (0x03u)
#define stromstyring_minus_DM_OD_LO           (0x04u)
#define stromstyring_minus_DM_OD_HI           (0x05u)
#define stromstyring_minus_DM_STRONG          (0x06u)
#define stromstyring_minus_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define stromstyring_minus_MASK               stromstyring_minus__MASK
#define stromstyring_minus_SHIFT              stromstyring_minus__SHIFT
#define stromstyring_minus_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define stromstyring_minus_PS                     (* (reg32 *) stromstyring_minus__PS)
/* Port Configuration */
#define stromstyring_minus_PC                     (* (reg32 *) stromstyring_minus__PC)
/* Data Register */
#define stromstyring_minus_DR                     (* (reg32 *) stromstyring_minus__DR)
/* Input Buffer Disable Override */
#define stromstyring_minus_INP_DIS                (* (reg32 *) stromstyring_minus__PC2)


#if defined(stromstyring_minus__INTSTAT)  /* Interrupt Registers */

    #define stromstyring_minus_INTSTAT                (* (reg32 *) stromstyring_minus__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define stromstyring_minus_DRIVE_MODE_SHIFT       (0x00u)
#define stromstyring_minus_DRIVE_MODE_MASK        (0x07u << stromstyring_minus_DRIVE_MODE_SHIFT)


#endif /* End Pins stromstyring_minus_H */


/* [] END OF FILE */
