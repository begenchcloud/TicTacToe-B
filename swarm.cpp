#include "archetypes.hpp"

string Swarm::getDescription() {
    return "The Swarm can win by occupying all four corners in addition to regular win conditions.";
}

bool Swarm::specialMove(char board[10]) {
    // Swarm has no special move
    return false;
}
