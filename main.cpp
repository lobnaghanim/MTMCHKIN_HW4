
#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Mtmchkin.h"
#include "Cards/Witch.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Exception.h"


#include <algorithm>
#include <sstream>
#include <random>
#include <cstdio>
#include <fstream>
#include <cstring>
using namespace std;

void run_test(std::function<bool()> test, std::string test_name)
{
    if(!test()){
        std::cout<< test_name <<" FAILED."<<std::endl;
        std::cout << std::endl;
        return;
    }
    std::cout<<test_name<<" SUCCEEDED."<<std::endl;
    std::cout << std::endl;

}
bool cardsPrintsTest()
{

    Barfight junta;
    Dragon mushu;
    Mana mana;
    Gremlin gremlin;
    Merchant pizzaHut;
    Well well;
    Treasure factor;
    Witch witch;
    cout << junta << std::endl << mushu << std::endl << mana
         << std::endl << gremlin  << std::endl << pizzaHut
         << std::endl << well  << std::endl << factor
         << std::endl << witch;
    return true;
}

bool testCard()
{
    vector<unique_ptr<Card>> cards;
    cards.push_back(unique_ptr<Card>(new Gremlin()));
    cards.push_back(unique_ptr<Card>(new Witch()));
    cards.push_back(unique_ptr<Card>(new Dragon()));
    cards.push_back(unique_ptr<Card>(new Treasure()));
    cards.push_back(unique_ptr<Card>(new Merchant()));
    cards.push_back(unique_ptr<Card>(new Mana()));
    cards.push_back(unique_ptr<Card>(new Barfight()));
    cards.push_back(unique_ptr<Card>(new Well()));
    for(unique_ptr<Card>& card : cards){
        cout << *card;
    }
    cards.erase(cards.begin(),cards.end());
    return true;
}

bool playersPrintsTest()
{

    Ninja player1("Itay");
    Warrior player2("Efrat");
    Healer player3("Jimmy");
    cout << player1 << std::endl << player2 << std::endl << player3
         << std::endl;
    return true;
}
void createTextFile(const string &filename, const string &input)
{
    std::ofstream file(filename);
    if(file){
        file << input;
    }
}

void deleteTextFile(const string &filename)
{
    std::remove(filename.c_str());
}

bool compareFiles(const string &filename1, const string &filename2)
{
    string line1,line2;
    fstream file1(filename1),file2(filename2);
    if( !file2){
        cerr<<"Error opening file 2"<<std::endl;
        return false;
    }
    if(!file1 ){
        cerr<<"Error opening file 1"<<std::endl;
        return false;
    }
    while(!file1.eof()){ //read file until you reach the end
        getline(file1,line1);
        getline(file2,line2);
        if(!(line1==line2))
        {
            return false;
        }
    }
    if(!file2.eof()){
        return false;
    }
    return true;
}

bool GeneralGameSimulationTest(const string &tempDeckFilename, string input, string deck, string expectedOutputFileName)
{
    //   init cin from file
    createTextFile(tempDeckFilename+".txt",deck);
    istringstream in(input);
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf());

    std::ofstream outfile(tempDeckFilename+"out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(outfile.rdbuf());
    Mtmchkin game(tempDeckFilename+".txt");
    while(!game.isGameOver() && game.getNumberOfRounds() < 100){
        game.playRound();
        game.printLeaderBoard();
    }

    bool res = compareFiles(tempDeckFilename+"out.txt", expectedOutputFileName);
    outfile.close();
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    deleteTextFile(tempDeckFilename+".txt");
    return res;
}

bool dragonDenTest()
{
    const string tmp_file("dragonDen_test");
    string input("2\nJimmy Healer\nPikachu Warrior");
    string deck("Dragon\nDragon\nDragon\nDragon\nDragon");
//    string expectedOutputFilename("tests/dragonDen_test_expected.txt");
    string expectedOutputFilename("tests/dragonDen_test_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}

int main(){

    try{
        Mtmchkin game("C:\\Users\\97252\\Documents\\GitHub\\HW2\\MTMCHKIN_HW4\\deck.txt");
    }
    catch (const DeckFileNotFound& e)
    {
        cout<<e.what()<<endl;
    }
    catch (const DeckFileFormatError& e)
    {
        cout<<e.what()<<endl;
    }


//    Mtmchkin game("C:\\Users\\allih\\OneDrive\\Documents\\GitHub\\MTMCHKIN_HW4\\deck.txt");
//    while(!game.isGameOver()){
//        game.playRound();
//    }

//
//
//    Healer healer("Ali");
//    cout << healer << endl;
//
//
//    Witch witch;
//    cout << witch << endl;
//
//    Gremlin gremlin;
//    cout << gremlin << endl;
//
//    Dragon dragon;
//    cout << dragon << endl;
//
//    Treasure t;
//    cout << t << endl;
//
//    Merchant m;
//    cout << m << endl;


//
//    vector<char> v = {'a','b','c','d','e','f', 'm'};
//    vector<int> w = {0, 4, 3};
//    vector<int> l = {1, 2, 5};
//
//
//    int rank = 1;
//    for(int i = 0; i < 3; i++){
//        cout << "rank is: " << rank << "char is " << v[w[i]] << endl;
//        rank++;
//    }
//
//    for(int i = 4 - 1; i >= 0; i--){
//        cout << "rank is: " << rank << "char is " << v[l[i]] << endl;
//        rank++;
//    }

//    return 0;


    // Ali Ninja
//    Mtmchkin game2("deck.txt");
    run_test(cardsPrintsTest,"cardsPrintsTest");
    run_test(playersPrintsTest,"playersPrintsTest");
    run_test(testCard,"Deck creation test");
//    run_test(dragonDenTest,"Dragon Den simulation test");
//    run_test(gremlinCaveTest,"Gremlin Cave simulation test");
//    run_test(witchLairTest,"Witch Lair simulation test");
//    run_test(nonMostersTest,"Non monsters cards simulation test");
//    run_test(badFormatStartTest,"Bad format at start of file exception test");
//    run_test(badFormatTest,"Bad format exception test");
//    run_test(noFileTest,"File Doesnt exist exception test");
//    run_test(badSizeTest,"Bad size exception test");
//    run_test(roundLimitTest,"Round upper limit test");
//    run_test(allTenTest,"All reach lvl 10 test");
//    run_test(badPlayerInputTest,"Bad player input test");
    return 0;
}

//
//int main(){
//
//    Mtmchkin game("C:\\Users\\Ali Harbaji\\Documents\\GitHub\\MTMCHKIN_HW4\\deck.txt");
//
////    cout << game.m_players[0]->getName() << endl;
//
//
////
////
////    Ninja ninja("Ninja");
////    cout << ninja.getName() << endl;
////    cout << ninja.getForce() << endl;
////    cout << ninja.getLevel() << endl;
////    cout << ninja.getHP() << endl;
////    cout << ninja.getCoins() << endl;
////    cout << ninja.getAttackStrength() << endl;
////    cout << "------------------------------------" << endl;
////    Warrior warrior("Warrior");
////    cout << warrior.getName() << endl;
////    cout << warrior.getForce() << endl;
////    cout << warrior.getLevel() << endl;
////    cout << warrior.getHP() << endl;
////    cout << warrior.getCoins() << endl;
////    cout << warrior.getAttackStrength() << endl;
////    cout << "------------------------------------" << endl;
////
////    BarfightCard barfightCard;
////    barfightCard.applyEncounter(ninja);
////    cout << ninja.getHP() << endl;
////
////    barfightCard.applyEncounter(warrior);
////    cout << warrior.getHP() << endl;
////    cout << "------------------------------------" << endl;
////
////    ManaCard manaCard;
////    manaCard.applyEncounter(ninja);
////    cout << ninja.getHP() << endl;
////
////    Healer healer("Healer");
////    manaCard.applyEncounter(healer);
////    cout << healer.getHP() << endl;
////
////    WellCard wellCard;
////    wellCard.applyEncounter(ninja);
////    cout << ninja.getHP() << endl;
////
////    wellCard.applyEncounter(warrior);
////    cout << warrior.getHP() << endl;
//////    MerchantCard merchantCard;
//////    merchantCard.applyEncounter(ninja);
////
////    TreasureCard treasureCard;
////    treasureCard.applyEncounter(ninja);
////
////    cout << ninja.getCoins() << endl;
////
//
//
////
////    Warrior warrior("Warrior");
////    BarfightCard barfightCard;
////    barfightCard.applyEncounter(warrior);
////    barfightCard.applyEncounter(ninja);
////    cout << ninja.getHP() << endl;
////    cout << warrior.getName() << endl;
////    cout << warrior.getHP() << endl;
//
////    ManaCard manaCard;
////    manaCard.applyEncounter(ninja);
////    cout << ninja.getHP() << endl;
////
////    Healer healer("Healer");
////    cout << healer.getName() << endl;
////    barfightCard.applyEncounter(healer);
////    barfightCard.applyEncounter(healer);
////    barfightCard.applyEncounter(healer);
////    cout << healer.getHP() << endl;
////    manaCard.applyEncounter(healer);
////    cout << healer.getHP() << endl;
//
//
////
////BattleCard battleCard("BattleCard", 10, 20, 30);
////    cout << battleCard.getName() << endl;
////    cout << battleCard.getForce() << endl;
////    cout << battleCard.getLoot() << endl;
////    cout << battleCard.getDamage() << endl;
////    cout << "------------------------------------" << endl;
//
////    Gremlin gremlin;
////    cout << gremlin.getName() << endl;
////    cout << gremlin.getForce() << endl;
////    cout << gremlin.getLoot() << endl;
////    cout << gremlin.getDamage() << endl;
////    cout << "------------------------------------" << endl;
////
////    Witch witch;
////    cout << witch.getName() << endl;
////    cout << witch.getForce() << endl;
////    cout << witch.getLoot() << endl;
////    cout << witch.getDamage() << endl;
////    cout << "------------------------------------" << endl;
////
////    cout << "After applying Witch encounter: " << endl;
////    witch.applyEncounter(ninja);
////    cout << ninja.getForce() << endl;
////    cout << ninja.getLevel() << endl;
////    cout << ninja.getHP() << endl;
////    cout << ninja.getCoins() << endl;
////    cout << "------------------------------------" << endl;
////
////    // print witch info
////    cout << witch.getName() << endl;
////    cout << witch.getForce() << endl;
////    cout << witch.getLoot() << endl;
////    cout << witch.getDamage() << endl;
////    cout << "------------------------------------" << endl;
////
////    Dragon* dragon = new Dragon;
////    cout << dragon->getName() << endl;
////    cout << dragon->getForce() << endl;
////    cout << dragon->getLoot() << endl;
////    cout << dragon->getDamage() << endl;
////    cout << "------------------------------------" << endl;
////
////    cout << "After applying Dragon encounter: " << endl;
////    dragon->applyEncounter(ninja);
////    cout << ninja.getForce() << endl;
////    cout << ninja.getLevel() << endl;
////    cout << ninja.getHP() << endl;
////    cout << ninja.getCoins() << endl;
////    cout << "------------------------------------" << endl;
////
////    MerchantCard merchantCard;
////    cout << merchantCard.getName() << endl;
//////    merchantCard.applyEncounter(ninja);
////    cout << "------------------------------------" << endl;
////    cout << ninja.getCoins() << endl;
////    TreasureCard treasureCard;
////    treasureCard.applyEncounter(ninja);
////    cout << ninja.getCoins() << endl;
////
////
////
////    WellCard wellCard;
////
////    cout<< "ninja health after encounter" << endl;
////    ninja.heal(50);
////    wellCard.applyEncounter(ninja);
////    cout << ninja.getHP() << endl;
////
////    Warrior warrior("ali");
////    cout << warrior.getName() << endl;
////    wellCard.applyEncounter(warrior);
////    cout << warrior.getHP() << endl;
////    cout << wellCard << endl;
//
////    Witch witch("Witch");
////    cout << witch.getName() << endl;
////    cout << witch.getForce() << endl;
////    cout << witch.getLoot() << endl;
////    cout << witch.getDamage() << endl;
////    cout << "------------------------------------" << endl;
////
////    Dragon dragon("Dragon");
////    cout << dragon.getName() << endl;
////    cout << dragon.getForce() << endl;
////    cout << dragon.getLoot() << endl;
////    cout << dragon.getDamage() << endl;
//
////    cout << "------------------------------------" << endl;
////    Dragon dragon("Ali Dragon");
////    cout << dragon.getName() << endl;
////    cout << dragon.getForce() << endl;
////    cout << dragon.getLoot() << endl;
////    cout << dragon.getDamage() << endl;
//
////    // Player tests
////    Player player("Player1");
////    cout << player.getName() << endl;
////    cout << player.getLevel() << endl;
////    cout << player.getHP() << endl;
////    cout << player.getForce() << endl;
////    cout << player.getCoins() << endl;
////
//////    player.addCoins(10);
//////    player.addHealth(10);
//////    cout << player.getCoins() << endl;
//////    cout << player.getHealth() << endl;
//////    cout << player.getDamage() << endl;
////    cout << "------------------------------------" << endl;
//////
////    Ninja ninja("Ninja");
////    cout << ninja.getName() << endl;
////    ninja.heal(10);
////    ninja.addCoins(10);
////    cout << ninja.getLevel() << endl;
////    cout << ninja.getHP() << endl;
////    cout << ninja.getForce() << endl;
////    cout << ninja.getCoins() << endl;
////    cout << "------------------------------------" << endl;
//////
////    Healer healer("Healer");
////    cout << healer.getName() << endl;
////    healer.heal(-10);
////    healer.addCoins(10);
////    cout << healer.getLevel() << endl;
////    cout << healer.getHP() << endl;
////    cout << healer.getForce() << endl;
////    cout << healer.getCoins() << endl;
////    cout << healer.getAttackStrength() << endl;
////    cout << "------------------------------------" << endl;
//////
////    Warrior warrior("Warrior");
////    cout << warrior.getName() << endl;
////    cout << warrior.getLevel() << endl;
////    cout << warrior.getHP() << endl;
////    cout << warrior.getForce() << endl;
////    cout << warrior.getCoins() << endl;
////    cout << warrior.getAttackStrength() << endl;
//
//
//
//    return 0;
//}