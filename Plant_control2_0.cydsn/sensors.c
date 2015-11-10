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
#include<sensors.h>


uint8 moisture_ptr = 0;
uint8 waterlevel_ptr=0;
uint8 temperature_ptr=0;
uint8 batterylevel_ptr=0;
uint8 lightlevel_ptr=0;



CY_ISR(isr_EOC_vec)
{
    if(moisture_ptr < 50u)
    {
        moisture[moisture_ptr]=ADC_SAR_Seq_1_GetResult16(0);
        moisture_ptr++; 
    }
    if(waterlevel_ptr<50u)
    {
        waterlevel[waterlevel_ptr]=ADC_SAR_Seq_1_GetResult16(3);
        waterlevel_ptr++;
    }
   if(temperature_ptr < 8u )
    {
        temperature[temperature_ptr]=ADC_SAR_Seq_1_CountsTo_mVolts(2u,ADC_SAR_Seq_1_GetResult16(2));
        temperature_ptr++;  
    }
    if(batterylevel_ptr< 8u)
    {
        batterylevel[batterylevel_ptr]=ADC_SAR_Seq_1_CountsTo_mVolts(2u,ADC_SAR_Seq_1_GetResult16(1));
        batterylevel_ptr++;
    }
    if(lightlevel_ptr< 8u)
    {
        lightlevel[batterylevel_ptr]=ADC_SAR_Seq_1_CountsTo_mVolts(2u,ADC_SAR_Seq_1_GetResult16(4));
        lightlevel_ptr++;
    }
    
}


int16 get_moisture(void)
{
     if(moisture_ptr == 50)
       {
            int16 moisture_max = moisture[0];
            int16 moisture_min = moisture[0];
           
            
            int i;
            for(i = 1; i < 50; i++)
            {
                  if(moisture_max < moisture[i])
                    moisture_max = moisture[i];
                  else if(moisture_min > moisture[i])
                    moisture_min = moisture[i];
 
            }
          
        
            char moisture_data[50];
            
            int16 moisture_maxV=ADC_SAR_Seq_1_CountsTo_mVolts(0, moisture_max);
            int16 moisture_minV=ADC_SAR_Seq_1_CountsTo_mVolts(0, moisture_min);
            int16 moisture_pp = (int16)moisture_maxV - (int16)moisture_minV;
            float moisture;
            
            if(moisture_pp < 965)
            {
                moisture= 318.06-((float)moisture_pp)*0.278;
                if(moisture > 100)
                {
                    moisture=100;
                }
            }
            else if(moisture_pp >965)
            {
                moisture=78.13-0.0292*((float)moisture_pp);
                if(moisture < 0)
                {
                    moisture=0;
                }
            }
            
            
            /* //til test af sensorer
            sprintf(moisture_data, "fugtniveau procent = %d\n\r",(int16)moisture);
            UART_1_UartPutString(moisture_data);
            CyDelay(1000);
            */
            moisture_ptr=0;
            //return (int16)moisture; BRUGRES TIL TEST HUSK AT RETTE
            return 50;
            
       }
        return 0;
}

int16 get_waterlevel(void)
{
if(waterlevel_ptr == 50)
        {
            int16 waterlevel_max = waterlevel[0];
            int16 waterlevel_min = waterlevel[0];
           
            
            int i;
            for(i = 1; i < 50; i++)
            {
                  if(waterlevel_max < waterlevel[i])
                    waterlevel_max = waterlevel[i];
                  else if(waterlevel_min > waterlevel[i])
                    waterlevel_min = waterlevel[i];
 
            }
          
        
            char waterlevel_data[50];
 
            
            
            int16 waterlevel_maxV=ADC_SAR_Seq_1_CountsTo_mVolts(2, waterlevel_max);
            int16 waterlevel_minV=ADC_SAR_Seq_1_CountsTo_mVolts(2, waterlevel_min);
            int16 waterlevel_pp =waterlevel_maxV-waterlevel_minV;
            
            float water_level;
            
            if(waterlevel_pp < 965)
            {
                water_level= 310.64-((float)waterlevel_pp)*0.268;
                if(water_level > 100)
                {
                    water_level=100;
                }
            }
            else if(waterlevel_pp >=965)
            {
                water_level=78.03-0.0273*((float)waterlevel_pp);
                if(water_level < 0)
                {
                    water_level=0;
                }
            }
            /* //til test af sensorer
            sprintf(waterlevel_data, "vand niveau procent = %d\n\r", (int16)water_level);
            UART_1_UartPutString(waterlevel_data);
            CyDelay(1000);
            */
            waterlevel_ptr=0;
            return (int16)water_level;
            
        }
    return 0;
}

int16 get_temp(void)
{
    if(temperature_ptr == 8u)
        {
            
            int16 temp_avg=0;
            int i;
            for(i = 0; i < 8; i++)
            {
                 temp_avg=temp_avg+temperature[i];
            }
            
            temp_avg=(temp_avg>>3u);
            
            
            
          
        
            char temp_data[50];
            
            // omregning af temperatur. 
            temp_avg=(temp_avg-29)*0.253; 
            // 1.65V som svare til 0 grader trækkes fra og forstærkning gange på for at få temperatur i grader (eks 39mV=39 grader)
        
            /* //til test af sensorer
            sprintf(temp_data, "temperature = %d \n\r",temp_avg);
            UART_1_UartPutString(temp_data);
            CyDelay(1000);
            */
            temperature_ptr=0u;
            
            if(temp_avg < 0)
                temp_avg = 0;
            
            return temp_avg;
            
        }
        return 0; 
}

int16 get_batterylevel(void)
{
     if(batterylevel_ptr == 8u)
        {
   
            int16 battery_avg=0;
            int i;
            for(i = 1; i < 8; i++)
            {
                 battery_avg=battery_avg+batterylevel[i];
            }
            
            battery_avg=(battery_avg>>3u);
          
        
            char battery_data[50];
            
           
            //batteri styringen går fra 3.3V ved fuld opladt batteri til 2.7 diff 600mV
            int16 battery_pro=0;
            battery_avg=battery_avg+1970;
         
            
            if(battery_avg > 3300)
            {
                battery_pro=100;
            }
            else if(battery_avg > 3240)
            {
                battery_pro=90;
            }
            else if(battery_avg > 3180)
            {
                battery_pro=80;
            }
            else if(battery_avg > 3120)
            {
                battery_pro=70;
            }
            else if(battery_avg > 3060)
            {
                battery_pro=60;
            }
            else if(battery_avg > 3000)
            {
                battery_pro=50;
            }
            else if(battery_avg > 2940)
            {
                battery_pro=40;
            }
            else if(battery_avg > 2880)
            {
                battery_pro=30;
            }
            else if(battery_avg > 2820)
            {
                battery_pro=20;
            }
            else if(battery_avg > 2760)
            {
                battery_pro=10;
            }
            else
            {
                battery_pro=5;
            }
           
          
            /* //til test af sensorer
            sprintf(battery_data, "batteri niveau = %d\n\r", battery_pro);
            UART_1_UartPutString(battery_data);
            CyDelay(1000);
            */
            
            batterylevel_ptr=0;
            return battery_pro;
            
        }
        return 0; 


}

int16 get_lightlevel(void)
{
if(lightlevel_ptr == 8u)
        {
   
            int16 light_avg=0;
            int i;
            for(i = 1; i < 8; i++)
            {
                 light_avg=light_avg+lightlevel[i];
            }
            
            light_avg=(light_avg/8);
          
        
            char light_data[50];
            
            // Behandling af målt avg til et lys niveau eller spænding
 
          
            /* //til test af sensorer
            sprintf(light_data, "lys niveau i volt = %d\n\r", light_avg);
            UART_1_UartPutString(light_data);
            CyDelay(1000);
            */
            
            lightlevel_ptr=0;
            return light_avg;
            
        }
        return 0; 

}

/* [] END OF FILE */
