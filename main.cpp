#include <iostream>
#include <fstream>
#include "game.hpp"
#include "archetypes.hpp"
using namespace std;

int gamesPlayed = 0;
int playerOneWins = 0;
int playerTwoWins = 0;
int ties = 0;
char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
string playerXName = "Player X";
string playerOName = "Player O";
Archetype* playerXArchetype = nullptr;
Archetype* playerOArchetype = nullptr;


void chooseArchetype(Archetype*& archetype, const string& playerName) {
    int choice;
    cout << playerName << ", choose your archetype:\n";
    cout << "1. Swarm: The Swarm can win by occupying all four corners in addition to regular win conditions.\n";
    cout << "2. Pyromancer: The Pyromancer can clear the board once per game, but no more.\n";

    while (true) {
        cout << "Enter your choice (1 or 2): ";
        if (!(cin >> choice) || (choice != 1 && choice != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter 1 or 2.\n";
        } else {
            break;
        }
    }

    if (choice == 1) {
        archetype = new Swarm();
    } else if (choice == 2) {
        archetype = new Pyromancer();
    }
}


void writeGameReport() {
    ofstream reportFile("GameReport.txt");
    if (reportFile.is_open()) {
        reportFile << "Tic-Tac-Toe Game Report\n";
        reportFile << "=======================\n";
        reportFile << "Total games played: " << gamesPlayed << "\n";
        reportFile << "Player One wins: " << playerOneWins << "\n";
        reportFile << "Player Two wins: " << playerTwoWins << "\n";
        reportFile << "Number of ties: " << ties << "\n";
        reportFile.close();
        cout << "Game report saved to 'GameReport.txt'.\n";
    } else {
        cerr << "Error: Could not create game report file.\n";
    }
}


int main() {
    while (true) {
        cout << "\nChoose game mode:\n1. Regular\n2. Battle\n3. Exit\nYour choice: ";
        int mode;

        while (!(cin >> mode) || mode < 1 || mode > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 3: ";
        }

        if (mode == 3) {
            cout << "Thanks for playing! Goodbye.\n";
            break;
        } else if (mode == 1) {
            gameChoice(true, false);
        } else if (mode == 2) {
            chooseArchetype(playerXArchetype, "Player X");
            chooseArchetype(playerOArchetype, "Player O");
            gameChoice(true, true);
        }

        delete playerXArchetype;
        delete playerOArchetype;
        playerXArchetype = playerOArchetype = nullptr;
    }
    return 0;
}

