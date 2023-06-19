#include "WellCard.h"
WellCard::WellCard() : Card("Well") {}

void WellCard::applyEncounter(Player &player) {
    player.wellFall();
}
