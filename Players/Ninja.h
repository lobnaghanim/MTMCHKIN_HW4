#ifndef NINJA_H
#define NINJA_H
#include "Player.h"

class Ninja : public Player{
public:
    explicit Ninja(const string& name) : Player(name){ };
    void addCoins(int coins) override;
    void wellFall() override;
};

#endif