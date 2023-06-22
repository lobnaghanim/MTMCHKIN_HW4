#include "Treasure.h"

Treasure::Treasure() : Card("Treasure") {}

void Treasure::applyEncounter(Player &player) {
    player.addCoins(10);
    printTreasureMessage();
}

void Treasure::print(ostream &os) const {
    return; // do nothing
}
