#ifndef MANA_CARD_H
#define MANA_CARD_H

#include "Card.h"

class Mana : public Card {
public:
    Mana();
    void applyEncounter(Player &player) override;
    void print(std::ostream &os) const override;
};




#endif