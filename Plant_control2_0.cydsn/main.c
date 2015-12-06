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
    initPSoC(SSID,PASS,DevKitIP);

    for(;;)
    {
        run();
    }
}
/* [] END OF FILE */
