#include "Mtmchkin.h"
#define SPACE ' '

int count(const string & str, char c){
    int count = 0;
    for(int i = 0; i < (int) str.size(); i++){
        if(str[i] == c){
            count++;
            while(str[i] == c){
                i++;
            }
        }
    }
    return count;
}

int isValid(const string & input){
    // use ust::stringstream to split the string into words
    // and put them in a vector
    // check if the input is more than 2 words (return -1 if so)
    // check if the first word is a valid name (return 2 if not)
    // check if the second word is a valid class (return 3 if not)
    // if both are valid return 1
    std::string name, type;
    std::istringstream iss(input);

    // check if the input is more than 2 words
    if (count(input, SPACE) != 1) {
        return -1;  // Invalid input
    }


    // split the input into 2 words and print them
    for(int i = 0; i < (int) input.size(); i++){
        if(input[i] == SPACE){
            name = input.substr(0, i);
            // check if name contains integers
            for(char c : name){
                // checks if c is not a capital/small letter
                if(!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z')){
                    return 2;  // Invalid name
                }
            }
            while(input[i] == SPACE){
                i++;
            }
            type = input.substr(i, input.size());
            break;
        }
    }

    if (iss >> name >> type) {
        if(name.length() > 15){
            return 2;  // Invalid name
        }
        // Check if the type is either "Dragon" or "Ninja"
        if (!(type == "Warrior" || type == "Ninja" || type == "Warrior" || type == "Healer")) {
            return 3;  // invalid class
        }
    }

    return 1;
}

int cardTypesAreValid(const vector<string>& inputArray, int size) {
    int i;
    for(i = 0; i < size; i++) {
        if(!(inputArray[i] == "Dragon" || inputArray[i] == "Well" || inputArray[i] == "Barfight" || inputArray[i] == "Gremlin"
        || inputArray[i] == "Witch"  || inputArray[i] == "Merchant" || inputArray[i] == "Treasure" || inputArray[i] == "Mana")) {
            return i; //the deck of cards starts with line 1 not 0 in the file deck.txt
        }
    }
    return i;
}

void Mtmchkin::buildPlayer(const std::string &name, const std::string &type) {
    if(type == "Ninja"){
        unique_ptr<Ninja> ninja(new Ninja(name));
        m_players.push_back(std::move(ninja));
    } else if(type == "Warrior"){
        unique_ptr<Warrior> warrior(new Warrior(name));
        m_players.push_back(std::move(warrior));
    } else if(type == "Healer"){
        unique_ptr<Healer> healer(new Healer(name));
        m_players.push_back(std::move(healer));
    }
}

bool isNumber(const std::string& str) {
    try {
        std::stoi(str);
        return true;
    } catch (const std::exception& e) {
        return false;
    }
}


Mtmchkin::Mtmchkin(const std::string &fileName) {
    // read the cards from the file
    std::ifstream file(fileName);

    printStartGameMessage();
    if(!file) {
        throw DeckFileNotFound();
    }
    // -----------------------------
    // card array
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
    int lineNumber = cardTypesAreValid(inputArray, size);
    if(lineNumber<size) {
        throw DeckFileFormatError(lineNumber + 1);
    }
    if(size<5) throw DeckFileInvalidSize();
    // -----------------------------

    printEnterTeamSizeMessage();
    string teamSize;
    std::getline(std::cin, teamSize);
    // check if team size is a number not a word
    while(!isNumber(teamSize) || stoi(teamSize) <= 1 || stoi(teamSize) >= 7){
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        std::getline(std::cin, teamSize);
    }

    int teamSizeAsInt = stoi(teamSize);
    for(int i = 0; i < teamSizeAsInt; i++) { // builds the players
        string name;
        printInsertPlayerMessage();

        std::getline(std::cin, name);
        // check weather the name and class are valid (returns 1 if valid, 2 if the player's name is invalid, 3 if the player's class is invalid)
        int flag = isValid(name);
        while(flag != 1){ //
            if(flag == -1) {
                printInvalidInput();
            }else if(flag == 2){
                printInvalidName();
            }else {
                printInvalidClass();
            }
            std::getline(std::cin, name);
            flag = isValid(name);
        }

        string tempName, tempType;
        // create a new player and add it to the vector
        for(int e = 0; i < (int) name.size(); e++){
            if(name[e] == SPACE){
                tempName = name.substr(0, e);
                while(name[e] == SPACE){
                    e++;
                }
                tempType = name.substr(e, name.size());
                break;
            }
        }

        buildPlayer(tempName, tempType);
    }

    // construct the deck
    buildDeck(inputArray);

    m_roundsPlayed = 0;
    m_currentCard = 0;
    file.close();
}

void Mtmchkin::buildDeck(const std::vector<std::string> &inputArray) {
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
        } else if(s == "Witch"){
            unique_ptr<Witch> witch(new Witch());
            m_deck.push_back(std::move(witch));
        } else if(s == "Merchant"){
            unique_ptr<Merchant> merchant(new Merchant());
            m_deck.push_back(std::move(merchant));
        } else if(s == "Treasure"){
            unique_ptr<Treasure> treasure(new Treasure());
            m_deck.push_back(std::move(treasure));
        } else if(s == "Mana"){
            unique_ptr<Mana> mana(new Mana());
            m_deck.push_back(std::move(mana));
        }
    }
}

bool Mtmchkin::isGameOver() const {
    int count = 0;
    for(int i = 0; i < (int)m_players.size(); i++){
        if(m_players[i]->isKnockedOut() || m_players[i]->getLevel() >= MAXLVL){
            count++;
        }
    }
    if(count == (int) m_players.size()){
        return true;
    }
    return false;
}

void Mtmchkin::playRound() {
    if(isGameOver()){
        printGameEndMessage();
        return;
    }

    // print the round start message
    printRoundStartMessage(m_roundsPlayed + 1);

    for(int i = 0; i < (int) m_players.size(); i++){
        if(m_players[i]->isKnockedOut() || m_players[i]->getLevel() >= MAXLVL){
            continue;
        }
        printTurnStartMessage(m_players[i]->getName());

        m_deck[m_currentCard]->applyEncounter(*m_players[i]);
        m_currentCard++;
        if(m_currentCard == (int) m_deck.size()){
            m_currentCard = 0;
        }
        if(m_players[i]->getLevel() >= MAXLVL){
            m_winners_indexes.push_back(i);
        } else if(m_players[i]->isKnockedOut()){
            m_losers_indexes.push_back(i);
        }
    }


    // cyclical increment

    m_roundsPlayed++;

//    printLeaderBoard();
    if(isGameOver()){
        printGameEndMessage();
        return;
    }
}

int Mtmchkin::getNumberOfRounds() const {
    return m_roundsPlayed;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    // print the leader board
    int rank = 1;
    for(int i = 0; i < (int) m_winners_indexes.size(); i++){
        printPlayerLeaderBoard(rank,*m_players[m_winners_indexes[i]]);
        rank++;
    }
    // for each player that is not a winner and not a loser
    for(int i = 0; i < (int) m_players.size(); i++){
        if(m_players[i]->isKnockedOut() || m_players[i]->getLevel() >= MAXLVL){
            continue;
        }
        printPlayerLeaderBoard(rank,*m_players[i]);
        rank++;
    }

    for(int i = (int) m_losers_indexes.size() - 1; i >= 0; i--){
        printPlayerLeaderBoard(rank,*m_players[m_losers_indexes[i]]);
        rank++;
    }

}
