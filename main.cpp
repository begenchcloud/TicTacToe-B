#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
string winCondition = "";
string winSquares = "";
string playerXName = "Player 1";
string playerOName = "Player 2";

void display();
void gameChoice(bool isTwoPlayer);
void title();
int checkWin();
void Reset();

int main() {
    char mode;

    title();
    display();


    cout << "Choose game mode:\n";
    cout << "1. Two Player\n";
    cout << "Enter 1 to play or 2 to exit: ";
    mode = _getch();

    if (mode == '1') {
        gameChoice(true);
    } else {
        cout << "Invalid choice. Exiting game.\n";
    }

    return 0;
}

void title() {
    cout << "*********************************************\n";
    cout << "            Tic-Tac-Toe Project             \n";
    cout << "*********************************************\n\n";
}

void display() {
    cout << "\n";
    cout << setw(66) << "     |     |     \n";
    cout << setw(50) << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << "  \n";
    cout << setw(66) << "_____|_____|_____\n";
    cout << setw(66) << "     |     |     \n";
    cout << setw(50) << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << "  \n";
    cout << setw(66) << "_____|_____|_____\n";
    cout << setw(66) << "     |     |     \n";
    cout << setw(50) << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << "  \n";
    cout << setw(65) << "     |     |     " << "\n\n";
}

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

void Reset() {
    for (int i = 1; i <= 9; i++) {
        square[i] = '0' + i;
    }

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    playAgain = _getch();

    if (playAgain == 'y' || playAgain == 'Y') {
        display();

        char mode;
        cout << "Choose game mode:\n";
        cout << "1. Two Player\n";
        cout << "Enter 1 to play or 2 to exit: ";
        mode = _getch();

        if (mode == '1') {
            gameChoice(true);
        } else {
            cout << "Invalid choice. Exiting game.\n";
        }

    }
}
