#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;


extern char square[10];
extern string winCondition;
extern string winSquares;
extern string playerXName;
extern string playerOName;


void display();
void gameChoice(bool isTwoPlayer);
void title();
int checkWin();
void Reset();

#endif // GAME_HPP
