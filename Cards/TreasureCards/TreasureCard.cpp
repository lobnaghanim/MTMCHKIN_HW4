#include "TreasureCard.h"

TreasureCard::TreasureCard() : Card("TreasureCard") {}

void TreasureCard::applyEncounter(Player &player) {
    player.addCoins(10);
}
