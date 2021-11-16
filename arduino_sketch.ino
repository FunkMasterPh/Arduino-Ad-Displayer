#include <LiquidCrystal.h>
#define MAX_CHARS 250

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char recChars[MAX_CHARS];
char temp[MAX_CHARS];

char msg[MAX_CHARS] = {0};
float adTime = 0.0;

size_t indx;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); 
}

void loop() {
  recAds();
  splitAds();
}

void recAds(){
  while(Serial.available() > 0) {
    indx = Serial.readBytes(recChars, MAX_CHARS);
  }
}

void splitAds(){
  int j = 0;
  for(int i = 0; i < indx; i++){
    temp[j] = recChars[i];
    j++;
    if(recChars[i] == '|'){
      parseData();
      j = 0;
    }
  }
}

void parseData(){
  char* strtokIndx;
  strtokIndx = strtok(temp, ",");
  strcpy(msg, strtokIndx);
  strtokIndx = strtok(NULL, "|");
  adTime = atof(strtokIndx);
  unsigned long currMillis = millis();
  unsigned long prevMillis = millis();
  printToLCD(currMillis, prevMillis, msg, adTime);
 }

 void printToLCD(unsigned long currMillis, unsigned long prevMillis, char* msg, float adTime){
  while((currMillis - prevMillis) < (adTime * 1000.00)){
    lcd.setCursor(15,0);
    lcd.print(msg);
    lcd.scrollDisplayLeft();
    delay(225);
    currMillis = millis();
  }
  lcd.clear();
}
