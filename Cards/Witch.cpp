#include "Witch.h"

Witch::Witch() : BattleCard("Witch", 11, 2, 10) {}

void Witch::applyEncounter(Player &player) {
    if(isAWin(player, *this)){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), m_name);
    } else {
        player.damage(10);
        player.buff(-1);
        printLossBattle(player.getName(), m_name);
    }
}
// ostream &os, int force, int damage, int coins, bool isDragon)
void Witch::print(ostream &os) const {
    printMonsterDetails(os, m_force, m_damage, m_loot, false);
}
