#include <fstream>
#include "Mtmchkin.h"

#include "Cards/BattleCards/Dragon.h"
#include "Cards/BattleCards/Witch.h"
#include "Cards/MerchantCards/MerchantCard.h"
#include "Cards/TreasureCards/TreasureCard.h"
#include "Cards/WellCards/WellCard.h"
#include "Cards/BarfightCards/BarfightCard.h"

#include "Cards/ManaCards/ManaCard.h"

Mtmchkin::Mtmchkin(const std::string &fileName) {
    m_players.push_back(new Player());

    std::ifstream file(fileName);

//    if (!file.is_open()) {
//        throw std::runtime_error("Failed to open file: " + fileName);
//    }
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            // create a new card and add it to the deck
            printf("line is: %s\n", line.c_str());
            m_deck.push_back(new ManaCard());

//            m_deck.push_back(Card(line));
        }
    }

    file.close();

}
