#include "Gremlin.h"
Gremlin::Gremlin(string name) : BattleCard(name, 5, 2, 10) {}

void Gremlin::applyEncounter(Player &player) {
    if(isAWin(player, *this)) {
        player.levelUp();
        player.addCoins(m_loot);
    }else{
        player.damage(m_damage);
    }
}
