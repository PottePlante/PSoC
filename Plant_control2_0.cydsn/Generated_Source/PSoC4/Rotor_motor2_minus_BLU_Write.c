/*******************************************************************************
* File Name: Rotor_motor2_minus_BLU_Write.c  
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
#include "Rotor_motor2_minus_BLU_Write.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Rotor_motor2_minus_BLU_Write_PC =   (Rotor_motor2_minus_BLU_Write_PC & \
                                (uint32)(~(uint32)(Rotor_motor2_minus_BLU_Write_DRIVE_MODE_IND_MASK << (Rotor_motor2_minus_BLU_Write_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Rotor_motor2_minus_BLU_Write_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Rotor_motor2_minus_BLU_Write_Write
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
void Rotor_motor2_minus_BLU_Write_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Rotor_motor2_minus_BLU_Write_DR & (uint8)(~Rotor_motor2_minus_BLU_Write_MASK));
    drVal = (drVal | ((uint8)(value << Rotor_motor2_minus_BLU_Write_SHIFT) & Rotor_motor2_minus_BLU_Write_MASK));
    Rotor_motor2_minus_BLU_Write_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Rotor_motor2_minus_BLU_Write_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Rotor_motor2_minus_BLU_Write_DM_STRONG     Strong Drive 
*  Rotor_motor2_minus_BLU_Write_DM_OD_HI      Open Drain, Drives High 
*  Rotor_motor2_minus_BLU_Write_DM_OD_LO      Open Drain, Drives Low 
*  Rotor_motor2_minus_BLU_Write_DM_RES_UP     Resistive Pull Up 
*  Rotor_motor2_minus_BLU_Write_DM_RES_DWN    Resistive Pull Down 
*  Rotor_motor2_minus_BLU_Write_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Rotor_motor2_minus_BLU_Write_DM_DIG_HIZ    High Impedance Digital 
*  Rotor_motor2_minus_BLU_Write_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Rotor_motor2_minus_BLU_Write_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Rotor_motor2_minus_BLU_Write__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Rotor_motor2_minus_BLU_Write_Read
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
*  Macro Rotor_motor2_minus_BLU_Write_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Rotor_motor2_minus_BLU_Write_Read(void) 
{
    return (uint8)((Rotor_motor2_minus_BLU_Write_PS & Rotor_motor2_minus_BLU_Write_MASK) >> Rotor_motor2_minus_BLU_Write_SHIFT);
}


/*******************************************************************************
* Function Name: Rotor_motor2_minus_BLU_Write_ReadDataReg
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
uint8 Rotor_motor2_minus_BLU_Write_ReadDataReg(void) 
{
    return (uint8)((Rotor_motor2_minus_BLU_Write_DR & Rotor_motor2_minus_BLU_Write_MASK) >> Rotor_motor2_minus_BLU_Write_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Rotor_motor2_minus_BLU_Write_INTSTAT) 

    /*******************************************************************************
    * Function Name: Rotor_motor2_minus_BLU_Write_ClearInterrupt
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
    uint8 Rotor_motor2_minus_BLU_Write_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Rotor_motor2_minus_BLU_Write_INTSTAT & Rotor_motor2_minus_BLU_Write_MASK);
		Rotor_motor2_minus_BLU_Write_INTSTAT = maskedStatus;
        return maskedStatus >> Rotor_motor2_minus_BLU_Write_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
