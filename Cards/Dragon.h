#ifndef DRAGON_H
#define DRAGON_H

#include "Cards/BattleCards/BattleCard.h"
class Dragon : public BattleCard{
public:
    explicit Dragon();
    void applyEncounter(Player &player) override;
};

#endif
