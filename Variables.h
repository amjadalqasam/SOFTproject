/**************************** PINOUT ****************************/
/**************************** PINOUT ****************************/

#define M1_Pin1 4
#define M1_Pin2 5
#define M2_Pin1 6
#define M2_Pin2 7

#define Trig1_Pin 34
#define Echo1_Pin 36
#define Trig2_Pin 38
#define Echo2_Pin 40

#define Trig3_Pin 30
#define Echo3_Pin 32

#define IR1_Pin 31
#define IR2_Pin 33


/**************************** OBJECTS ****************************/
/**************************** OBJECTS ****************************/

int Mode = 1;
int Speed = 110;        // MAX 255

float Limit_1 = 5;
float Limit_2 = 20;
float Limit_3 = 36;
float Limit_4 = 150;

float Duration;
float Distance_1;
float Distance_2;
float Distance_3;


char Msg;
int IR1_State;
int IR2_State;
int Turn_Speed = 230;    // MAX 255
int Delay = 5;
