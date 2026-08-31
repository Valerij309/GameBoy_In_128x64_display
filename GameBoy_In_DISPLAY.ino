#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "mainH.h"
Adafruit_SSD1306 dp(128,64,&Wire,-1);


void setup(){
  if (!dp.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }
  randomSeed(analogRead(A0)+analogRead(A1));
  dp.clearDisplay();
  dp.display();
  for(int i = 2; i <= 5; i++){
    pinMode(i,INPUT);
  }
  EatApple();
}



void loop(){
  dp.clearDisplay();
  move();
  appleApple();
  if(millis() - Timer >= 50){
  dp.fillCircle(xApple, yApple, 4, SSD1306_WHITE);  
  dp.fillCircle(xSnake, ySnake, 5, SSD1306_WHITE);
  dp.display();
  }
}