#include "ManaCard.h"

ManaCard::ManaCard() : Card("Mana"){}

void ManaCard::applyEncounter(Player &player) {
    player.manaApply();
}

