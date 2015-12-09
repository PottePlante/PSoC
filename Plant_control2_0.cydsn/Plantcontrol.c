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

uint8 ID = 2;
uint8 wantedMoisture = 0;
uint8 wantedRotate = 0;

void run()
{
    ADC_SAR_Seq_1_Start();
    ADC_SAR_Seq_1_StartConvert();

    initPSoCWiFi(SSID,PASS,DevKitIP);
    
    for(;;)
    {
        struct updateParameters values = getValues();     

        struct responses res = sendSensorData(values);

        ID = res.ID;
        wantedMoisture = res.moisture;
        wantedRotate = res.rotate;
        
        if(wantedMoisture >= values.currentMoisture)
        {
            start();
            CyDelay(1000);
            stop();
        }
        
        rotate(wantedRotate);
        
        CyDelay(100000);
    }
}

int8 getID()
{
    return ID;
}

/* [] END OF FILE */
