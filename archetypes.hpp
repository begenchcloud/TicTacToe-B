#ifndef ARCHETYPES_HPP
#define ARCHETYPES_HPP

#include <string>
using namespace std;

class Archetype {
public:
    virtual string getDescription() = 0;
    virtual bool specialMove(char board[10]) = 0;
    virtual ~Archetype() {}
};

class Swarm : public Archetype {
public:
    string getDescription() override;
    bool specialMove(char board[10]) override;
};

class Pyromancer : public Archetype {
private:
    bool specialMoveUsed = false;
public:
    string getDescription() override;
    bool specialMove(char board[10]) override;
};

#endif
