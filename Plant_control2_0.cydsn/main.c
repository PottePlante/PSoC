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
    //   tick();
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
            Pumpe_Write(1);
            CyDelay(1000);
            Pumpe_Write(0);
        }
       // else //(count == 5 && wantedMoisture <= sensors_.currentMoisture )
        //    UART_PutString("plant is moist :D\r\n");
        
        count++;
        CyDelay(12000);
    }
}






/* [] END OF FILE */
