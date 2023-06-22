#ifndef BARFIGHT_CARD_H
#define BARFIGHT_CARD_H
#include "Card.h"

class Barfight : public Card {
public:
    Barfight();
    void applyEncounter(Player &player) override;
    void print(std::ostream &os) const override;
};




#endif