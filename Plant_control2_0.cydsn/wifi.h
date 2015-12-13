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
    
/*********************MAKROER***************************/
#define SSID "BB2"                          //Router SSID
#define PASS "brynebork"                    //Router PASSWORD
#define DevKitIP "192.168.1.200"            //DevKit IP Adresse
#define DevKitPortNr 8888                   //DevKit Port Nr.
//#define DevKitIP "192.168.1.60"             //debugging
    
struct responses
{
    uint8 ID;
    uint8 moisture;
    uint8 rotate;
};
    
/*******************************************FUNKTIONS PROTOTYPER***********************************************/ 
void initPSoCWiFi(char *, char *, char *);                          //initierer ESP-12 modulet, så PSoCen kan sende modtage/sende data
struct responses sendSensorData(struct updateParameters sensors);   //sender sensor data til DevKit - Modtager data fra devkit, og returnerer det i form af en struct

#endif
/* [] END OF FILE */
