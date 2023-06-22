#include "Healer.h"
#include "utilities.h"
void Healer::heal(int hp) {
    Player::heal(hp * 2);
}

void Healer::manaApply() {
    this->heal(10);
    printManaMessage(true);
}
