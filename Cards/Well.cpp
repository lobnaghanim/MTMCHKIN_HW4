#include "Cards/Well.h"
Well::Well() : Card("Well") {}

void Well::applyEncounter(Player &player) {
    player.wellFall();
}
