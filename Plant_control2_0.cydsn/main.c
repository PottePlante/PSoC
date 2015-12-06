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

int main()
{
       
    CyGlobalIntEnable;                          //enabler global interrupt
        
    ADC_SAR_Seq_1_Start();
    ADC_SAR_Seq_1_StartConvert();
    isr_EOC_StartEx(isr_EOC_vec);
    
    initPSoCWifi(SSID,PASS,DevKitIP);

    for(;;)
    {
        run();
    }
}
/* [] END OF FILE */
