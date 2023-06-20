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
    m_players.push_back(new Player());

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
            printf("line is: %s\n", line.c_str());
            inputArray.push_back(line);
            size++;
        }
    }
    bool isValid = inputIsValid(inputArray.data(), size);
    if(!isValid) {
        throw std::runtime_error("Invalid input");
    }


    // construct the deck
    for(string s: inputArray){
        if(s == "Dragon"){
            m_deck.push_back(new Dragon());
        } else if(s == "Well"){
            m_deck.push_back(new Well());
        } else if(s == "Barfight"){
            m_deck.push_back(new Barfight());
        } else if(s == "Gremlin"){
            m_deck.push_back(new Gremlin());
        } else if(s == "Witch"){
            m_deck.push_back(new Witch());
        } else if(s == "Merchant"){
            m_deck.push_back(new Merchant());
        } else if(s == "Treasure"){
            m_deck.push_back(new Treasure());
        } else if(s == "Mana"){
            m_deck.push_back(new Mana());
        }
    }

    // print the deck
    for(Card* card: m_deck){
        cout << card->getName() << endl;
    }

    file.close();

}
