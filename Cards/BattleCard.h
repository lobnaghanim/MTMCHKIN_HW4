#ifndef BATTLECARD_H
#define BATTLECARD_H

#include "Card.h"



class BattleCard : public Card{
public:
    explicit BattleCard(string name,int force, int loot, int damage);
    int getForce() const;
//    virtual void applyEncounter(Player &player) = 0;
protected:
    int m_force;
    int m_loot;
    int m_damage;

};

bool isAWin(Player &player, BattleCard &card);
#endif