///* ========================================
// *
// * Copyright YOUR COMPANY, THE YEAR
// * All Rights Reserved
// * UNPUBLISHED, LICENSED SOFTWARE.
// *
// * CONFIDENTIAL AND PROPRIETARY INFORMATION
// * WHICH IS THE PROPERTY OF your company.
// *
// * ========================================
//*/

#include <stdio.h>
#include <stdlib.h>
#include "wifi.h"

/***********************************DIVERSE GLOBALE VARIABLER********************************/
uint8 RXnewData;                            //Benyttes til ISR - '1' hvis der er data i RX bufferen, '0' hvis der ikke er data...
uint8 stringRX_len = 0;                     //Længde af RX buffer
char stringRX[255] = {0};                   //RX buffer til interrupts
char uartString[255] = {0};                 //string som UARTen benytter til at modtage / har modtaget
uint8 plantID = 2;                         //Pottens ID / PSoC ID

CY_ISR(UART_ISR)
{
    updateBuf();
}

void updateBuf()
{
    if(RXnewData)
        return;
    uint8 size = UART_GetRxBufferSize();
    int i;
    for(i = 0; i < size + 1; i++)
    {
        char rxdata = (char)UART_ReadRxData();      //læser data fra uarten

        if(rxdata == 0 || rxdata == '\n' || rxdata == '\r' || stringRX_len == 255)   //hvis der ikke er data eller stringen er afsluttet eller stringRX_len er 255 så:
        {
            stringRX[stringRX_len] = 0;     //buffer sættes til 0 på index stringRX_len
            RXnewData = 1;                  //RXnewData sættes til 1 for at enable interrupt
            return;
        }
        
        stringRX[stringRX_len] = rxdata;    //data fra uarten skrives ind i stringRX med index stringRX_len
        stringRX_len++;  
    }
}

char getStringFromUart(char *data)
{
    
    uint8 i;
    
    if(!RXnewData)
        return 0;
    
    updateBuf();
        
    for(i = 0; i<stringRX_len; i++)     //string fra uarten skrives ind i data
    {
        data[i] = stringRX[i];  
        stringRX[i] = 0;
    }
    data[stringRX_len] = 0;
    stringRX_len = 0;
    RXnewData = 0;                      //interrupt resettes
    
    return strlen(data);
}

uint8 findResponse(char *textToFind)
{
    uint8 textToFindLength = strlen(textToFind);    //finder længden af den text man gerne vil finde
    uint8 index = 0;
    char currentChar;
    
    while((currentChar = UART_GetChar()) != 0)      //læser data fra uarten
    {
        if(currentChar == textToFind[index])        //Hvis den currentChar matcher én char fra uarten ved plads af index
        {
            if(++index >= textToFindLength)         //så incrementeres index for at læse næste plads 
                return 1;                           //og der ses om index er større eller lig med end længden af den text man vil finde, derved returneres true
        }
        else
            index = 0;                              //hvis den char man ser på ikke er lig med den man vil finde resettes index og der læses forfra.
    }
    return 0;                                       //hvis ingen text findes returneres false
}

int connectToWiFi(char *wifiSSID, char *wifiPASS)
{
    char sendString[255];                                            //char array på 64 pladser, så det kan have texten som bliver kopieret fra sprintf()
    sprintf(sendString,"AT+CWJAP=\"%s\",\"%s\"\r\n",wifiSSID, wifiPASS);    //tilslut net med SSID og PASS --> gemmes i sendString
    UART_PutString(sendString);                                     //sendString printes på uarten
    CyDelay(5000);
    if(findResponse("OK"))
    {
        CyDelay(100);
        return 1;
    }
    else
        return 0;
}

int connectToDevKit(char *DevKitIPAdress)
{
    char sendString[255];
    sprintf(sendString,"AT+CIPSTART=\"TCP\",\"%s\",%d\r\n",DevKitIPAdress, DevKitPortNr); //tilslut net med SSID og PASS --> gemmes i sendstring
    CyDelay(500);
    UART_PutString(sendString);                                                     //sendString printes på uarten
    CyDelay(1000);
    if(findResponse("OK"))
    {
        CyDelay(100);
        return 1;
    }
    else
        return 0;
}

void sendDataDevkit(char *dataToSend)
{
    char sendString[255];                               //char array på 254 chars, muligt at højst sende 1024 bytes på én gang. 
    uint16 length=0;
    length=strlen(dataToSend);                          //længden af den mængde data man vil sende
    sprintf(sendString,"AT+CIPSEND=%d\r\n",length);     //AT kommando for at sende, syntax er AT+CIPSEND=length, dvs. det antal bytes man vil sende
    UART_PutString(sendString);                         //sendString printes på uarten
    CyDelay(100);
    if(findResponse("link"))                            //hvis den ikke er forbundet, forbinder den sig selv til portnr / Ip og sender beskeden igen når der er forbindelse
    {
        CyDelay(300);
        if(connectToDevKit(DevKitIP))                   //forbinder til net
        {
            while(findResponse("OK"));                  //venter på OK svar
            UART_PutString(sendString);
            CyDelay(100);
            UART_PutString(dataToSend);
        }
    }
    else
    {
        CyDelay(100);
        UART_PutString(dataToSend);                     //printer hvis den er forbundet til serveren
    }
}

uint8 receiveDataDevKit(char *inputString, char *data)
{
    getStringFromUart(inputString);
    //Tjekker om starten af den modtagende string starter med +IPD
    char IPD[] = "+IPD";
    uint8 i;
    for(i= 0; i<4; i++)
    {
        if(IPD[i] != inputString[i])
            return 0;
    }

    //Så længde man ikke mødder ":" i inputString læses dataene over i bytesLength_char så der vides hvilken længde data'en er på
    char bytesLength_char[4];
    uint8 len = 0;
    uint8 bytesPos = 0;
    uint8 dataPos = 0;
    while(inputString[(bytesPos + 5)]!=':')
    {
        bytesLength_char[bytesPos] = inputString[bytesPos+5];
        bytesPos++;
    }
    bytesLength_char[bytesPos] = 0;

    //mængde data aflæses og gemmes i len
    len = atoi(bytesLength_char);
    if(len <= 0)
        return 0;
    
    //data overføres fra den modtagne string og over i 
    bytesPos++;
    dataPos = bytesPos + 5;
    for(i=0; i<len; i++)        //f.eks. +IPD,8:Hello123   --> len = 8.                  
    {
           data[i] = inputString[(i+dataPos)];
    }
    
    data[dataPos + len] = 0;        //afslutter arrayet ved pladsen efter det sidst modtagne data.
    
    return len;
}


void updatePlantData(char* inputString)      //det er kun Moisture og Rotate der kan sættes, resten valideres bare
{
    int i = 0;
    
    char dataBuf[255];  ///string med data modtaget fra DevKittet
//    char dataType[4];
    char value_char[8];
    uint8 plantIDLocal;

    while(receiveDataDevKit(inputString,dataBuf) == 0u);
    //M1065R1099
//    dataType[0] = dataBuf[0];       //Moist
//    dataType[1] = dataBuf[5];       //Rotate
    plantIDLocal = dataBuf[1];        //'1' i ascii er = 49 i decimal, derfor minus med decimal48 for at få 1. NEVERMIND.
    
    for(i=0;i<3;i++)
        value_char[i] = dataBuf[i+2];   //Tager moist value
    for(i=0;i<3;i++)
        value_char[i+3] = dataBuf[i+7]; //tager rotate value
        
    value_char[6] = 0;
    
    if (plantIDLocal >= 0)
    {
        plantID = plantIDLocal;
        setPlantData(value_char);
    }
    else
        return; 
}

void setPlantData(char *plantValue)
{
    int i;
    uint8 valueMoist = 0;
    uint8 valueRotate = 0;
    char plantMoist[4];
    char plantRotate[4];
    
    for(i=0;i<3;i++)
        plantMoist[i] = plantValue[i];
    
    for(i=0;i<3;i++)
        plantRotate[i] = plantValue[i+3];
    
    plantMoist[3] = 0;
    plantRotate[3] = 0;

    valueMoist = atoi(plantMoist);       //data fra dataBuf læses fra pladserne [2-4] hvor der kan stå 0-999 som pr. protocol definitionen. Laves fra char til int.
    valueRotate = atoi(plantRotate);     //
    
        if(valueMoist >=10 && valueMoist <=100)             //moisture samt rotate validering
            wantedMoisture = valueMoist;
        else
            UART_PutString("Value outside permitted plant set data for Moist\r\n");       //debugging

        if(valueRotate >=0 && valueRotate <= 100)
            wantedRotate = valueRotate;
        else
            UART_PutString("Value outside permitted plant set data for Rotate\r\n");       //debugging
}

void testSendSensorData(uint8 moist,uint8 water,uint8 light,uint8 battery,uint8 tempe)
{
    char sendString[128]; //lokal string til behandling af sprintf
    //Sender alt i 1 lang string
    char moistureString[16];
    char waterString[16];
    char lightString[16];
    char batteryString[16];
    char temperatureString[16];
    
    //Moisture fejlhåndtering
    if(moist > 99)
        sprintf(moistureString,"M%c%d",plantID,moist);
    else if(moist <= 99 && moist >= 10)
        sprintf(moistureString,"M%c0%d",plantID,moist);
    else if(moist < 10 && moist >=0)
        sprintf(moistureString,"M%c00%d",plantID,moist);
        
    //Water fejlhåndtering    
    if(water > 99)
        sprintf(waterString,"W%c%d",plantID,water);
    else if(water <= 99 && water >= 10)
        sprintf(waterString,"W%c0%d",plantID,water);
    else if(water < 10 && water >=0)
        sprintf(waterString,"W%c00%d",plantID,water);
    
    //Light fejlhåndtering    
    if(light > 99)
        sprintf(lightString,"L%c%d",plantID,light);
    else if(light <= 99 && light >= 10)
        sprintf(lightString,"L%c0%d",plantID,light);
    else if(light < 10 && light >=0)
        sprintf(lightString,"L%c00%d",plantID,light);
        
    //Battery fejlhåndtering    
    if(battery > 99)
        sprintf(batteryString,"B%c%d",plantID,battery);
    else if(battery <= 99 && battery >= 10)
        sprintf(batteryString,"B%c0%d",plantID,battery);
    else if(battery < 10 && battery >=0)
        sprintf(batteryString,"B%c00%d",plantID,battery);
         
    //Temperature fejlhåndtering    
    if(tempe > 99)
        sprintf(temperatureString,"T%c%d",plantID,tempe);
    else if(tempe <= 99 && tempe >= 10)
        sprintf(temperatureString,"T%c0%d",plantID,tempe);
    else if(tempe < 10 && tempe >=0)
        sprintf(temperatureString,"T%c00%d",plantID,tempe);
        
    sprintf(sendString,"%s%s%s%s%s",moistureString,waterString,lightString,batteryString,temperatureString);
    sendDataDevkit(sendString);            
    updatePlantData(uartString);

    CyDelay(500);
    UART_PutString("AT+CIPCLOSE\r\n");  //lukker forbindelse til tcp serveren(devkit)
}

void sendSensorData(struct updateParameters sensors) // OBS der er tilføjes et mellemrum " " i slutningen af de forksellige data forsendelser!!!!!!!
{
    char sendString[128]; //lokal string til behandling af sprintf
    //Sender alt i 1 lang string
    char moistureString[16];
    char waterString[16];
    char lightString[16];
    char batteryString[16];
    char temperatureString[16];
    
    //Moisture fejlhåndtering
    if(sensors.currentMoisture > 99)
        sprintf(moistureString,"M%c%d",plantID,sensors.currentMoisture);
    else if(sensors.currentMoisture <= 99 && sensors.currentMoisture >= 10)
        sprintf(moistureString,"M%c0%d",plantID,sensors.currentMoisture);
    else if(sensors.currentMoisture < 10 && sensors.currentMoisture >=0)
        sprintf(moistureString,"M%c00%d",plantID,sensors.currentMoisture);
        
    //Water fejlhåndtering    
    if(sensors.currentWater > 99)
        sprintf(waterString,"W%c%d",plantID,sensors.currentWater);
    else if(sensors.currentWater <= 99 && sensors.currentWater >= 10)
        sprintf(waterString,"W%c0%d",plantID,sensors.currentWater);
    else if(sensors.currentWater < 10 && sensors.currentWater >=0)
        sprintf(waterString,"W%c00%d",plantID,sensors.currentWater);
    
    //Light fejlhåndtering    
    if(sensors.currentLight > 99)
        sprintf(lightString,"L%c%d",plantID,sensors.currentLight);
    else if(sensors.currentLight <= 99 && sensors.currentLight >= 10)
        sprintf(lightString,"L%c0%d",plantID,sensors.currentLight);
    else if(sensors.currentLight < 10 && sensors.currentLight >=0)
        sprintf(lightString,"L%c00%d",plantID,sensors.currentLight);
        
    //Battery fejlhåndtering    
    if(sensors.currentBattery > 99)
        sprintf(batteryString,"B%c%d",plantID,sensors.currentBattery);
    else if(sensors.currentBattery <= 99 && sensors.currentBattery >= 10)
        sprintf(batteryString,"B%c0%d",plantID,sensors.currentBattery);
    else if(sensors.currentBattery < 10 && sensors.currentBattery >=0)
        sprintf(batteryString,"B%c00%d",plantID,sensors.currentBattery);
         
    //Temperature fejlhåndtering    
    if(sensors.currentTemperature > 99)
        sprintf(temperatureString,"T%c%d",plantID,sensors.currentTemperature);
    else if(sensors.currentTemperature <= 99 && sensors.currentTemperature >= 10)
        sprintf(temperatureString,"T%c0%d",plantID,sensors.currentTemperature);
    else if(sensors.currentTemperature < 10 && sensors.currentTemperature >=0)
        sprintf(temperatureString,"T%c00%d",plantID,sensors.currentTemperature);
        
    sprintf(sendString,"%s%s%s%s%s",moistureString,waterString,lightString,batteryString,temperatureString);
    sendDataDevkit(sendString);            
    updatePlantData(uartString);

    CyDelay(500);
    UART_PutString("AT+CIPCLOSE\r\n");  //lukker forbindelse til tcp serveren(devkit)  
}

void initPSoCWiFi(char *wifiSSID, char *wifiPASS, char *DevKitIPAdress) //Opstart af WiFi modul tager ~10-12 sekunder pga. delays
{
    int i = 0;
   
    CyGlobalIntEnable;                          //enabler global interrupt
    isr_UART_StartEx(UART_ISR);                 //initierer en bruger defineret interrupt service: UART_ISR, på intern pin: isr_UART
    UART_Start();                               //Initier UARTEN

    UART_PutString("AT+CIPCLOSE\r\n");
    CyDelay(500);
    
    UART_PutString("AT+RST\r\n");
    CyDelay(3000);
    
    UART_PutString("AT+CWMODE=3\r\n");          //WiFI mode sættes til AP+station mode
    CyDelay(500);
    
    for(i=0;i<3;i++)
    {
        if(connectToWiFi(wifiSSID,wifiPASS))    //forbinde til WiFi
            break;
    }
   
    CyDelay(100);
    for(i=0;i<2;i++)                            //forbinde til DevKit
    {
        if(connectToDevKit(DevKitIPAdress))
            break;
    }
    CyDelay(1000);
}

void tick()   
{

    char sendString[128];                        //temp string til at handle lidt printning -- fjernes senere ved endelig prog
    if(getStringFromUart(uartString) != 0)
    {
        
        if(strcmp(uartString,"GG") == 0)
        {
            UART_PutString("Works...");
        }
        else if(strcmp(uartString,"Print all") == 0)
        {
            sprintf(sendString,"Moist:%d Rotate:%d CurMoist:%d CurWater:%d CurBattery:%d CurTemp:%d\r\n",wantedMoisture,wantedRotate,sensors_.currentMoisture,sensors_.currentWater,sensors_.currentBattery,sensors_.currentTemperature);
            UART_PutString(sendString);
        }
        else if(strcmp(uartString,"Print sensor1") == 0)
        {
            updateSensors();
            CyDelay(200);
            
            sendSensorData(sensors_);
        }
        else if(strcmp(uartString,"Print sensor2") == 0)
        {
            testSendSensorData(50,50,70,90,50);
        }
        else if(strcmp(uartString,"Print sensor3") == 0)
        {
           testSendSensorData(65,20,50,120,30);
        }   
        else if(strcmp(uartString,"Update sensor") == 0)
        {
            updateSensors();
        }
        else if(strcmp(uartString,"Receive data") == 0)
        {
            updatePlantData(uartString);
        }
        else if(strcmp(uartString,"Test Pump") == 0)
        {
//            updateSensors();
//            CyDelay(200);
//            
//            sendSensorData(sensors_);
//            while(wantedMoisture < sensors_.currentMoisture)
//                startPumpingWater();
            UART_PutString("Pump is starting\r\n");
            //startPumpingWater();
            Pumpe_Write(1);
            CyDelay(1000);
            updateSensors();
            char fastPrint[16];
            sprintf(fastPrint,"Bat:%d\r\n",sensors_.currentBattery);
            UART_PutString(fastPrint);
            CyDelay(1000);
            updateSensors();
            sprintf(fastPrint,"Bat:%d\r\n",sensors_.currentBattery);
            UART_PutString(fastPrint);
            CyDelay(1000);
            updateSensors();
            sprintf(fastPrint,"Bat:%d\r\n",sensors_.currentBattery);
            UART_PutString(fastPrint);
            CyDelay(1000);
            updateSensors();
            sprintf(fastPrint,"Bat:%d\r\n",sensors_.currentBattery);
            UART_PutString(fastPrint);
            CyDelay(1000);
            updateSensors();
            sprintf(fastPrint,"Bat:%d\r\n",sensors_.currentBattery);
            UART_PutString(fastPrint);
            Pumpe_Write(0);
            
            UART_PutString("Pump is done pumping\r\n");
            
        }
        
            
    }
}

    


/* [] END OF FILE */