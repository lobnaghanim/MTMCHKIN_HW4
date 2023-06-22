#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string>
#include <vector>
#include "Cards/Card.h"
#include "memory"
#include "Players/Player.h"
#include "Players/Warrior.h"
#include "Players/Healer.h"
#include "Players/Ninja.h"
#include "Cards/Dragon.h"
#include "Cards/Witch.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"
#include "Cards/Barfight.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include <fstream>
#include <sstream>

#define MAXLVL 10

#include "utilities.h"

using std::unique_ptr;

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    vector<unique_ptr<Player>> m_players;
    vector<unique_ptr<Card>> m_deck;
    void buildPlayer(const std::string &name, const std::string &type);
    void buildDeck(const std::vector<std::string> &inputArray);
    int m_roundsPlayed;

    int m_currentCard;

    vector<int> m_winners_indexes;
    vector<int> m_losers_indexes;
};



#endif /* MTMCHKIN_H_ */
