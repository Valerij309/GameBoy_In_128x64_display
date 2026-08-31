int button1 = 2;
int button2 = 3;
int button3 = 4;
int button4 = 5;
int UP = 0;
int RIGHT = 1;
int LEFT = 0;
int DOWN = 0;
int xSnake = 64;
int ySnake = 32;
int xApple = 0;
int yApple = 0;
unsigned long Timer = 0;
 void move(){
  if(digitalRead(button4) and !digitalRead(button3) and !digitalRead(button2) and !digitalRead(button1)){
    UP = 1;
    RIGHT = 0;
    DOWN = 0;
    LEFT = 0;
  }
  if(digitalRead(button3) and !digitalRead(button4) and !digitalRead(button2) and !digitalRead(button1)){
    UP = 0;
    RIGHT = 0;
    DOWN = 1;
    LEFT = 0;
  }
  if(digitalRead(button2) and !digitalRead(button3) and !digitalRead(button4) and !digitalRead(button1)){
    UP = 0;
    RIGHT = 0;
    DOWN = 0;
    LEFT = 1;
  }
  if(digitalRead(button1) and !digitalRead(button3) and !digitalRead(button2) and !digitalRead(button4)){
    UP = 0;
    RIGHT = 1;
    DOWN = 0;
    LEFT = 0;
  }
    if(UP == 1){
       ySnake--;
    }
    if(RIGHT == 1){
       xSnake++;
    }
    if(LEFT == 1){
      xSnake--;
    }
    if(DOWN ==1){
      ySnake++;
    }
    if(xSnake >= 128){
      xSnake == 0;
    }
    if(ySnake >= 64){
      ySnake == 0;
    }
   }
   void EatApple(){
    xApple = random(0,128);
    yApple = random(0,64);
   }
   void appleApple(){
    if(xSnake == xApple and ySnake == yApple){
      EatApple();
    }
   }














