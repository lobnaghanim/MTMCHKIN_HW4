#ifndef TREASURE_H
#define TREASURE_H

#include "Cards/Card.h"
class TreasureCard : public Card{
public:
    explicit TreasureCard();
    void applyEncounter(Player &player) override;
};


#endif