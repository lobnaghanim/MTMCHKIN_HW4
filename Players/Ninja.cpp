#include "Ninja.h"


void Ninja::addCoins(int coins) {
    Player::addCoins(coins * 2);
}

void Ninja::wellFall() {
    printWellMessage(true);
    // do nothing
}


