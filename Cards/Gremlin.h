#ifndef GREMLIN_H
#define GREMLIN_H
#include "BattleCard.h"

class Gremlin : public BattleCard{
public:
    explicit Gremlin();
    void applyEncounter(Player &player) override;
    void print(std::ostream &os) const override;
};

#endif