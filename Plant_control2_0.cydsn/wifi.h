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
#define SSID "Lemonade"                    //Router SSID
#define PASS "ESPisBEST"                   //Router PASSWORD
//#define DevKitIP "192.168.43.125"          //DevKit IP Adresse
#define DevKitIP "192.168.43.49"
#define DevKitPortNr 8888                  //DevKit Port Nr.
#define SSID2 "Mom Use This One"             //brugt til test
#define PASS2 "Laimonasisthebest12345"       //brugt til test
 
struct responses
{
    uint8 ID;
    uint8 moisture;
    uint8 rotate;
};
    
/*******************************************FUNKTIONS PROTOTYPER***********************************************/ 
void initPSoCWiFi(char *, char *, char *);                  //initierer ESP8266 modulet, så PSoCen er klar til at modtage/sende data
struct responses sendSensorData(struct updateParameters sensors);       //sender sensor data for planter til DevKit -- Her indtastes de referencen som fås fra sensorenes struct

#endif
/* [] END OF FILE */
