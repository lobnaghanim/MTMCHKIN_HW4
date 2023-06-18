#ifndef NINJA_H
#define NINJA_H
#include "Player.h"

class Ninja : public Player{
public:
    Ninja(string name) : Player(name){ };
    void addCoins(int coins) override;
};

#endif