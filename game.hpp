#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <limits>
#include "archetypes.hpp"
using namespace std;

extern string playerXName, playerOName;
extern char square[10];
extern Archetype* playerXArchetype;
extern Archetype* playerOArchetype;


extern string winCondition;
extern string winSquares;
extern int gamesPlayed;
extern int playerOneWins;
extern int playerTwoWins;
extern int ties;


void display();
void Reset();
int checkWin();
void gameChoice(bool isTwoPlayer, bool isBattle);
void chooseArchetype(Archetype*& archetype, const string& playerName);
void writeGameReport();


#endif
