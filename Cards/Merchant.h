#ifndef MERCHANTCARD_H
#define MERCHANTCARD_H

#include "Card.h"

class Merchant : public Card{
public:
    explicit Merchant();
    void applyEncounter(Player &player) override;
    void print(std::ostream &os) const override;
};


#endif