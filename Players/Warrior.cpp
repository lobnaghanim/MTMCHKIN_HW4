#include "Warrior.h"

int Warrior::getAttackStrength() const {
    return getLevel() +  2 * getForce();
}