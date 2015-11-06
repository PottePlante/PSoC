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
#include<Plantcontrol.h>

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
    currentBattery=get_batterylevel();
    //int8 lightlevel=get_lightlevel();
    currentMoisture=get_moisture();
    currentTemperature=get_temp();
    currentWater=get_waterlevel();
    
//    sensor.currentMoisture=get_batterylevel();
//    sensor.currentBattery=get_batterylevel();
//    sensor.currentLight=get_lightlevel();
//    sensor.currentTemperature=get_temp();
//    sensor.currentWater=get_waterlevel();
//    
}

/* [] END OF FILE */
