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
#include <pump.h>

void start()    //simpel function som tænder for pumpen, venter 5 sekunder og slukker for den igen
{
    Pumpe_Write(1);
}

void stop()
{
    Pumpe_Write(0);
}


/* [] END OF FILE */
