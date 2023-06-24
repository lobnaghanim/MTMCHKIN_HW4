#include "BattleCard.h"

BattleCard::BattleCard(string name, int force, int loot, int damage) : Card(name) {
    m_force = force;
    m_loot = loot;
    m_damage = damage;
}


int BattleCard::getForce() const {
    return m_force;
}

bool isAWin(Player &player, BattleCard &card){
    return player.getAttackStrength() >= card.getForce();
}

