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
//#define DevKitIP "192.168.43.125"          //DevKit IP Adresse
#define DevKitIP "192.168.1.117"
#define DevKitPortNr 8888                  //DevKit Port Nr.
#define SSID "Mom Use This One"             //brugt til test
#define PASS "Laimonasisthebest12345"       //brugt til test

struct updateParameters;
    
/*******************************************FUNKTIONS PROTOTYPER***********************************************/ 
CY_ISR_PROTO(UART_ISR);                                     //interrupt når der er data i RX bufferen (se design).
void updateBuf();                                           //funktion for at updatere receive bufferen og gemme dataet fra bufferen
void initPSoCWifi(char *, char *, char *);                  //initierer ESP8266 modulet, så PSoCen er klar til at modtage/sende data
void updatePlantData(char *);                               //opdaterer setpunktet for en pottes dataType f.eks. [M]oisture
void sendSensorData(struct updateParameters sensors);       //sender sensor data for planter til DevKit -- Her indtastes de referencen som fås fra sensorenes struct
char getStringFromUart(char *);                             //finder strings på UARTen
uint8 receiveDataDevKit(char * , char *);                   //modtager data fra DevKittet gennem wifi
uint8 findResponse(char *);                                 //finder chars på UARTen
void tick();                                 //ÆNDRESZZZ sæt i plantcontrol               //main test program

#endif
/* [] END OF FILE */
