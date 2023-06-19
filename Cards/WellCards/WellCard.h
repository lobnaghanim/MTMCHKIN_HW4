#ifndef WELL_CARD_H
#define WELL_CARD_H
#include "Cards/Card.h"

class WellCard : public Card{
public:
    explicit WellCard();
    void applyEncounter(Player &player);
};



#endif