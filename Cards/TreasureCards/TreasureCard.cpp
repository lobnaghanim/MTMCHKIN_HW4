#include "TreasureCard.h"

TreasureCard::TreasureCard(string name) : Card(name) {}

void TreasureCard::applyEncounter(Player &player) {
    player.addCoins(10);
}
