#include "Healer.h"

void Healer::heal(int hp) {
    Player::heal(hp * 2);
}