#include <LiquidCrystal.h> // include lib according to your lcd type

// Constant for my lcd size, adjust to your lcd
#define LCDWIDTH 16
#define LCDHEIGHT 2

int Contrast=0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read(); 
  }
}

void setup() {
  analogWrite(6,Contrast);
  Serial.begin(9600);
  lcd.begin(16, 2); // initialize with your correct lcd size here
  

}

void loop() {
  String var1;
  String var2;
  lcd.clear();
  while (Serial.available() > 0) {
    var1 = Serial.readStringUntil(','); // writes in the string all the inputs till a comma
    Serial.read(); 
    var2 = Serial.readStringUntil(',');
    Serial.read(); 
}
  String pinnedString = var1;
  String scrollingString = var2;
  int pinnedRow = 1;
  int scrollingRow =  0;
  int scrollingSpeed = 200;
  pinAndScrollText(pinnedString, pinnedRow, scrollingString, scrollingRow, scrollingSpeed);

  delay(2000);
  lcd.clear();
  lcd.print("Back");
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