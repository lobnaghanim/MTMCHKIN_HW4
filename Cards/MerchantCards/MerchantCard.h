#ifndef MERCHANTCARD_H
#define MERCHANTCARD_H

#include "Cards/Card.h"

class MerchantCard : public Card{
public:
    explicit MerchantCard(string name);
    void applyEncounter(Player &player);
};


#endif