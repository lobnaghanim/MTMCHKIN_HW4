#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;
#include "Players/Player.h"



class Card{
public:
    explicit Card(string name);
    string getName();
protected:
    string m_name;

};




#endif