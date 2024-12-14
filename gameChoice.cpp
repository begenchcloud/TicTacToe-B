#include "game.hpp"
#include <iostream>
using namespace std;

void gameChoice(bool isTwoPlayer, bool isBattle) {
    display();

    bool gameOver = false;
    int turn = 1;

    while (!gameOver) {
        string currentPlayer = (turn % 2 != 0) ? playerXName : playerOName;
        Archetype* currentArchetype = (turn % 2 != 0) ? playerXArchetype : playerOArchetype;
        char xo = (turn % 2 != 0) ? 'X' : 'O';

        cout << currentPlayer << "'s turn.\n";

        int choice;
        do {
    cout << "Enter 0 for a special move, or 1-9 to make a regular move: ";
    if (!(cin >> choice) || choice < 0 || choice > 9) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number between 0 and 9.\n";
        continue;
    }

    if (choice == 0 && isBattle && currentArchetype && currentArchetype->specialMove(square)) {
        display();
        break;
    } else if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice) {
        square[choice] = xo;
        display();
        break;
    } else {
        cout << "Invalid move. Try again.\n";
    }
} while (true);


        int result = checkWin();
        if (result == 1) {
            cout << currentPlayer << " wins by " << winCondition << " (" << winSquares << ")!\n";
            if (turn % 2 != 0) {
                playerOneWins++;
            } else {
        playerTwoWins++;
        }
        gamesPlayed++;
        gameOver = true;
        Reset();
        } else if (result == -1) {
            cout << "It's a draw!\n";
            ties++;
            gamesPlayed++;
            gameOver = true;
            Reset();
        }

        turn++;
    }
}
