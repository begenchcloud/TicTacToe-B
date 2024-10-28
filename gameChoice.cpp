#include "game.hpp"

void gameChoice(bool isTwoPlayer) {
    int choice;
    char xo;
    bool playerX = true;

    for (int i = 1; i <= 9; ++i) {
        playerX = (i % 2 != 0);
        if (playerX) {
            xo = 'X';
            cout << "\n" << playerXName << ", enter a number: ";
            choice = _getch() - '0';
        } else {
            if (isTwoPlayer) {
                xo = 'O';
                cout << "\n" << playerOName << ", enter a number: ";
                choice = _getch() - '0';
            }
        }

        if (choice >= 1 && choice <= 9) {
            if (square[choice] == '0' + choice) {
                square[choice] = xo;
                display();

                int result = checkWin();
                if (result == 1) {
                    cout << (playerX ? playerXName : playerOName) << " wins by " << winCondition << " (" << winSquares << ")!\n";
                    Reset();
                    return;
                } else if (result == -1) {
                    cout << "It's a draw!\n";
                    Reset();
                    return;
                }
            } else {
                cout << "Invalid move. Try again." << endl;
                --i;
            }
        } else {
            cout << "Invalid input. Try again.\n";
            --i;
        }
    }
}
