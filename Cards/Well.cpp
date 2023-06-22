#include "Cards/Well.h"
Well::Well() : Card("Well") {}

void Well::applyEncounter(Player &player) {
    player.wellFall();
}

void Well::print(ostream &os) const {
    return; // do nothing
}
