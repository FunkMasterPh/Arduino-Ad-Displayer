#include <LiquidCrystal.h>
#define MAX_CHARS 340

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char recChars[MAX_CHARS];
char temp[MAX_CHARS];
int Contrast = 0;

char msg[MAX_CHARS] = {0};
float adTime = 0.0;

size_t indx;
void setup() {
  analogWrite(6, Contrast);
  Serial.begin(9600);
  lcd.begin(16, 2); 
}

void loop() {
  recAds();
  splitAds();
}
/*Reads bytes from buffer and adds them to recChars array. 
  Saves amount of bytes read to indx.*/
void recAds(){
  while(Serial.available() > 0) {
    indx = Serial.readBytes(recChars, MAX_CHARS);
  
  }
}
/*Splits array until |.*/
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
/*Splits string into ad message and ad time duration.*/
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
/*Displays message on LCD for 'ad time' seconds.*/
 void printToLCD(unsigned long currMillis, unsigned long prevMillis, char* msg, float adTime){
  while((currMillis - prevMillis) < (adTime * 1000.00)){
    lcd.setCursor(15,0);
    lcd.print(msg);
    lcd.scrollDisplayLeft();
    delay(200);
    currMillis = millis();
  }
  lcd.clear();
}