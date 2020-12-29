/**************************** Libraries ****************************/
/**************************** Libraries ****************************/

#include <DHT.h>
#include <WiFi.h>
#include <Servo.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "Variables.h"
#include "Functions.h"

/**************************** SETUP ****************************/
/**************************** SETUP ****************************/

void setup()
{
  Serial.begin(9600);

  pinMode(M1_PIN1, OUTPUT);
  pinMode(M1_PIN2, OUTPUT);
  pinMode(M2_PIN1, OUTPUT);
  pinMode(M2_PIN2, OUTPUT);

  Stop();
  
  Base.attach(Base_PIN);
  Shoulder.attach(Shoulder_PIN);
  Elbow.attach(Elbow_PIN);
  Wrist.attach(Wrist_PIN);
  Roll.attach(Roll_PIN);
  Gripper.attach(Gripper_PIN);
  
  Blynk.begin(Auth_Code, Wifi_SSID, Password);
  Clock.setInterval(100L, Send_Data);
}

/**************************** LOOP ****************************/
/**************************** LOOP ****************************/

void loop()
{
  Blynk.run();
  Clock.run();
}
