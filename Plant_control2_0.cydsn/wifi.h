/* =================================================================
 * AUTHOR: Laimonas Ignas bendikas, 3. Semester - projekt gruppe 7.
 * 
 * DESCRIPTION: Koden heri kan få et ESP8266 modul til at oprette 
 *              forbindelse til en server gennem en router(AP) 
 *              og fungere som en client.
 *              Den kan sende og modtage data til og fra serveren.              
 * =================================================================
*/
#ifndef WIFI_H
#define WIFI_H

#include <project.h>
#include <Plantcontrol.h>
    
/*******************************************MAKROER***********************************************************/
#define SSID2 "Lemonade"                    //Router SSID
#define PASS2 "ESPisBEST"                   //Router PASSWORD
//#define DevKitIP "192.168.43.125"            //DevKit IP Adresse
#define DevKitIP "192.168.1.117"
#define DevKitPortNr 8888                   //Port nr. på DevKit
#define SSID "Mom Use This One"             //brugt til test
#define PASS "Laimonasisthebest12345"       //brugt til test
#define DevKitIP2 "192.168.1.117"           //brugt til test
    


//PLANT DATA TEST
//uint8 wantedMoisture = 0;
//uint8 wantedRotate = 0;
//uint8 water = 0;
//uint8 light = 0;
//uint8 temp = 0;
//uint8 battery = 0;
struct updateParameters;
    
/*******************************************FUNKTIONS PROTOTYPER***********************************************/ 
CY_ISR_PROTO(UART_ISR);                                     //interrupt når der er data i RX bufferen (se design).
void updateBuf();                                           //funktion for at updatere receive bufferen og gemme dataet fra bufferen
void initPSoCWiFi(char *, char *, char *);                  //initierer ESP8266 modulet, så PSoCen er klar til at modtage/sende data
void sendDataDevkit(char *);                                //sender data til devkit
void setPlantData(char *);                                  //funktion til at opdatere set punkter for plante data
void updatePlantData(char *);                               //opdaterer setpunktet for en pottes dataType f.eks. [M]oisture
void sendSensorData(struct updateParameters sensors);       //sender sensor data for planter til DevKit -- Her indtastes de referencen som fås fra sensorenes struct
void testSendSensorData(uint8, uint8, uint8, uint8, uint8); //DEBUGGING
void requestDevKitData();                                   //sender en anmodnig til DevKit for at få opdateret plante parametre
char getStringFromUart(char *);                             //finder strings på UARTen
int connectToWiFi(char *, char *);                          //forbinder til WiFi
int connectToDevKit(char *);                                //forbinder til DevKittet
uint8 receiveDataDevKit(char * , char *);                   //modtager data fra DevKittet gennem wifi
uint8 findResponse(char *);                                 //finder chars på UARTen
void tick();    //main test program

#endif
/* [] END OF FILE */
