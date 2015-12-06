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
#include <wifi.h>
#include <motor.h>
#include <pump.h>

int8 ID;
int8 wantedMoisture;
int8 maxTemperature;
int8 light;
int8 battery;
int8 water;
int8 wantedRotate;
       
struct updateParameters
{
    int16 currentMoisture;
    int16 currentBattery;
    int16 currentWater;
    int16 currentLight;
    int16 currentTemperature;
};

struct updateParameters sensors_;

void updateSensors();
void run();

#endif

/* [] END OF FILE */
