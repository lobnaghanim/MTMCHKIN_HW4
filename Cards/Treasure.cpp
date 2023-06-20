#include "Treasure.h"

Treasure::Treasure() : Card("TreasureCard") {}

void Treasure::applyEncounter(Player &player) {
    player.addCoins(10);
}
