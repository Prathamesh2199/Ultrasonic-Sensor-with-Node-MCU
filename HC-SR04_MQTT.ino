//===================================================================
// Author  :Techs & Crafts
// Project : Ultrasonic value Display in Cloud using cayenne (MQTT)
//
//
//==================================================================

#include <CayenneMQTTESP8266.h>                                     // Include library file for MQTT
#include "Ultrasonic.h"                                             // Include library file for ultrasonic (HC-SR04)

Ultrasonic ultrasonic(14,12);                                       // Assign Trig PIN 14(D5),Assign Echo PIN 12(D6)

char ssid[] = "Prathamesh";                                           // Your WIFI Name   
char wifiPassword[] = "prathamesh11";                                   // Your WIFI password
char username[] = "223a9160-69a7-11ea-8221-599f77add412";           // Your MQTT cayenne username
char Password[] = "4e6ba7698692b10483cef05a4b03402517fcd5d0 ";       // Your MQTT cayenne Password
char clientID[] = "3d4aab20-69a7-11ea-b301-fd142d6c1e6c";       // Your MQTT cayenne clientID
int GIu_Ultrasonic_Dist_CM=0;

//=====================Basic Setup ============================

void setup(){  
   Serial.begin(9600);                                              // Setup Debug uart port if you want ?
   Cayenne.begin(username, Password, clientID, ssid, wifiPassword); // Setup cayenne server for MQTT protocol
}

void loop() 
  {
      delay(2000);
      GIu_Ultrasonic_Dist_CM=ultrasonic.Ranging(CM);                 // Read ultrasonic distance value in CM or INCH
      Cayenne.virtualWrite(V7, GIu_Ultrasonic_Dist_CM);              // Post Distance value in cayenne mqtt server
      Serial.print(GIu_Ultrasonic_Dist_CM); 
      Serial.println(" cm" );
      Cayenne.loop();
  }
//==================================================================
