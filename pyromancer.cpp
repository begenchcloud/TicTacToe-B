#include "archetypes.hpp"
#include <cstring>

string Pyromancer::getDescription() {
    return "The Pyromancer can clear the board once per game, but no more.";
}

bool Pyromancer::specialMove(char board[10]) {
    if (specialMoveUsed) return false;
    specialMoveUsed = true;
    for (int i = 1; i <= 9; ++i) board[i] = '0' + i;
    return true;
}
