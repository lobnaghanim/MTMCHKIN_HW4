#ifndef HEALER_H
#define HEALER_H
#include "Player.h"

class Healer : public Player{
public:
    Healer(string name) : Player(name){ };
    void heal(int health) override;
    void manaApply() override;
};

#endif