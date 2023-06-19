#ifndef BARFIGHT_CARD_H
#define BARFIGHT_CARD_H
#include "../Card.h"

class BarfightCard : public Card {
public:
    BarfightCard();
    void applyEncounter(Player &player) override;
};




#endif