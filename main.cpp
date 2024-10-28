#include <iostream>
#include "game.hpp"

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
