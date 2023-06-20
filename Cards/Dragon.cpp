#include "Dragon.h"

Dragon::Dragon() : BattleCard("Dragon", 25, 1000, 100) {}

void Dragon::applyEncounter(Player &player) {
    if(isAWin(player, *this)){
        player.levelUp();
        player.addCoins(m_loot);
    } else {
        player.damage(MAXHP);
    }
}
