#ifndef WELL_CARD_H
#define WELL_CARD_H

#include "Card.h"

class Well : public Card{
public:
    explicit Well();
    void applyEncounter(Player &player) override;
    void print(std::ostream &os) const override;
};



#endif