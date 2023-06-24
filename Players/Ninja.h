#ifndef NINJA_H
#define NINJA_H
#include "Player.h"
#include "../utilities.h"

class Ninja : public Player{
public:
    explicit Ninja(const string& name) : Player(name, "Ninja"){ };
    void addCoins(int coins) override;
    void wellFall() override;
};

#endif