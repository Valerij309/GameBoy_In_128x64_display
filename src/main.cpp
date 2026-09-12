#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "mainH.h"

int button1 = 2; 
int button2 = 3; 
int button3 = 4; 
int button4 = 5; 

int UP = 0;
int RIGHT = 0;
int LEFT = 0;
int DOWN = 0;

int xSnake = 5;
int ySnake = 3;
int xApple = 0;
int yApple = 0;
unsigned long Timer = 0;
int score = 0;
int value = 0;
Adafruit_SSD1306 dp(128, 64, &Wire, -1);

void EatApple() {
  xApple = random(0, GRID_W);
  yApple = random(0, GRID_H);
}

void readInputs() {
  if (digitalRead(button4) == 1 && digitalRead(button3) == 0 && digitalRead(button2) == 0 && digitalRead(button1) == 0) {
    UP = 1; RIGHT = 0; DOWN = 0; LEFT = 0;
  }
  if (digitalRead(button3) == 1 && digitalRead(button4) == 0 && digitalRead(button2) == 0 && digitalRead(button1) == 0) {
    UP = 0; RIGHT = 0; DOWN = 1; LEFT = 0;
  }
  if (digitalRead(button2) == 1 && digitalRead(button3) == 0 && digitalRead(button4) == 0 && digitalRead(button1) == 0) {
    UP = 0; RIGHT = 0; DOWN = 0; LEFT = 1;
  }
  if (digitalRead(button1) == 1 && digitalRead(button3) == 0 && digitalRead(button2) == 0 && digitalRead(button4) == 0) {
    UP = 0; RIGHT = 1; DOWN = 0; LEFT = 0;
  }
}

void moveSnake() {
  if (UP == 1) ySnake--;
  if (RIGHT == 1) xSnake++;
  if (DOWN == 1) ySnake++;
  if (LEFT == 1) xSnake--;

  if (xSnake >= GRID_W) xSnake = 0;
  if (xSnake < 0)       xSnake = GRID_W - 1;
  if (ySnake >= GRID_H) ySnake = 0;
  if (ySnake < 0)       ySnake = GRID_H - 1;
}

void appleApple() {
  if (xSnake == xApple && ySnake == yApple) {
    EatApple();
    score++;
  }
}

void SnakeGame() {
  readInputs(); // Continuously check inputs for responsiveness
  
  if (millis() - Timer >= 200) {
    Timer = millis(); 
    moveSnake();
    appleApple();
    
    
    dp.setTextSize(1);
    dp.setTextColor(SSD1306_WHITE);
    dp.setCursor(0, 0);
    dp.print(score);
    dp.fillCircle(xApple * CELL + CELL / 2, yApple * CELL + CELL / 2, CELL / 2 - 1, SSD1306_WHITE); 
    dp.fillRect(xSnake * CELL, ySnake * CELL, CELL, CELL, SSD1306_WHITE);
  }
}
void menuMove(){
  if (digitalRead(button3) == 1 && digitalRead(button3) == 0 && digitalRead(button2) == 0 && digitalRead(button1) == 0) {
    value++;
  }
  if (digitalRead(button4) == 1 && digitalRead(button3) == 0 && digitalRead(button2) == 0 && digitalRead(button1) == 0) {
    value--;
  }
  if(button1 == 1 && digitalRead(button3) == 0 && digitalRead(button2) == 0 && digitalRead(button4) == 0){
    if(value == 1){
      SnakeGame();
    }
  }
}
void setup() {
  if (!dp.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true); 
  }
  
  randomSeed(analogRead(A0) + analogRead(A1));
  
  dp.clearDisplay();
  dp.display();

  for (int i = 2; i <= 5; i++) {
    pinMode(i, INPUT);
  }
  
  EatApple();
}

void loop() {
  dp.clearDisplay();
  dp.setTextSize(1);
  dp.setTextColor(SSD1306_WHITE);
  dp.setCursor(25, 0);
  dp.print("RetroByte Games");
  dp.setCursor(12, 18);
  dp.print("Snake Game");
  menuMove();
  dp.display(); 
}