#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

class Treasure : public Card{
public:
    explicit Treasure();
    void applyEncounter(Player &player) override;
    void print(std::ostream &os) const override;
};


#endif