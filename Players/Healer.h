#ifndef HEALER_H
#define HEALER_H
#include "Player.h"

class Healer : public Player{
public:
    explicit Healer(const string& name) : Player(name, "Healer"){};
    void heal(int health) override;
    void manaApply() override;
//    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif