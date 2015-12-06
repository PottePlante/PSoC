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
#include <Plantcontrol.h>

uint8 count = 6;

void updateSensors()
{
//    struct updateParameters sensor;
//    struct updateParameters *updatePtr;
//    updatePtr =&sensor;
//    
    // get funktioner skal hentes en gang før disse data læses (nødvendigt da dette data kan være gammel data i arrays)
    get_batterylevel();
    get_lightlevel();
    get_moisture();
    get_temp();
    get_waterlevel();
    // Data hentes

    sensors_.currentMoisture=get_moisture();
    sensors_.currentLight=get_lightlevel();
    sensors_.currentBattery=get_batterylevel();
    sensors_.currentLight=get_lightlevel();
    sensors_.currentTemperature=get_temp();
    sensors_.currentWater=get_waterlevel();
}

void run()
{
    updateSensors();
    CyDelay(50);
    
    if(count == 6)
    {      
        sendSensorData(sensors_);
        count = 0;
    }
    
    //Rotere
    rotate(wantedRotate);
    wantedRotate = 0;

    //Pumpe
    if(wantedMoisture >= sensors_.currentMoisture)  //hvis den værdi devkit sender er større end sensors værdi så pumpes der
    {
        start();
        CyDelay(1000);
        stop();
    }
    
    count++;
    CyDelay(60000);
}

/* [] END OF FILE */
