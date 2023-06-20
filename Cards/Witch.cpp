#include "Witch.h"

Witch::Witch() : BattleCard("Witch", 11, 2, 10) {}

void Witch::applyEncounter(Player &player) {
    if(isAWin(player, *this)){
        player.levelUp();
        player.addCoins(m_loot);
    } else {
        player.damage(10);
        this->m_force -= 1;
    }
}
