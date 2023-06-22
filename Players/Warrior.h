#ifndef WARRIOR_H
#define WARRIOR_H
#include "Player.h"

class Warrior : public Player {
public:
    explicit Warrior(const string& name) : Player(name, "Warrior") {};
    int getAttackStrength() const override;
    void barFight() override;
};

#endif