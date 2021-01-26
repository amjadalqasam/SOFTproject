/**************************** WIFI Crediential ****************************/
/**************************** WIFI Crediential ****************************/

char Wifi_SSID[] = "ALOTAIBI";
char Password[] = "Ruba-2017";

unsigned long myChannelNumber = 1284159;
const char * myWriteAPIKey = "UMRNLE60F3PRP3PM";
char Auth_Code[] = "ghnMXpLQkcadDUb3xr6FBINsIYiH6vVn";

/**************************** PINOUT ****************************/

#define STATUS_LED 2
#define DHT_PIN 4
#define SEN1_PIN 34
#define SEN2_PIN 35
#define DHT_TYPE DHT11

/**************************** OBJECTS ****************************/
/**************************** OBJECTS ****************************/

int Mode = 1;
int Alarm = 1;

long Delay;
long Del_1;
long Del_2;

float Co, Gas, Hum, Temp;

WiFiClient client;
DHT DHT_SEN(DHT_PIN, DHT_TYPE);
