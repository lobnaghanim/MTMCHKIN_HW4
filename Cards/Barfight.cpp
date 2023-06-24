#include "Barfight.h"
Barfight::Barfight() : Card("Barfight") {}

void Barfight::applyEncounter(Player &player) {
    player.barFight();
}

void Barfight::print(ostream &os) const {
    return; // do nothing
}
