#include <LiquidCrystal.h>
#define SERIAL_BUFFER_SIZE 256

int Contrast = 0;
int row = 0;
int row2 = 1;
int col = 15;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void serialFlush() {
  while (Serial.available() > 0) {
    char t = Serial.read();
  }
}

void printToLCD(const String company, const String ad, const float adTime, int row, int row2, int col, unsigned long previousMillis, unsigned long currentMillis){
  while((currentMillis - previousMillis) < (adTime * 1000)){
    lcd.setCursor(15,0);
    lcd.print(ad);
    lcd.setCursor(15,1);
    lcd.print(company);
    lcd.scrollDisplayLeft();
    delay(225);
    currentMillis = millis();
  }
  lcd.clear();
}

void setup() {
  analogWrite(6, Contrast);
  Serial.begin(9600);
  lcd.begin(16, 2); 

}

void loop() {
  String company;
  String ad;
  String adTime_str;
  float adTime;
  lcd.clear();
  while (Serial.available() > 0) {
    company = Serial.readStringUntil(',');
    ad = Serial.readStringUntil(',');
    adTime_str = Serial.readStringUntil('|');
    adTime = adTime_str.toFloat();
    unsigned long previousMillis = millis();
    unsigned long currentMillis = millis();
    printToLCD(company, ad, adTime, row, row2, col, previousMillis, currentMillis);
  }
  lcd.print("slut");
}