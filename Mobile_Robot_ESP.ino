/**************************** Libraries ****************************/
/**************************** Libraries ****************************/

#include "DHT.h"                         // DHT Library
#include <WiFi.h>                        // WIFI Library
#include "ThingSpeak.h"                  // Thingspeak Library
#include <WiFiClient.h>                  // WIFI Client Library
#include <BlynkSimpleEsp32.h>            // Blynk Library
#include "Variables.h"                   // Variable File added
#include "Sensors.h"                     // Sensors File added
#include "Functions.h"                   // Functions File added

/**************************** SETUP ****************************/
/**************************** SETUP ****************************/

void setup()                                                                      
{
  Serial.begin(115200);                           // Serial 1 Initialized for testing
  Serial2.begin(115200);                          // Serial Initialized for Sending commands to arduino mega
  pinMode(STATUS_LED, OUTPUT);                                                   
  
  DHT_SEN.begin();                                                               
  WiFi.mode(WIFI_STA);                                                           
  
  Blynk.begin(Auth_Code, Wifi_SSID, Password);         // Blynk Server Initialized
  Blynk.virtualWrite(V10, Alarm);                                                
  Blynk.virtualWrite(V11, Mode);                                                
  
  ThingSpeak.begin(client);                           // Thingspeak Sever Initialized
}

/**************************** LOOP ****************************/
/**************************** LOOP ****************************/

void loop()                                                                      
  Network_Status();                                                              
  Blynk.run();                                                                   
  Read_Sensors();                                                                
  Delay = millis();                                                              

  
//  Co = Co + 1;            // Random data to check the communition between thingspeak and blynk servers
//  Gas = Gas + 2;
//  Hum = Hum + 3;
//  Temp = Temp + 4;
  
  
  if (Delay >= Del_1)                                                                      
  {
    Send_Blynk();                                                                          
    Del_1 = Delay + 1000;
  }
  if (Delay >= Del_2)                                                                      
  {
    Send_ThingSpeak();                                                                    
    Del_2 = Delay + 30000;
  }
}

/**************************** Network_Status ****************************/
/**************************** Network_Status ****************************/

void Network_Status()                                                         
  if (WiFi.status() == WL_CONNECTED && Blynk.connected()) 
  {
    digitalWrite(STATUS_LED, HIGH);
  }
  else 
  {
    digitalWrite(STATUS_LED, LOW);
  }
}
