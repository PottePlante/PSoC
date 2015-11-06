/*******************************************************************************
* File Name: stromstyring.h  
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

#if !defined(CY_PINS_stromstyring_H) /* Pins stromstyring_H */
#define CY_PINS_stromstyring_H

#include "cytypes.h"
#include "cyfitter.h"
#include "stromstyring_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    stromstyring_Write(uint8 value) ;
void    stromstyring_SetDriveMode(uint8 mode) ;
uint8   stromstyring_ReadDataReg(void) ;
uint8   stromstyring_Read(void) ;
uint8   stromstyring_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define stromstyring_DRIVE_MODE_BITS        (3)
#define stromstyring_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - stromstyring_DRIVE_MODE_BITS))

#define stromstyring_DM_ALG_HIZ         (0x00u)
#define stromstyring_DM_DIG_HIZ         (0x01u)
#define stromstyring_DM_RES_UP          (0x02u)
#define stromstyring_DM_RES_DWN         (0x03u)
#define stromstyring_DM_OD_LO           (0x04u)
#define stromstyring_DM_OD_HI           (0x05u)
#define stromstyring_DM_STRONG          (0x06u)
#define stromstyring_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define stromstyring_MASK               stromstyring__MASK
#define stromstyring_SHIFT              stromstyring__SHIFT
#define stromstyring_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define stromstyring_PS                     (* (reg32 *) stromstyring__PS)
/* Port Configuration */
#define stromstyring_PC                     (* (reg32 *) stromstyring__PC)
/* Data Register */
#define stromstyring_DR                     (* (reg32 *) stromstyring__DR)
/* Input Buffer Disable Override */
#define stromstyring_INP_DIS                (* (reg32 *) stromstyring__PC2)


#if defined(stromstyring__INTSTAT)  /* Interrupt Registers */

    #define stromstyring_INTSTAT                (* (reg32 *) stromstyring__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define stromstyring_DRIVE_MODE_SHIFT       (0x00u)
#define stromstyring_DRIVE_MODE_MASK        (0x07u << stromstyring_DRIVE_MODE_SHIFT)


#endif /* End Pins stromstyring_H */


/* [] END OF FILE */
