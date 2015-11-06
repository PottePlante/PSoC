/*******************************************************************************
* File Name: Fugt.c  
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
#include "Fugt.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Fugt_PC =   (Fugt_PC & \
                                (uint32)(~(uint32)(Fugt_DRIVE_MODE_IND_MASK << (Fugt_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Fugt_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Fugt_Write
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
void Fugt_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Fugt_DR & (uint8)(~Fugt_MASK));
    drVal = (drVal | ((uint8)(value << Fugt_SHIFT) & Fugt_MASK));
    Fugt_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Fugt_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Fugt_DM_STRONG     Strong Drive 
*  Fugt_DM_OD_HI      Open Drain, Drives High 
*  Fugt_DM_OD_LO      Open Drain, Drives Low 
*  Fugt_DM_RES_UP     Resistive Pull Up 
*  Fugt_DM_RES_DWN    Resistive Pull Down 
*  Fugt_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Fugt_DM_DIG_HIZ    High Impedance Digital 
*  Fugt_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Fugt_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Fugt__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Fugt_Read
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
*  Macro Fugt_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Fugt_Read(void) 
{
    return (uint8)((Fugt_PS & Fugt_MASK) >> Fugt_SHIFT);
}


/*******************************************************************************
* Function Name: Fugt_ReadDataReg
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
uint8 Fugt_ReadDataReg(void) 
{
    return (uint8)((Fugt_DR & Fugt_MASK) >> Fugt_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Fugt_INTSTAT) 

    /*******************************************************************************
    * Function Name: Fugt_ClearInterrupt
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
    uint8 Fugt_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Fugt_INTSTAT & Fugt_MASK);
		Fugt_INTSTAT = maskedStatus;
        return maskedStatus >> Fugt_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
