#include "Player.h"

class Healer : public Player{
public:
    Healer(string name) : Player(name){ };
    void heal(int health) override;
};