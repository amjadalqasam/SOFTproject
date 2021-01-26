/**************************** ROBOTIC CAR FUNCTIONS ****************************/
/**************************** ROBOTIC CAR FUNCTIONS ****************************/

void Stop()                                                             
{
  analogWrite(M1_Pin1, 0);
  analogWrite(M1_Pin2, 0);
  analogWrite(M2_Pin1, 0);
  analogWrite(M2_Pin2, 0);
}

void Forward()       // Forward Function to Forward the Car
{
  analogWrite(M1_Pin1, Speed);
  analogWrite(M1_Pin2, 0);
  analogWrite(M2_Pin1, Speed);
  analogWrite(M2_Pin2, 0);
}

void Back()      // Back Function to Back the car
{
  analogWrite(M1_Pin1, 0);
  analogWrite(M1_Pin2, Speed);
  analogWrite(M2_Pin1, 0);
  analogWrite(M2_Pin2, Speed);
}
 
void Left()      // Left Function to Turn the car left
{
  analogWrite(M1_Pin1, 0);
  analogWrite(M1_Pin2, Speed);
  analogWrite(M2_Pin1, Speed);
  analogWrite(M2_Pin2, 0);
}

void Right()    // Right Function to Turn the car right
{
  analogWrite(M1_Pin1, Speed);
  analogWrite(M1_Pin2, 0);
  analogWrite(M2_Pin1, 0);
  analogWrite(M2_Pin2, Speed);
}

/**************************** Read_IR ****************************/
/**************************** Read_IR ****************************/

void Read_IR()    // Function to read both IR Sensors
{
  IR1_State = digitalRead(IR1_Pin);
  IR2_State = digitalRead(IR2_Pin);
}
    
/**************************** Read_Sonar ****************************/
/**************************** Read_Sonar ****************************/

int Read_Sonar_1()             // Function to read Sonar Sensor 1
{
  digitalWrite(Trig1_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig1_Pin, HIGH);                                                                                  
  delayMicroseconds(10);
  digitalWrite(Trig1_Pin, LOW);
  Duration = pulseIn(Echo1_Pin, HIGH);                                                                 
  Distance_1 = Duration / 58.2;                                                                      
}

int Read_Sonar_2()                                                                               
{
  digitalWrite(Trig2_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig2_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig2_Pin, LOW);
  Duration = pulseIn(Echo2_Pin, HIGH);
  Distance_2 = Duration / 58.2;
}

int Read_Sonar_3()                                                                                        
{
  digitalWrite(Trig3_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig3_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig3_Pin, LOW);
  Duration = pulseIn(Echo3_Pin, HIGH);
  Distance_3 = Duration / 58.2;
}

/********************* Check_Mode *********************/
/********************* Check_Mode *********************/

void Check_Mode()                                                                                      
{
  if (Msg == '1')                                                                                                           
  {
    Mode = 1;
  }
  else if (Msg == '2')                                                                                
  {
    Mode = 2;
  }
  else if (Msg == '3')                                                                                           
  {
    Mode = 3;
  }
  else if (Msg == '4')                                                                        
  {
    Mode = 4;
  }
  else if (Msg == '5')                                                                        
  {
    Mode = 5;
  }
}

/********************* Mode_1 *********************/
/********************* Mode_1 *********************/

void Mode_1()                                                                         // Mode 1 Function (User mode) 
{
  if (Mode == 1)                                                                          
  {
    if (Msg == 'F')                                                                      
    {
      Forward();                                                                         
    }
    else if (Msg == 'B')                                                                  
    {
      Back();                                                                             
    }
    else if (Msg == 'R')                                                                   
    {
      Right();                                                                              
    }
    else if (Msg == 'L')                                                                    
    {
      Left();                                                                               
    }
    else                                                                                                                                          
    {
      Stop();                                                                                                                                  
    }
  }
}

/********************* Mode_2 *********************/
/********************* Mode_2 *********************/

void Mode_2()                 // Mode 2 Function (Semi auto mode) 
{
  if (Mode == 2)           // check if mode is set to 2, if yes then continue the loop otherwise exit it
  {
    if (Msg == 'F')                                                                                                                                 
    {
      Read_Sonar_1();      // then first check for obstacle
      Read_Sonar_2();     // then first check for obstacle
      if ((Distance_1 <= Limit_2 && Distance_1 > Limit_1) || (Distance_2 <= Limit_2 && Distance_2 > Limit_1))
      {               // if detected, then car will not run otherwise move the car Forward
        Stop();
        return;
      }
      Forward();
    }
    else if (Msg == 'B')                                                                    
    {
      Read_Sonar_3();                                                                                                                        
      if (Distance_3 <= Limit_2 && Distance_3 > Limit_1)    //if detected, then car will not run otherwise move the car Backward
      {
        Stop();
        return;
      }
      Back();                                                                            
    }

    else if (Msg == 'R')                                                                 
    {
      Right();                                                                             
    }
    else if (Msg == 'L')                                                                   
    {
      Left();                                                                              
    }
    else if (Msg == 'S')                                                                 
    {
      Stop();                                                                             
    }
  }
}

/********************* Mode_3 *********************/
/********************* Mode_3 *********************/

void Mode_3()  // Mode 3 Function (Line follwing mode) In this mode car will follow the black Line
{
  if (Mode == 3)    // check if mode is set to 3, if yes then continue the loop otherwise exit it
  {
    Read_IR();              // Read IR Sensos (Function called)
    if (IR1_State == HIGH && IR2_State == LOW)                                                                 
    {
      analogWrite(M1_Pin1, Turn_Speed);
      analogWrite(M1_Pin2, 0);
      analogWrite(M2_Pin1, Speed);
      analogWrite(M2_Pin2, 0);
      delay(Delay);
    }
    if (IR1_State == LOW && IR2_State == HIGH)                                                                 
      analogWrite(M1_Pin1, Speed);
      analogWrite(M1_Pin2, 0);
      analogWrite(M2_Pin1, Turn_Speed);
      analogWrite(M2_Pin2, 0);
      delay(Delay);
    }
                                                       
    if (IR1_State == LOW && IR2_State == LOW)  // If Both sensors detect white car will move Forward (Both sides wheels rotate with same speed)
    {
      analogWrite(M1_Pin1, Speed);
      analogWrite(M1_Pin2, 0);
      analogWrite(M2_Pin1, Speed);
      analogWrite(M2_Pin2, 0);
      delay(Delay);
    }

    if (IR1_State == HIGH && IR2_State == HIGH)     // If Both sensors detect Black car will Stop (means finish line)
    {
      analogWrite(M1_Pin1, 0);
      analogWrite(M1_Pin2, 0);
      analogWrite(M2_Pin1, 0);
      analogWrite(M2_Pin2, 0);
      delay(Delay);
    }
  }
}

/********************* Mode_4 *********************/
/********************* Mode_4 *********************/

void Mode_4()       // Mode 4 Function (Follow Me mode) In this mode car will follow the object/person and maintain a specific distance from object or person 
{
  if (Mode == 4)        // check if mode is set to 4, if yes then continue the loop otherwise exit it
  {
    Read_Sonar_1();                         
    Read_Sonar_2();                       
    if ((Distance_1 >= Limit_3 && Distance_1 < Limit_4) && (Distance_2 >= Limit_3 && Distance_2 < Limit_4))
    {                                // check if distance is greater than limit car will move forward
      Forward();
    }
    else if ((Distance_1 >= Limit_2 && Distance_1 < Limit_3) && (Distance_2 >= Limit_2 && Distance_2 < Limit_3))
    {                                // check if distance is in limit car will stop
      Stop();
    }
    else if ((Distance_1 >= Limit_1 && Distance_1 < Limit_2) && (Distance_2 >= Limit_1 && Distance_2 < Limit_2))
    {                                // check if distance is Lesser than limit car will move Back
      Back();
    }
  }
}
