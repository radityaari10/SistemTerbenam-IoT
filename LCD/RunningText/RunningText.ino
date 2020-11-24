#include <LiquidCrystal_I2C.h>

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);  

//other variabel
String nama = "33418120 - Raditya Ari Pradana - D3TI";

void setup()
{
  // initialize the lcd 
  lcd.init();
  lcd.backlight();
}

void loop()
{
  int str = nama.length();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(nama);
  delay(2000);
  for(int counter=0; counter < str; counter++){
    lcd.scrollDisplayLeft();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(17,0);
  lcd.print(nama);
  for(int counter=0; counter < 17; counter++){
    lcd.scrollDisplayLeft();
    if(counter != 16){
      delay(100);
    }else{
      delay(2000);
    }
  }
}
