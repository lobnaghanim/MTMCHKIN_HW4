#include "Ninja.h"
#include "utilities.h"

void Ninja::addCoins(int coins) {
    Player::addCoins(coins * 2);
}

void Ninja::wellFall() {
    printWellMessage(true);
    // do nothing
}


