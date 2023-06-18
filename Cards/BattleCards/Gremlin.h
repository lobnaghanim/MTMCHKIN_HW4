#ifndef GREMLIN_H
#define GREMLIN_H
#include "BattleCard.h"

class Gremlin : public BattleCard{
public:
    explicit Gremlin(string name);
    void applyEncounter(Player &player) override;
};

#endif