#include <LiquidCrystal_I2C.h>

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);  

//other variabel
String nim = "33418120";
String nama = "Raditya Ari P.";

void setup()
{
  // initialize the lcd 
  lcd.init();
  lcd.backlight();
}

void loop()
{
  lcd.setCursor(8,0);
  lcd.print(nim);
  lcd.setCursor(8,1);
  lcd.print(nama);
}
