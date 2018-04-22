#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

int data1 = 0;
int data2 = 0;
int data3 = 0;
int data4 = 0;
void setup()
{
    Serial.begin(9600); // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[12];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
      //Serial.print("Message: ");
      //Serial.println((char*)buf); 
      data1 = buf[0];
      data2 = buf[1];
      data3 = buf[2];
      data4 = buf[3]; 
      Serial.print(data1);
      Serial.print(" , ");
      Serial.print(data2);
      Serial.print(" , ");
      Serial.print(data3);
      Serial.print(" , ");
      Serial.print(data4);
      Serial.println(" ");           
    }    
}
