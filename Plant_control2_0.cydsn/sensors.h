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
#ifndef SENSORS_H
#define SENSORS_H
#include <project.h>

CY_ISR_PROTO(isr_EOC_vec);
    
int16 moisture[50];
int16 waterlevel[50];
int16 temperature[8];
int16 batterylevel[8];
int16 lightlevel[8];

int16 get_moisture(void);
int16 get_waterlevel(void);
int16 get_temp(void);
int16 get_batterylevel(void);
int16 get_lightlevel(void);

#endif
/* [] END OF FILE */
