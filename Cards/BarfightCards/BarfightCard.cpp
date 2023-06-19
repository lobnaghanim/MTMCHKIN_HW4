#include "BarfightCard.h"
BarfightCard::BarfightCard() : Card("Barfight") {}

void BarfightCard::applyEncounter(Player &player) {
    player.barFight();
}
