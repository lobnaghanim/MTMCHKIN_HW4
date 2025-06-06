#ifndef WITCH_H
#define WITCH_H

#include "BattleCard.h"

class Witch : public BattleCard{
public:
    explicit Witch();
    void applyEncounter(Player &player) override;
    void print(std::ostream &os) const override;
};

#endif