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
#ifndef PLANTCONTROL_H
#define PLANTCONTROL_H
#include <project.h>
#include <sensors.h>
#include <pump.h>
#include <wifi.h>

int8 ID;
int8 wantedMoisture;
int8 maxTemperature;
int8 light;
int8 battery;
int8 water;
int8 wantedRotate;
       
struct datas
{
    int8 water;
};
// int16 currentMoisture;
//    int16 currentBattery;
//    int16 currentWater;
//    int16 currentLight;
//    int16 currentTemperature;

struct updateParameters
{
    int16 currentMoisture;
    int16 currentBattery;
    int16 currentWater;
    int16 currentLight;
    int16 currentTemperature;
};

struct updateParameters sensors_;

uint8 calcValues();
void updateSensors();


#endif

/* [] END OF FILE */
