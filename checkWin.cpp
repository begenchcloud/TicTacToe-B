#include "game.hpp"

int checkWin() {
    if (square[1] == square[2] && square[2] == square[3]) {
        winCondition = "the top row";
        winSquares = "1, 2, 3";
        return 1;
    }
    if (square[4] == square[5] && square[5] == square[6]) {
        winCondition = "the middle row";
        winSquares = "4, 5, 6";
        return 1;
    }
    if (square[7] == square[8] && square[8] == square[9]) {
        winCondition = "the bottom row";
        winSquares = "7, 8, 9";
        return 1;
    }
    if (square[1] == square[4] && square[4] == square[7]) {
        winCondition = "the first column";
        winSquares = "1, 4, 7";
        return 1;
    }
    if (square[2] == square[5] && square[5] == square[8]) {
        winCondition = "the second column";
        winSquares = "2, 5, 8";
        return 1;
    }
    if (square[3] == square[6] && square[6] == square[9]) {
        winCondition = "the third column";
        winSquares = "3, 6, 9";
        return 1;
    }
    if (square[1] == square[5] && square[5] == square[9]) {
        winCondition = "the diagonal from top left to bottom right";
        winSquares = "1, 5, 9";
        return 1;
    }
    if (square[3] == square[5] && square[5] == square[7]) {
        winCondition = "the diagonal from top right to bottom left";
        winSquares = "3, 5, 7";
        return 1;
    }

    bool draw = true;
    for (int i = 1; i <= 9; i++) {
        if (square[i] == '0' + i) {
            draw = false;
            break;
        }
    }
    if (draw) return -1;

    return 0;
}
