#include "BarfightCard.h"
BarfightCard::BarfightCard() : Card("Barfight Card") {}

void BarfightCard::applyEncounter(Player &player) {
    player.barFight();
}
