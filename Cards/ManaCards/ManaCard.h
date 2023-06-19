#ifndef MANA_CARD_H
#define MANA_CARD_H
#include "../Card.h"

class ManaCard : public Card {
public:
    ManaCard();
    void applyEncounter(Player &player) override;
};




#endif