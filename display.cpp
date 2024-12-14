#include "game.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

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
