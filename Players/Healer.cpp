#include "Healer.h"
#include "utilities.h"
void Healer::heal(int hp) {
    Player::heal(hp * 2);
}

void Healer::manaApply() {
    this->heal(10);
    printManaMessage(true);
}

std::ostream& operator<<(std::ostream& os, const Player& player){
    printPlayerDetails(os, player.getName(), "Healer", player.getLevel(),
                       player.getForce(), player.HP_asInteger(), player.getCoins());
    return os;
}