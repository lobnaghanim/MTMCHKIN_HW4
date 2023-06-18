
#include <iostream>
#include "Players/Player.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
//#include "Card.h"

using namespace std;

int main(){
//    Card card("Card");
//    cout << card.getName() << endl;
//
//    cout << "------------------------------------" << endl;
//
//    Gremlin gremlin("Ali Gremlin");
//    cout << gremlin.getName() << endl;
//    cout << gremlin.getForce() << endl;
//    cout << gremlin.getLoot() << endl;
//    cout << gremlin.getDamage() << endl;
//
//    cout << "------------------------------------" << endl;
//    Witch witch("Ali Witch");
//    cout << witch.getName() << endl;
//    cout << witch.getForce() << endl;
//    cout << witch.getLoot() << endl;
//    cout << witch.getDamage() << endl;
//
//    cout << "------------------------------------" << endl;
//    Dragon dragon("Ali Dragon");
//    cout << dragon.getName() << endl;
//    cout << dragon.getForce() << endl;
//    cout << dragon.getLoot() << endl;
//    cout << dragon.getDamage() << endl;

    // Player tests
    Player player("Player1");
    cout << player.getName() << endl;
    cout << player.getLevel() << endl;
    cout << player.getHP() << endl;
    cout << player.getForce() << endl;
    cout << player.getCoins() << endl;

//    player.addCoins(10);
//    player.addHealth(10);
//    cout << player.getCoins() << endl;
//    cout << player.getHealth() << endl;
//    cout << player.getDamage() << endl;
    cout << "------------------------------------" << endl;
//
    Ninja ninja("Ninja");
    cout << ninja.getName() << endl;
    ninja.heal(10);
    ninja.addCoins(10);
    cout << ninja.getLevel() << endl;
    cout << ninja.getHP() << endl;
    cout << ninja.getForce() << endl;
    cout << ninja.getCoins() << endl;
    cout << "------------------------------------" << endl;
//
    Healer healer("Healer");
    cout << healer.getName() << endl;
    healer.heal(-10);
    healer.addCoins(10);
    cout << healer.getLevel() << endl;
    cout << healer.getHP() << endl;
    cout << healer.getForce() << endl;
    cout << healer.getCoins() << endl;
    cout << healer.getAttackStrength() << endl;
    cout << "------------------------------------" << endl;
//
    Warrior warrior("Warrior");
    cout << warrior.getName() << endl;
    cout << warrior.getLevel() << endl;
    cout << warrior.getHP() << endl;
    cout << warrior.getForce() << endl;
    cout << warrior.getCoins() << endl;
    cout << warrior.getAttackStrength() << endl;



    return 0;
}