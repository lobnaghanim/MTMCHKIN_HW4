#ifndef WELL_CARD_H
#define WELL_CARD_H
#include "Cards/Card.h"

class Well : public Card{
public:
    explicit Well();
    void applyEncounter(Player &player) override;
};



#endif