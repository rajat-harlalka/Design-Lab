
#include <SPI.h>
#include <RH_ASK.h>

RH_ASK driver;
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int data1 = 0;
int data2 = 0;
int data3 = 0;
int data4 = 0;
void setup()
{
    Serial.begin(9600);   // Debugging only
    if (!driver.init())
         Serial.println("init failed");
    pinMode(in1, INPUT);
    pinMode(in2, INPUT);
    pinMode(in3, INPUT);
    pinMode(in4, INPUT);
}

void loop()
{
    String string1 = String(digitalRead(in1), DEC);
    String string2 = String(digitalRead(in2), DEC);
    String string3 = String(digitalRead(in3), DEC);
    String string4 = String(digitalRead(in4), DEC);
    String string = string1+string2+string3+string4;
    //char *msg = string;
    const char * msg = string.c_str();
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
}
