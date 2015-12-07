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
#include <motor.h>
  
struct updateParameters;

void run();
int8 getID();

#endif

/* [] END OF FILE */
