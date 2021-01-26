/**************************** Libraries ****************************/
/**************************** Libraries ****************************/

#include "Variables.h"                                                                         
#include "Functions.h"                                                                        
/**************************** SETUP ****************************/
/**************************** SETUP ****************************/

void setup()
{
  Serial.begin(115200);                                                                        
  Serial2.begin(115200);                                                                       
  
  pinMode(IR1_Pin, INPUT);                                                                   
  pinMode(IR2_Pin, INPUT);                                                                     
  
  pinMode(Echo1_Pin, INPUT);                                                                   
  pinMode(Echo2_Pin, INPUT);                                                                    
  pinMode(Echo3_Pin, INPUT);                                                                    

  pinMode(Trig1_Pin, OUTPUT);                                                                
  pinMode(Trig2_Pin, OUTPUT);                                                                   
  pinMode(Trig3_Pin, OUTPUT);                                                                    

  pinMode(M1_Pin1, OUTPUT);                                                                      
  pinMode(M1_Pin2, OUTPUT);                                                                      
  pinMode(M2_Pin1, OUTPUT);                                                                      
  pinMode(M2_Pin2, OUTPUT);                                                                    

  Stop();           // Stop Function Called to stop the car at start
}

/**************************** LOOP ****************************/
/**************************** LOOP ****************************/

void loop()                                                                                                                                     
{
  Data_Received();              // Data receiver Function Called
  Mode_3();                                                                                                                                    
  Mode_4();                                                                                                                                     
  Mode_5();                                                                                                                                     
}

/**************************** Data_Received ****************************/
/**************************** Data_Received ****************************/

void Data_Received()                                                                                                                                             
{
  while (Serial2.available() > 0)                                                                              
  {
    Msg = Serial2.read();                                                                                            
    Serial.print(Msg);                                                                                                
    Check_Mode();                                                                                   
    Mode_1();                                                                                                  
    Mode_2();                                                                                                 
  }

/************ THIS PART IS TO TEST THE CODE WORKING ************/
/************ THIS PART IS TO TEST THE CODE WORKING ************/
 
//  if (Mode <=2 && Serial2.available() < 1)
//  {
//    Stop();
//  }
//  Read_IR();
//  Read_Sonar_1();
//  Read_Sonar_2();
//  Read_Sonar_3();
//  Serial.print(IR1_State);
//  Serial.print("  ");
//  Serial.print(IR2_State);
//  Serial.print("  ");
//  Serial.print(Distance_1);
//  Serial.print("  ");
//  Serial.print(Distance_2);
//  Serial.print("  ");
//  Serial.println(Distance_3);

}
