/*******************************************************************************
* File Name: temperatur.c  
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
#include "temperatur.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        temperatur_PC =   (temperatur_PC & \
                                (uint32)(~(uint32)(temperatur_DRIVE_MODE_IND_MASK << (temperatur_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (temperatur_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: temperatur_Write
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
void temperatur_Write(uint8 value) 
{
    uint8 drVal = (uint8)(temperatur_DR & (uint8)(~temperatur_MASK));
    drVal = (drVal | ((uint8)(value << temperatur_SHIFT) & temperatur_MASK));
    temperatur_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: temperatur_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  temperatur_DM_STRONG     Strong Drive 
*  temperatur_DM_OD_HI      Open Drain, Drives High 
*  temperatur_DM_OD_LO      Open Drain, Drives Low 
*  temperatur_DM_RES_UP     Resistive Pull Up 
*  temperatur_DM_RES_DWN    Resistive Pull Down 
*  temperatur_DM_RES_UPDWN  Resistive Pull Up/Down 
*  temperatur_DM_DIG_HIZ    High Impedance Digital 
*  temperatur_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void temperatur_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(temperatur__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: temperatur_Read
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
*  Macro temperatur_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 temperatur_Read(void) 
{
    return (uint8)((temperatur_PS & temperatur_MASK) >> temperatur_SHIFT);
}


/*******************************************************************************
* Function Name: temperatur_ReadDataReg
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
uint8 temperatur_ReadDataReg(void) 
{
    return (uint8)((temperatur_DR & temperatur_MASK) >> temperatur_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(temperatur_INTSTAT) 

    /*******************************************************************************
    * Function Name: temperatur_ClearInterrupt
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
    uint8 temperatur_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(temperatur_INTSTAT & temperatur_MASK);
		temperatur_INTSTAT = maskedStatus;
        return maskedStatus >> temperatur_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
