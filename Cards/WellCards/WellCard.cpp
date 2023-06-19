#include "WellCard.h"
WellCard::WellCard() : Card("Well Card") {}

void WellCard::applyEncounter(Player &player) {
    player.wellFall();
}
