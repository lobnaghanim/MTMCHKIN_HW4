#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;
#include "../Players/Player.h"
#include "../utilities.h"


class Card{
public:
    explicit Card(string name);
    string getName();
    virtual void applyEncounter(Player &player) = 0;
    virtual ~Card() = default;
    Card(const Card& other) = delete;
    Card& operator=(const Card& other) = delete;
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
    virtual void print(std::ostream &os) const = 0;
protected:
    string m_name;
};




#endif