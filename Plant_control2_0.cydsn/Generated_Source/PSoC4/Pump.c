/*******************************************************************************
* File Name: Pump.c  
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
#include "Pump.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Pump_PC =   (Pump_PC & \
                                (uint32)(~(uint32)(Pump_DRIVE_MODE_IND_MASK << (Pump_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Pump_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Pump_Write
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
void Pump_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Pump_DR & (uint8)(~Pump_MASK));
    drVal = (drVal | ((uint8)(value << Pump_SHIFT) & Pump_MASK));
    Pump_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Pump_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Pump_DM_STRONG     Strong Drive 
*  Pump_DM_OD_HI      Open Drain, Drives High 
*  Pump_DM_OD_LO      Open Drain, Drives Low 
*  Pump_DM_RES_UP     Resistive Pull Up 
*  Pump_DM_RES_DWN    Resistive Pull Down 
*  Pump_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Pump_DM_DIG_HIZ    High Impedance Digital 
*  Pump_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Pump_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Pump__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Pump_Read
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
*  Macro Pump_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Pump_Read(void) 
{
    return (uint8)((Pump_PS & Pump_MASK) >> Pump_SHIFT);
}


/*******************************************************************************
* Function Name: Pump_ReadDataReg
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
uint8 Pump_ReadDataReg(void) 
{
    return (uint8)((Pump_DR & Pump_MASK) >> Pump_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Pump_INTSTAT) 

    /*******************************************************************************
    * Function Name: Pump_ClearInterrupt
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
    uint8 Pump_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Pump_INTSTAT & Pump_MASK);
		Pump_INTSTAT = maskedStatus;
        return maskedStatus >> Pump_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
