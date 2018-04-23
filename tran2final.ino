#include <SPI.h>
#include <RH_ASK.h>

RH_ASK driver;
char data1 = '0';
char data2 = '0';
char data3 = '0';
char data4 = '0';

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);   // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop() {
  // put your main code here, to run repeatedly:
    if(Serial.available())
    {
      String data = Serial.readString();
      Serial.println(data);
      char char_array[data.length()+1];
      strcpy(char_array, data.c_str()); 
      driver.send((uint8_t *)char_array, strlen(char_array));
      
      data1 = char_array[0];
      data2 = char_array[1];
      data3 = char_array[2];
      data4 = char_array[3];

       if(data1 == '1')
        digitalWrite(2, HIGH);
      else
        digitalWrite(2, LOW);
      if(data2 == '1')
        digitalWrite(3, HIGH);
      else
        digitalWrite(3, LOW);
      if(data3 == '1')
        digitalWrite(4, HIGH);
      else
        digitalWrite(4, LOW);
      if(data4 == '1')
        digitalWrite(5, HIGH);
      else
        digitalWrite(5, LOW);
        
      driver.waitPacketSent();
      delay(1000);
    }
}
