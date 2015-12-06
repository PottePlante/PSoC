/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <motor.h>


void rotate(int16 step)
{
    int8 speed=10;
    if(indexnummer1==0)
        indexnummer1=1;
    
    if(step>=0) //validering
    step=step;
    else
    step=0;
    
    while(step!=0)
    { 
        if(indexnummer1==1)
        {    
        Rotor_motor1_plus_BLK_Write(1);
        CyDelay(speed);
        Rotor_motor1_plus_BLK_Write(0);
        }
        if(indexnummer1==2)
        {    
        Rotor_motor2_plus_RED_Write(1);
        CyDelay(speed);
        Rotor_motor2_plus_RED_Write(0);
        }
         if(indexnummer1==3)
        {    
        Rotor_motor1_minus_GRN_Write(1);
        CyDelay(speed);
        Rotor_motor1_minus_GRN_Write(0);
        }
         if(indexnummer1==4)
        {    
        Rotor_motor2_minus_BLU_Write(1);
        CyDelay(speed);
        Rotor_motor2_minus_BLU_Write(0);
        }
       
        if(indexnummer1==4)
        indexnummer1=1;
        else
        indexnummer1++;
      
        step--;   
    } 
}


/* [] END OF FILE */
