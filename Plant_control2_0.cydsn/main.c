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
#include <project.h>
#include <Plantcontrol.h>



CY_ISR_PROTO(isr_EOC_vec);

uint8 count = 6;

int main()
{
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_EOC_StartEx(isr_EOC_vec);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    ADC_SAR_Seq_1_Start();
    ADC_SAR_Seq_1_StartConvert();
    //UART_1_Start(); // til test af sensorer ( udkommenter uart del i sensors.c også)
    
    initPSoCWiFi(SSID,PASS,DevKitIP);
    
    
    for(;;)
    {
        //tick();
        updateSensors();
        CyDelay(50);
        
        if(count == 6)
        {      
            //UART_PutString("Count is 6\r\n");
            sendSensorData(sensors_);
            count = 0;
        }
        
        if(wantedMoisture >= sensors_.currentMoisture)
        {
            startPumpingWater();
        }
//        else if(count == 5 && wantedMoisture <= sensors_.currentMoisture )
//            UART_PutString("plant is moist :D\r\n");
        
        count++;
        CyDelay(60000);
    }
}






/* [] END OF FILE */
