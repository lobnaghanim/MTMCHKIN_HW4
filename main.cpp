
#include <iostream>
#include "Players/Player.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include "Cards/Card.h"
#include "Cards/BattleCards/BattleCard.h"
#include "Cards/BattleCards/Gremlin.h"
#include "Cards/BattleCards/Witch.h"
#include "Cards/BattleCards/Dragon.h"
#include "Cards/MerchantCards/MerchantCard.h"
#include "Cards/TreasureCards/TreasureCard.h"
#include "Cards/WellCards/WellCard.h"
#include "Cards/BarfightCards/BarfightCard.h"
#include "Cards/ManaCards/ManaCard.h"

#include "Mtmchkin.h"

using namespace std;

int main(){

    Mtmchkin game("C:\\Users\\Ali Harbaji\\Documents\\GitHub\\MTMCHKIN_HW4\\deck.txt");

//    cout << game.m_players[0]->getName() << endl;


//
//
//    Ninja ninja("Ninja");
//    cout << ninja.getName() << endl;
//    cout << ninja.getForce() << endl;
//    cout << ninja.getLevel() << endl;
//    cout << ninja.getHP() << endl;
//    cout << ninja.getCoins() << endl;
//    cout << ninja.getAttackStrength() << endl;
//    cout << "------------------------------------" << endl;
//    Warrior warrior("Warrior");
//    cout << warrior.getName() << endl;
//    cout << warrior.getForce() << endl;
//    cout << warrior.getLevel() << endl;
//    cout << warrior.getHP() << endl;
//    cout << warrior.getCoins() << endl;
//    cout << warrior.getAttackStrength() << endl;
//    cout << "------------------------------------" << endl;
//
//    BarfightCard barfightCard;
//    barfightCard.applyEncounter(ninja);
//    cout << ninja.getHP() << endl;
//
//    barfightCard.applyEncounter(warrior);
//    cout << warrior.getHP() << endl;
//    cout << "------------------------------------" << endl;
//
//    ManaCard manaCard;
//    manaCard.applyEncounter(ninja);
//    cout << ninja.getHP() << endl;
//
//    Healer healer("Healer");
//    manaCard.applyEncounter(healer);
//    cout << healer.getHP() << endl;
//
//    WellCard wellCard;
//    wellCard.applyEncounter(ninja);
//    cout << ninja.getHP() << endl;
//
//    wellCard.applyEncounter(warrior);
//    cout << warrior.getHP() << endl;
////    MerchantCard merchantCard;
////    merchantCard.applyEncounter(ninja);
//
//    TreasureCard treasureCard;
//    treasureCard.applyEncounter(ninja);
//
//    cout << ninja.getCoins() << endl;
//


//
//    Warrior warrior("Warrior");
//    BarfightCard barfightCard;
//    barfightCard.applyEncounter(warrior);
//    barfightCard.applyEncounter(ninja);
//    cout << ninja.getHP() << endl;
//    cout << warrior.getName() << endl;
//    cout << warrior.getHP() << endl;

//    ManaCard manaCard;
//    manaCard.applyEncounter(ninja);
//    cout << ninja.getHP() << endl;
//
//    Healer healer("Healer");
//    cout << healer.getName() << endl;
//    barfightCard.applyEncounter(healer);
//    barfightCard.applyEncounter(healer);
//    barfightCard.applyEncounter(healer);
//    cout << healer.getHP() << endl;
//    manaCard.applyEncounter(healer);
//    cout << healer.getHP() << endl;


//
//BattleCard battleCard("BattleCard", 10, 20, 30);
//    cout << battleCard.getName() << endl;
//    cout << battleCard.getForce() << endl;
//    cout << battleCard.getLoot() << endl;
//    cout << battleCard.getDamage() << endl;
//    cout << "------------------------------------" << endl;

//    Gremlin gremlin;
//    cout << gremlin.getName() << endl;
//    cout << gremlin.getForce() << endl;
//    cout << gremlin.getLoot() << endl;
//    cout << gremlin.getDamage() << endl;
//    cout << "------------------------------------" << endl;
//
//    Witch witch;
//    cout << witch.getName() << endl;
//    cout << witch.getForce() << endl;
//    cout << witch.getLoot() << endl;
//    cout << witch.getDamage() << endl;
//    cout << "------------------------------------" << endl;
//
//    cout << "After applying Witch encounter: " << endl;
//    witch.applyEncounter(ninja);
//    cout << ninja.getForce() << endl;
//    cout << ninja.getLevel() << endl;
//    cout << ninja.getHP() << endl;
//    cout << ninja.getCoins() << endl;
//    cout << "------------------------------------" << endl;
//
//    // print witch info
//    cout << witch.getName() << endl;
//    cout << witch.getForce() << endl;
//    cout << witch.getLoot() << endl;
//    cout << witch.getDamage() << endl;
//    cout << "------------------------------------" << endl;
//
//    Dragon* dragon = new Dragon;
//    cout << dragon->getName() << endl;
//    cout << dragon->getForce() << endl;
//    cout << dragon->getLoot() << endl;
//    cout << dragon->getDamage() << endl;
//    cout << "------------------------------------" << endl;
//
//    cout << "After applying Dragon encounter: " << endl;
//    dragon->applyEncounter(ninja);
//    cout << ninja.getForce() << endl;
//    cout << ninja.getLevel() << endl;
//    cout << ninja.getHP() << endl;
//    cout << ninja.getCoins() << endl;
//    cout << "------------------------------------" << endl;
//
//    MerchantCard merchantCard;
//    cout << merchantCard.getName() << endl;
////    merchantCard.applyEncounter(ninja);
//    cout << "------------------------------------" << endl;
//    cout << ninja.getCoins() << endl;
//    TreasureCard treasureCard;
//    treasureCard.applyEncounter(ninja);
//    cout << ninja.getCoins() << endl;
//
//
//
//    WellCard wellCard;
//
//    cout<< "ninja health after encounter" << endl;
//    ninja.heal(50);
//    wellCard.applyEncounter(ninja);
//    cout << ninja.getHP() << endl;
//
//    Warrior warrior("ali");
//    cout << warrior.getName() << endl;
//    wellCard.applyEncounter(warrior);
//    cout << warrior.getHP() << endl;
//    cout << wellCard << endl;

//    Witch witch("Witch");
//    cout << witch.getName() << endl;
//    cout << witch.getForce() << endl;
//    cout << witch.getLoot() << endl;
//    cout << witch.getDamage() << endl;
//    cout << "------------------------------------" << endl;
//
//    Dragon dragon("Dragon");
//    cout << dragon.getName() << endl;
//    cout << dragon.getForce() << endl;
//    cout << dragon.getLoot() << endl;
//    cout << dragon.getDamage() << endl;

//    cout << "------------------------------------" << endl;
//    Dragon dragon("Ali Dragon");
//    cout << dragon.getName() << endl;
//    cout << dragon.getForce() << endl;
//    cout << dragon.getLoot() << endl;
//    cout << dragon.getDamage() << endl;

//    // Player tests
//    Player player("Player1");
//    cout << player.getName() << endl;
//    cout << player.getLevel() << endl;
//    cout << player.getHP() << endl;
//    cout << player.getForce() << endl;
//    cout << player.getCoins() << endl;
//
////    player.addCoins(10);
////    player.addHealth(10);
////    cout << player.getCoins() << endl;
////    cout << player.getHealth() << endl;
////    cout << player.getDamage() << endl;
//    cout << "------------------------------------" << endl;
////
//    Ninja ninja("Ninja");
//    cout << ninja.getName() << endl;
//    ninja.heal(10);
//    ninja.addCoins(10);
//    cout << ninja.getLevel() << endl;
//    cout << ninja.getHP() << endl;
//    cout << ninja.getForce() << endl;
//    cout << ninja.getCoins() << endl;
//    cout << "------------------------------------" << endl;
////
//    Healer healer("Healer");
//    cout << healer.getName() << endl;
//    healer.heal(-10);
//    healer.addCoins(10);
//    cout << healer.getLevel() << endl;
//    cout << healer.getHP() << endl;
//    cout << healer.getForce() << endl;
//    cout << healer.getCoins() << endl;
//    cout << healer.getAttackStrength() << endl;
//    cout << "------------------------------------" << endl;
////
//    Warrior warrior("Warrior");
//    cout << warrior.getName() << endl;
//    cout << warrior.getLevel() << endl;
//    cout << warrior.getHP() << endl;
//    cout << warrior.getForce() << endl;
//    cout << warrior.getCoins() << endl;
//    cout << warrior.getAttackStrength() << endl;



    return 0;
}