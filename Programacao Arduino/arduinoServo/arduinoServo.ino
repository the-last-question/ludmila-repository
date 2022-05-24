#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);
String msg = " ";

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop()
{
   if (Serial.available() > 2){
     Serial.flush();
     lcd.clear();
     msg = Serial.readStringUntil('\n');
   }
  
  delayMicroseconds(10);
  Serial.println(msg);
  
  lcd.setCursor(0,0);
  lcd.print("Distancia: ");
  lcd.setCursor(0,1);
  lcd.print(msg);
  lcd.print(" cm");
}
