#include "Cards/BattleCard.h"

BattleCard::BattleCard(string name, int force, int loot, int damage) : Card(name) {
    m_force = force;
    m_loot = loot;
    m_damage = damage;
}

int BattleCard::getDamage() const {
    return m_damage;
}

int BattleCard::getLoot() const {
    return m_loot;
}

int BattleCard::getForce() const {
    return m_force;
}

bool isAWin(Player &player, BattleCard &card){
    return player.getAttackStrength() >= card.getForce();
}

