#include "WellCard.h"
WellCard::WellCard(string name) : Card(name) {}

void WellCard::applyEncounter(Player &player) {
    player.wellFall();
}
