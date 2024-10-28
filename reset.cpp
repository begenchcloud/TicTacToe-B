#include "game.hpp"

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
    } else {
        cout << "\nThanks for Playing!!!!";
        cout << "\nBye Bye!!!!";
    }
}
