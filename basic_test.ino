/* Metal Touch Sensor Module [S042] : http://rdiot.tistory.com/130 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
int pin = 2;
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  pinMode(pin,INPUT);
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S042:Metal Touch");
 
  int val = digitalRead(pin);
 
  lcd.setCursor(0,1);
  lcd.print("digital=" + (String)val + " ");
 
  if(true == IsTouchec(pin))
  {
    lcd.setCursor(0,2);
    lcd.print("IsTouch=Touched   ");
  }
  else
  {    
    lcd.setCursor(0,2);
    lcd.print("IsTouch=None    ");
  }
 
}
 
bool IsTouchec(int p)
{
 int time = 0;
 do
 {
   if (HIGH == digitalRead(p)) return true;
   delay(1);
 } while (time++<15);
 return false;
}
