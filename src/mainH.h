#ifndef MAINH_H
#define MAINH_H

#include <Arduino.h>

#define CELL 8
#define GRID_W (128 / CELL) 
#define GRID_H (64 / CELL)  

extern int button1;
extern int button2;
extern int button3;
extern int button4; 

extern int UP;
extern int RIGHT;
extern int LEFT;
extern int DOWN;

extern int xSnake;
extern int ySnake;
extern int xApple;
extern int yApple;
extern unsigned long Timer;
extern int score;
extern int value;
void EatApple();
void readInputs();
void moveSnake();
void appleApple();

#endif