/*******************************************************************************
* File Name: stromstyring_plus.c  
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
#include "stromstyring_plus.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        stromstyring_plus_PC =   (stromstyring_plus_PC & \
                                (uint32)(~(uint32)(stromstyring_plus_DRIVE_MODE_IND_MASK << (stromstyring_plus_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (stromstyring_plus_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: stromstyring_plus_Write
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
void stromstyring_plus_Write(uint8 value) 
{
    uint8 drVal = (uint8)(stromstyring_plus_DR & (uint8)(~stromstyring_plus_MASK));
    drVal = (drVal | ((uint8)(value << stromstyring_plus_SHIFT) & stromstyring_plus_MASK));
    stromstyring_plus_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: stromstyring_plus_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  stromstyring_plus_DM_STRONG     Strong Drive 
*  stromstyring_plus_DM_OD_HI      Open Drain, Drives High 
*  stromstyring_plus_DM_OD_LO      Open Drain, Drives Low 
*  stromstyring_plus_DM_RES_UP     Resistive Pull Up 
*  stromstyring_plus_DM_RES_DWN    Resistive Pull Down 
*  stromstyring_plus_DM_RES_UPDWN  Resistive Pull Up/Down 
*  stromstyring_plus_DM_DIG_HIZ    High Impedance Digital 
*  stromstyring_plus_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void stromstyring_plus_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(stromstyring_plus__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: stromstyring_plus_Read
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
*  Macro stromstyring_plus_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 stromstyring_plus_Read(void) 
{
    return (uint8)((stromstyring_plus_PS & stromstyring_plus_MASK) >> stromstyring_plus_SHIFT);
}


/*******************************************************************************
* Function Name: stromstyring_plus_ReadDataReg
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
uint8 stromstyring_plus_ReadDataReg(void) 
{
    return (uint8)((stromstyring_plus_DR & stromstyring_plus_MASK) >> stromstyring_plus_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(stromstyring_plus_INTSTAT) 

    /*******************************************************************************
    * Function Name: stromstyring_plus_ClearInterrupt
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
    uint8 stromstyring_plus_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(stromstyring_plus_INTSTAT & stromstyring_plus_MASK);
		stromstyring_plus_INTSTAT = maskedStatus;
        return maskedStatus >> stromstyring_plus_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
