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


CY_ISR_PROTO(UART_ISR);                                     //interrupt når der er data i RX bufferen (se design).

    
int main()
{
CyGlobalIntEnable;
isr_EOC_StartEx(isr_EOC_vec);
/* Place your initialization/startup code here (e.g. MyInst_Start()) */
ADC_SAR_Seq_1_Start();
ADC_SAR_Seq_1_StartConvert();
//UART_1_Start(); // til test af sensorer ( udkommenter uart del i sensors.c også)

    isr_UART_StartEx(UART_ISR);                 //initierer en bruger defineret interrupt service: UART_ISR, på intern pin: isr_UART
    UART_Start();     
    //initPSoCWiFi(SSID,PASS,DevKitIP);

    for(;;)
    {
        run();
    }
}






/* [] END OF FILE */
