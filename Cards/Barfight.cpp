#include "Cards/Barfight.h"
Barfight::Barfight() : Card("Barfight") {}

void Barfight::applyEncounter(Player &player) {
    player.barFight();
}
