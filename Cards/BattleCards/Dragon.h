#ifndef DRAGON_H
#define DRAGON_H

#include "BattleCard.h"
class Dragon : public BattleCard{
public:
    explicit Dragon(string name);
    void applyEncounter(Player &player) override;
};

#endif
