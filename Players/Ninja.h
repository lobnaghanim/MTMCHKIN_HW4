#include "Player.h"

class Ninja : public Player{
public:
    Ninja(string name) : Player(name){ };
    void addCoins(int coins) override;
};