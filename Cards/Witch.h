#ifndef WITCH_H
#define WITCH_H
#include "Cards/BattleCards/BattleCard.h"

class Witch : public BattleCard{
public:
    explicit Witch();
    void applyEncounter(Player &player) override;
};

#endif