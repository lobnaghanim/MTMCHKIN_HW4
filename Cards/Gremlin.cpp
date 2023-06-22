#include "Gremlin.h"
Gremlin::Gremlin() : BattleCard("Gremlin", 5, 2, 10) {}

void Gremlin::applyEncounter(Player &player) {
    if(isAWin(player, *this)) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), m_name);
    }else{
        player.damage(m_damage);
        printLossBattle(player.getName(), m_name);
    }
}

void Gremlin::print(ostream &os) const {
    printMonsterDetails(os, m_force, m_damage, m_loot, false);
}
