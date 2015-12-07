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

int8 ID = 2;
int8 wantedMoisture = 0;
int8 wantedRotate = 0;

void run()
{
    struct updateParameters values = getValues();
    
//    if(wantedMoisture >= values.currentMoisture)
//    {
//        start();
//        CyDelay(1000);
//        stop();
//    }
//    
//    rotate(wantedRotate);
//    
    //struct responses res = sendSensorData(values);
    
//    ID = res.ID;
//    wantedMoisture = res.moisture;
//    wantedRotate = res.rotate;
//    
    CyDelay(200);
}

int8 getID()
{
    return ID;
}

/* [] END OF FILE */
