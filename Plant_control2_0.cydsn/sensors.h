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

struct updateParameters
{
    int16 currentMoisture;
    int16 currentBattery;
    int16 currentWater;
    int16 currentLight;
    int16 currentTemperature;
};

struct updateParameters getValues();

#endif
/* [] END OF FILE */
