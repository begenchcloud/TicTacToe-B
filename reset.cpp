#include "game.hpp"
#include <iostream>
using namespace std;

void Reset() {
    for (int i = 1; i <= 9; i++) {
        square[i] = '0' + i;
    }

    char playAgain;
    while (true) {
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        // Validate input
        if (playAgain == 'y' || playAgain == 'Y') {
            int mode;
            while (true) {
                cout << "\nChoose game mode:\n1. Regular\n2. Battle\nYour choice: ";
                cin >> mode;

                if (mode == 1) {
                    gameChoice(true, false);
                    break;
                } else if (mode == 2) {
                    chooseArchetype(playerXArchetype, "Player X");
                    chooseArchetype(playerOArchetype, "Player O");
                    gameChoice(true, true);
                    break;
                } else {
                    cout << "Invalid choice. Please enter 1 for Regular or 2 for Battle.\n";
                }
            }
            break; // Exit "play again" loop after starting a game
        } else if (playAgain == 'n' || playAgain == 'N') {
            // Call the function to write the game report
            writeGameReport();
            cout << "\nThanks for Playing!!!!";
            cout << "\nBye Bye!!!!\n";
            exit(0);
        } else {
            cout << "Invalid input. Please enter 'y' for yes or 'n' for no.\n";
        }
    }
}


