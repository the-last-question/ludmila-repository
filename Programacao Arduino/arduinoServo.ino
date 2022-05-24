#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);
String msg = " ";
String ant = " ";
double total = 0;
double total_t = 0;
int cont = 0;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop()
{
   if (Serial.available() > 2){
     Serial.flush();
     msg = Serial.readStringUntil('\n');
     total += msg.toFloat();
     cont += 1;
   }
  
  if(cont == 5){
     msg = " ";
     lcd.clear();
     total_t = (total/ 5) - 0.2;
     cont = 0;
     total = 0;
  }
  
  Serial.println(total_t);
  
  lcd.setCursor(0,0);
  lcd.print("Distancia: ");
  lcd.setCursor(0,1);
  
  lcd.print(total_t);
}
