#include "Dragon.h"

Dragon::Dragon() : BattleCard("Dragon", 25, 1000, 100) {}

void Dragon::applyEncounter(Player &player) {
    if(isAWin(player, *this)){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), m_name);
    } else {
        player.damage(MAXHP);
        printLossBattle(player.getName(), m_name);
    }
}

void Dragon::print(ostream &os) const {
    printMonsterDetails(os, m_force, m_damage, m_loot, true);
}
