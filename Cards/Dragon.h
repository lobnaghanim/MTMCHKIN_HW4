#ifndef DRAGON_H
#define DRAGON_H
#include "BattleCard.h"

class Dragon : public BattleCard{
public:
    explicit Dragon();
    void applyEncounter(Player &player) override;
    void print(std::ostream &os) const override;
};

#endif
