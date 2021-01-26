/**************************** Alarm ****************************/
/**************************** Alarm ****************************/

BLYNK_WRITE(V10)
{
  Alarm = param.asInt();                                                                         
}

/**************************** Mode Selection ****************************/
/**************************** Mode Selection ****************************/

BLYNK_WRITE(V11) 
{
  Mode = param.asInt();                                                                        
  Serial2.print(Mode);                                                                          
}

/**************************** Robotic Vehicle ****************************/
/**************************** Robotic Vehicle ****************************/

BLYNK_WRITE(V12)
{
  int X = param[0].asInt();     // Command Receive from app for Joystick movement
  int Y = param[1].asInt();
  
  if (Y > 612 && X >= 412 && X <= 612)                                                                               
  {
    Serial2.print("F");
  }
  else if (Y < 412 && X >= 412 && X <= 612)                                                                           
  {
    Serial2.print("B");
  }
  else if (X > 612 && Y >= 412 && Y <= 612)                                                                           
  {
    Serial2.print("R");
  }
  else if (X < 412 && Y >= 412 && Y <= 612)                                                                          
  {
    Serial2.print("L");
  }
  else
  {
    Serial2.print("S");                                                                                             // If Joystick at center then send command S to mega to stop car
  }
}
