#include <fstream>
#include "Mtmchkin.h"

#include "Cards/Dragon.h"
#include "Cards/Witch.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"
#include "Cards/Barfight.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"

bool inputIsValid(string * inputArray, int size) {
    for(int i = 0; i < size; i++) {
        if(!(inputArray[i] == "Dragon" || inputArray[i] == "Well" || inputArray[i] == "Barfight" || inputArray[i] == "Gremlin"
        || inputArray[i] == "Witch"  || inputArray[i] == "Merchant" || inputArray[i] == "Treasure" || inputArray[i] == "Mana")) {
            return false;
        }
    }
    return true;
}

Mtmchkin::Mtmchkin(const std::string &fileName) {
//    m_players.push_back(new Player());

    std::ifstream file(fileName);

//    if (!file.is_open()) {
//        throw std::runtime_error("Failed to open file: " + fileName);
//    }
    vector<string> inputArray;
    int size = 0;

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            // create a new card and add it to the deck
            inputArray.push_back(line);
            size++;
        }
    }
    bool isValid = inputIsValid(inputArray.data(), size);
    if(!isValid) {
        throw std::runtime_error("Invalid input");
    }


    // construct the deck
    for( const string& s: inputArray){
        if(s == "Dragon"){
            unique_ptr<Dragon> dragon(new Dragon());
            m_deck.push_back(std::move(dragon));
        } else if(s == "Well"){
            unique_ptr<Well> well(new Well());
            m_deck.push_back(std::move(well));
        } else if(s == "Barfight"){
            unique_ptr<Barfight> barfight(new Barfight());
            m_deck.push_back(std::move(barfight));
        } else if(s == "Gremlin"){
            unique_ptr<Gremlin> gremlin(new Gremlin());
            m_deck.push_back(std::move(gremlin));
//            m_deck.push_back(unique_ptr<Gremlin>(new Gremlin()));
        } else if(s == "Witch"){
            unique_ptr<Witch> witch(new Witch());
            m_deck.push_back(std::move(witch));
//            m_deck.push_back(unique_ptr<Witch>(new Witch()));
        } else if(s == "Merchant"){
            unique_ptr<Merchant> merchant(new Merchant());
            m_deck.push_back(std::move(merchant));
//            m_deck.push_back(unique_ptr<Merchant>(new Merchant()));
        } else if(s == "Treasure"){
            unique_ptr<Treasure> treasure(new Treasure());
            m_deck.push_back(std::move(treasure));
//            m_deck.push_back(unique_ptr<Treasure>(new Treasure()));
        } else if(s == "Mana"){
            unique_ptr<Mana> mana(new Mana());
            m_deck.push_back(std::move(mana));
//            m_deck.push_back(unique_ptr<Mana>(new Mana()));
        }
    }
    // print the deck
    // without using auto

    for(int i = 0; i < m_deck.size(); i++){
        printf("card %d is: %s\n", i, m_deck[i]->getName().c_str());
    }

    file.close();
}
