/**************************** Read Sensors ****************************/
/**************************** Read Sensors ****************************/

void Read_Sensors()                                                                                              
{
  Co = analogRead(SEN1_PIN);                                                                                  
  Gas = analogRead(SEN2_PIN);                                                                                  
  Hum = DHT_SEN.readHumidity();                                                                              
  Temp = DHT_SEN.readTemperature();                                                                                                     
  Co = Co / 4095 * 100;                                                                                     // Map the sensor value in 0-100 range
  Gas = Gas / 4095 * 100;                                                                                                                

  if (Hum > 75 && Alarm == 1)                                                                              
  {
    Blynk.notify("There is too much moisture in the air");
  }
  if (Temp > 50 && Alarm == 1)                                                                                
  {
    Blynk.notify("Temperature is too High");
  }
  if ((isnan(Hum) || isnan(Temp)) && Alarm == 1)                                                     
  {
    Blynk.notify("Some thing is wrong with your Sensors. Please Check");
  }
}

/********************** Send_Blynk **********************/
/********************** Send_Blynk **********************/

void Send_Blynk()          // Write Sensors data on Vitual pins on Blynk App
{
  Blynk.virtualWrite(V1, Co);
  Blynk.virtualWrite(V2, Gas);
  Blynk.virtualWrite(V3, Hum);
  Blynk.virtualWrite(V4, Temp);
}

/********************** Send_ThingSpeak **********************/
/********************** Send_ThingSpeak **********************/

void Send_ThingSpeak()       // Write Sensor data on Fields on Thingspeak
{
  ThingSpeak.setField(1, Co);
  ThingSpeak.setField(2, Gas);
  ThingSpeak.setField(3, Hum);
  ThingSpeak.setField(4, Temp);

  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);    // Write data on Channel Number and API KEY on channel
  
//  int Resp = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
//  if (Resp == 200)
//  {
//    Serial.println("Update Successful.");
//  }
//  else
//  {
//    Serial.println("Error Code " + String(Resp));
//  }
}
