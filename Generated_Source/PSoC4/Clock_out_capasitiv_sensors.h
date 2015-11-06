/*******************************************************************************
* File Name: Clock_out_capasitiv_sensors.h  
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

#if !defined(CY_PINS_Clock_out_capasitiv_sensors_H) /* Pins Clock_out_capasitiv_sensors_H */
#define CY_PINS_Clock_out_capasitiv_sensors_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Clock_out_capasitiv_sensors_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Clock_out_capasitiv_sensors_Write(uint8 value) ;
void    Clock_out_capasitiv_sensors_SetDriveMode(uint8 mode) ;
uint8   Clock_out_capasitiv_sensors_ReadDataReg(void) ;
uint8   Clock_out_capasitiv_sensors_Read(void) ;
uint8   Clock_out_capasitiv_sensors_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Clock_out_capasitiv_sensors_DRIVE_MODE_BITS        (3)
#define Clock_out_capasitiv_sensors_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Clock_out_capasitiv_sensors_DRIVE_MODE_BITS))

#define Clock_out_capasitiv_sensors_DM_ALG_HIZ         (0x00u)
#define Clock_out_capasitiv_sensors_DM_DIG_HIZ         (0x01u)
#define Clock_out_capasitiv_sensors_DM_RES_UP          (0x02u)
#define Clock_out_capasitiv_sensors_DM_RES_DWN         (0x03u)
#define Clock_out_capasitiv_sensors_DM_OD_LO           (0x04u)
#define Clock_out_capasitiv_sensors_DM_OD_HI           (0x05u)
#define Clock_out_capasitiv_sensors_DM_STRONG          (0x06u)
#define Clock_out_capasitiv_sensors_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Clock_out_capasitiv_sensors_MASK               Clock_out_capasitiv_sensors__MASK
#define Clock_out_capasitiv_sensors_SHIFT              Clock_out_capasitiv_sensors__SHIFT
#define Clock_out_capasitiv_sensors_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Clock_out_capasitiv_sensors_PS                     (* (reg32 *) Clock_out_capasitiv_sensors__PS)
/* Port Configuration */
#define Clock_out_capasitiv_sensors_PC                     (* (reg32 *) Clock_out_capasitiv_sensors__PC)
/* Data Register */
#define Clock_out_capasitiv_sensors_DR                     (* (reg32 *) Clock_out_capasitiv_sensors__DR)
/* Input Buffer Disable Override */
#define Clock_out_capasitiv_sensors_INP_DIS                (* (reg32 *) Clock_out_capasitiv_sensors__PC2)


#if defined(Clock_out_capasitiv_sensors__INTSTAT)  /* Interrupt Registers */

    #define Clock_out_capasitiv_sensors_INTSTAT                (* (reg32 *) Clock_out_capasitiv_sensors__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Clock_out_capasitiv_sensors_DRIVE_MODE_SHIFT       (0x00u)
#define Clock_out_capasitiv_sensors_DRIVE_MODE_MASK        (0x07u << Clock_out_capasitiv_sensors_DRIVE_MODE_SHIFT)


#endif /* End Pins Clock_out_capasitiv_sensors_H */


/* [] END OF FILE */
