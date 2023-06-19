#ifndef MERCHANTCARD_H
#define MERCHANTCARD_H

#include "Cards/Card.h"

class MerchantCard : public Card{
public:
    explicit MerchantCard();
    void applyEncounter(Player &player) override;
};


#endif