#include "Treasure.h"

Treasure::Treasure() : Card("Treasure") {}

void Treasure::applyEncounter(Player &player) {
    player.addCoins(10);
}
