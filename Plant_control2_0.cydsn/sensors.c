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
#include <sensors.h>
#include <math.h>
#include <stdio.h>

int16 moisture[50];
int16 waterlevel[50];
int16 temperature[8];
int16 batterylevel[8];
int16 lightlevel[8];

uint8 moisture_ptr = 0;
uint8 waterlevel_ptr=0;
uint8 temperature_ptr=0;
uint8 batterylevel_ptr=0;
uint8 lightlevel_ptr=0;

int16 get_moisture(void);
int16 get_waterlevel(void);
int16 get_temp(void);
int16 get_batterylevel(void);
int16 get_lightlevel(void);

struct updateParameters getValues()
{
    struct updateParameters values_;
    
    moisture_ptr = 0;
    waterlevel_ptr=0;
    temperature_ptr=0;
    batterylevel_ptr=0;
    lightlevel_ptr=0;
    
    CyDelay(500);
    
    //while(waterlevel_ptr != 50u);

    values_.currentMoisture=get_moisture();
    values_.currentLight=get_lightlevel();
    values_.currentBattery=get_batterylevel();
    values_.currentLight=get_lightlevel();
    values_.currentTemperature=get_temp();
    values_.currentWater=get_waterlevel();
    
    return values_;
}

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
        lightlevel[lightlevel_ptr]=ADC_SAR_Seq_1_CountsTo_mVolts(2u,ADC_SAR_Seq_1_GetResult16(4));
        lightlevel_ptr++;
    }

}


int16 procent_moisture = 0;
int16 get_moisture(void)
{
     if(moisture_ptr == 50)
        {
            int16 min=moisture[0];
            int16 max=moisture[0];
            
            int i;
            for(i = 1; i < 50; i++)
            {
                if(min > moisture[i])
                {
                    min = moisture[i];   
                }
                else if(max < moisture[i])
                {
                    max = moisture[i];   
                }
            }
            
            int16 pp = ((max - min)*806)/1000;
            
            double procent_d;
            
            if(pp>= 1117)
            {
                  procent_d = (-0.223834*((double)pp/1000)+0.583310)*100;
            }else
            {
                  procent_d = (-1.08366*((double)pp/1000)+1.54356)*100; 
            }
            if(procent_d < 0)
            {
                procent_d = 0;   
            }
            else if(procent_d > 100)
            {
                procent_d = 100;   
            }
            
            int16 procent = (int16)procent_d;
            //char bufchar[50];
            
            /*sprintf(bufchar, "max = %d\n\rmin = %d\n\rpp = %d mV\n\rprocent = %d %%\n\n\r", max, min, pp, procent);
            
            UART_1_UartPutString(bufchar);
            CyDelay(1000);*/
            moisture_ptr=0;
            
            procent_moisture = procent;
                        
        }
        
    return procent_moisture;
}

int16 procent_waterlevel = 0;

int16 get_waterlevel(void)
{
    if(waterlevel_ptr == 50)
        {
            int16 min=waterlevel[0];
            int16 max=waterlevel[0];
            
            int i;
            for(i = 1; i < 50; i++)
            {
                if(min > waterlevel[i])
                {
                    min = waterlevel[i];   
                }
                else if(max < waterlevel[i])
                {
                    max = waterlevel[i];   
                }
            }
            char bufchar[50];
            
            int16 pp = ((max - min)*806)/1000;
            
            double procent_d;
            
            if(pp>= 1117)
            {
                  procent_d = (-0.223834*((double)pp/1000)+0.583310)*100;
            }else
            {
                  procent_d = (-1.08366*((double)pp/1000)+1.54356)*100; 
            }
            if(procent_d < 0)
            {
                procent_d = 0;   
            }
            else if(procent_d > 100)
            {
                procent_d = 100;   
            }
            
            int16 procent = (int16)procent_d;
            
            /*sprintf(bufchar, "max = %d\n\rmin = %d\n\rpp = %d mV\n\rprocent = %d %%\n\n\r", max, min, pp, procent);
            
            UART_1_UartPutString(bufchar);
            CyDelay(1000);*/
            waterlevel_ptr=0;
            
            procent_waterlevel = procent;
                        
        }
        
    return procent_waterlevel;
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
            temp_avg=(temp_avg-1650)*0.014;
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

int16   get_batterylevel(void)
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
            volatile int16 light_avg = 0;
            int16 lightLux = 0;
            int i;
            
            for(i = 0; i < 8; i++)
            {
                 light_avg=light_avg+lightlevel[i];
            }
            
            light_avg=(light_avg>>3u);
          
            //Lys level går fra 3.03V ved 10000 Lux til 0 Lux ved 0V.
            
            lightLux = (539.9317572*(pow((double)light_avg/(3300 - (double)light_avg), 1.211)))/10;
            if(lightLux >= 999)
                lightLux = 999;
            else if(lightLux < 10)
                lightLux=0;
            // Behandling af målt avg til et lys niveau eller spænding
            char light_data[128];
            //til test af sensorer
            sprintf(light_data, "lys niveau i volt = %d\n\r lysintensitet i lux = %d\n\n\n\r", light_avg,lightLux);
            UART_PutString(light_data);
            CyDelay(500);
            
            
            lightlevel_ptr=0;
            return lightLux;
        }
        return 0; 

}

/* [] END OF FILE */
