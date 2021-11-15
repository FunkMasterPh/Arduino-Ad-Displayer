#include <LiquidCrystal.h> // include lib according to your lcd type

// Constant for my lcd size, adjust to your lcd
#define LCDWIDTH 16
#define LCDHEIGHT 2

int Contrast = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void serialFlush() {
  while (Serial.available() > 0) {
    char t = Serial.read();
  }
}

void setup() {
  analogWrite(6, Contrast);
  Serial.begin(9600);
  lcd.begin(16, 2); // initialize with your correct lcd size here


}

void loop() {
  String company;
  String ad;
  String adTime_str;
  int adTime;
  lcd.clear();
  while (Serial.available() > 0) {
    company = Serial.readStringUntil(',');
    //Serial.read();
    ad = Serial.readStringUntil(',');
    //Serial.read();
    adTime_str = Serial.readStringUntil('|');
    Serial.read();
    adTime = adTime_str.toInt();
    Serial.println(adTime);
    String pinnedString = company;
    String scrollingString = ad;
    int pinnedRow = 1;
    int scrollingRow =  0;
    int scrollingSpeed = 200;
    pinAndScrollText(pinnedString, pinnedRow, scrollingString, scrollingRow, scrollingSpeed);
    delay(1000 * adTime);
  }
  
}

/* This procedure pins a given text in the center of a desired row while scrolling from right to left another given text on another desired row.
    Parameters:
    const String &pinnedText: pinned String
    int pinnedRow: desired row for pinned String
    const String &scrollingText: scrolling String
    int scrollingRow: desired row for scrolling String
    int v = scrolling speed expressed in milliseconds
*/
void pinAndScrollText(const String &pinnedText, int pinnedRow, const String &scrollingText, int scrollingRow, int v) {
  int l = pinnedText.length();
  lcd.setCursor(l % 2 == 0 ? LCDWIDTH / 2 - (l / 2) : LCDWIDTH / 2 - (l / 2) - 1, pinnedRow);
  lcd.print(pinnedText);
  int x = LCDWIDTH;
  int n = scrollingText.length() + x;
  int i = 0;
  int j = 0;
  while (n > 0) {
    if (x > 0) {
      x--;
    }
    lcd.setCursor(x, scrollingRow);
    if (n > LCDWIDTH) {
      j++;
      i = (j > LCDWIDTH) ? i + 1 : 0;
      lcd.print(scrollingText.substring(i, j));
    } else {
      i = i > 0 ? i + 1 : 0;
      if (n == scrollingText.length()) {
        i++;
      }
      lcd.print(scrollingText.substring(i, j));
      lcd.setCursor(n - 1, scrollingRow);
      lcd.print(' ');
    }
    n--;
    if (n > 0) {
      delay(v);
    }
  }
}