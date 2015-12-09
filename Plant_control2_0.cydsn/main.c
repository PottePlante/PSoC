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

int main()
{
    CyGlobalIntEnable;
    isr_EOC_StartEx(isr_EOC_vec);
    
    run();
}
/* [] END OF FILE */
