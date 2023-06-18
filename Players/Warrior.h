#include "Player.h"

class Warrior : public Player {
public:
    Warrior(string name) : Player(name) {};
    int getAttackStrength() const override;
};