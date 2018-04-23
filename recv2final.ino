#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

RH_ASK driver;
//RF uses pin 11
char data1 = '0';
char data2 = '0';
char data3 = '0';
char data4 = '0';
void setup()
{
    Serial.begin(9600); // Debugging only
    if (!driver.init())
         Serial.println("init failed");
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    lcd.begin(16, 2);
    lcd.print("DESIGN PROJECT");
}

void loop()
{
    uint8_t buf[17];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      Serial.println((char*)buf);
      lcd.clear();
      lcd.print("DESIGN PROJECT");
      lcd.setCursor(0, 1);
      lcd.print((char*)buf);
      data1 = buf[0];
      data2 = buf[1];
      data3 = buf[2];
      data4 = buf[3]; 
      /*Serial.print(data1);
      Serial.print(" , ");
      Serial.print(data2);
      Serial.print(" , ");
      Serial.print(data3);
      Serial.print(" , ");
      Serial.print(data4);
      Serial.println(" ");*/
      if(data1 == '1')
        digitalWrite(8, HIGH);
      else
        digitalWrite(8, LOW);
      if(data2 == '1')
        digitalWrite(9, HIGH);
      else
        digitalWrite(9, LOW);
      if(data3 == '1')
        digitalWrite(12, HIGH);
      else
        digitalWrite(12, LOW);
      if(data4 == '1')
        digitalWrite(13, HIGH);
      else
        digitalWrite(13, LOW);
                
    }
      
}
