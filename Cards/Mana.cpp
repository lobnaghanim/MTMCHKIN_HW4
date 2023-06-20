#include "Mana.h"

Mana::Mana() : Card("Mana"){}

void Mana::applyEncounter(Player &player) {
    player.manaApply();
}

