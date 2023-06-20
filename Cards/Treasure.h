#ifndef TREASURE_H
#define TREASURE_H

#include "Cards/Card.h"
class Treasure : public Card{
public:
    explicit Treasure();
    void applyEncounter(Player &player) override;
};


#endif