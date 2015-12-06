/*******************************************************************************
* File Name: waterPump.h  
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

#if !defined(CY_PINS_waterPump_H) /* Pins waterPump_H */
#define CY_PINS_waterPump_H

#include "cytypes.h"
#include "cyfitter.h"
#include "waterPump_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    waterPump_Write(uint8 value) ;
void    waterPump_SetDriveMode(uint8 mode) ;
uint8   waterPump_ReadDataReg(void) ;
uint8   waterPump_Read(void) ;
uint8   waterPump_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define waterPump_DRIVE_MODE_BITS        (3)
#define waterPump_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - waterPump_DRIVE_MODE_BITS))

#define waterPump_DM_ALG_HIZ         (0x00u)
#define waterPump_DM_DIG_HIZ         (0x01u)
#define waterPump_DM_RES_UP          (0x02u)
#define waterPump_DM_RES_DWN         (0x03u)
#define waterPump_DM_OD_LO           (0x04u)
#define waterPump_DM_OD_HI           (0x05u)
#define waterPump_DM_STRONG          (0x06u)
#define waterPump_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define waterPump_MASK               waterPump__MASK
#define waterPump_SHIFT              waterPump__SHIFT
#define waterPump_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define waterPump_PS                     (* (reg32 *) waterPump__PS)
/* Port Configuration */
#define waterPump_PC                     (* (reg32 *) waterPump__PC)
/* Data Register */
#define waterPump_DR                     (* (reg32 *) waterPump__DR)
/* Input Buffer Disable Override */
#define waterPump_INP_DIS                (* (reg32 *) waterPump__PC2)


#if defined(waterPump__INTSTAT)  /* Interrupt Registers */

    #define waterPump_INTSTAT                (* (reg32 *) waterPump__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define waterPump_DRIVE_MODE_SHIFT       (0x00u)
#define waterPump_DRIVE_MODE_MASK        (0x07u << waterPump_DRIVE_MODE_SHIFT)


#endif /* End Pins waterPump_H */


/* [] END OF FILE */
