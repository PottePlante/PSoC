/*******************************************************************************
* File Name: Lysfoler.c  
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
#include "Lysfoler.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Lysfoler_PC =   (Lysfoler_PC & \
                                (uint32)(~(uint32)(Lysfoler_DRIVE_MODE_IND_MASK << (Lysfoler_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Lysfoler_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Lysfoler_Write
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
void Lysfoler_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Lysfoler_DR & (uint8)(~Lysfoler_MASK));
    drVal = (drVal | ((uint8)(value << Lysfoler_SHIFT) & Lysfoler_MASK));
    Lysfoler_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Lysfoler_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Lysfoler_DM_STRONG     Strong Drive 
*  Lysfoler_DM_OD_HI      Open Drain, Drives High 
*  Lysfoler_DM_OD_LO      Open Drain, Drives Low 
*  Lysfoler_DM_RES_UP     Resistive Pull Up 
*  Lysfoler_DM_RES_DWN    Resistive Pull Down 
*  Lysfoler_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Lysfoler_DM_DIG_HIZ    High Impedance Digital 
*  Lysfoler_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Lysfoler_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Lysfoler__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Lysfoler_Read
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
*  Macro Lysfoler_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Lysfoler_Read(void) 
{
    return (uint8)((Lysfoler_PS & Lysfoler_MASK) >> Lysfoler_SHIFT);
}


/*******************************************************************************
* Function Name: Lysfoler_ReadDataReg
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
uint8 Lysfoler_ReadDataReg(void) 
{
    return (uint8)((Lysfoler_DR & Lysfoler_MASK) >> Lysfoler_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Lysfoler_INTSTAT) 

    /*******************************************************************************
    * Function Name: Lysfoler_ClearInterrupt
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
    uint8 Lysfoler_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Lysfoler_INTSTAT & Lysfoler_MASK);
		Lysfoler_INTSTAT = maskedStatus;
        return maskedStatus >> Lysfoler_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
