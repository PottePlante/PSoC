/*******************************************************************************
* File Name: waterPump.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "waterPump.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        waterPump_PC =   (waterPump_PC & \
                                (uint32)(~(uint32)(waterPump_DRIVE_MODE_IND_MASK << (waterPump_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (waterPump_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: waterPump_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void waterPump_Write(uint8 value) 
{
    uint8 drVal = (uint8)(waterPump_DR & (uint8)(~waterPump_MASK));
    drVal = (drVal | ((uint8)(value << waterPump_SHIFT) & waterPump_MASK));
    waterPump_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: waterPump_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  waterPump_DM_STRONG     Strong Drive 
*  waterPump_DM_OD_HI      Open Drain, Drives High 
*  waterPump_DM_OD_LO      Open Drain, Drives Low 
*  waterPump_DM_RES_UP     Resistive Pull Up 
*  waterPump_DM_RES_DWN    Resistive Pull Down 
*  waterPump_DM_RES_UPDWN  Resistive Pull Up/Down 
*  waterPump_DM_DIG_HIZ    High Impedance Digital 
*  waterPump_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void waterPump_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(waterPump__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: waterPump_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro waterPump_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 waterPump_Read(void) 
{
    return (uint8)((waterPump_PS & waterPump_MASK) >> waterPump_SHIFT);
}


/*******************************************************************************
* Function Name: waterPump_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 waterPump_ReadDataReg(void) 
{
    return (uint8)((waterPump_DR & waterPump_MASK) >> waterPump_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(waterPump_INTSTAT) 

    /*******************************************************************************
    * Function Name: waterPump_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 waterPump_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(waterPump_INTSTAT & waterPump_MASK);
		waterPump_INTSTAT = maskedStatus;
        return maskedStatus >> waterPump_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
