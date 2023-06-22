#include "Warrior.h"

int Warrior::getAttackStrength() const {
    return getLevel() +  2 * getForce();
}

void Warrior::barFight() {
    printBarfightMessage(true);
    // do nothing
}
