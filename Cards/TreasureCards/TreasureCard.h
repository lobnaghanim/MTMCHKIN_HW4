#ifndef TREASURE_H
#define TREASURE_H

#include "Cards/Card.h"
class TreasureCard : public Card{
public:
    explicit TreasureCard(string name);
    void applyEncounter(Player &player);
};


#endif