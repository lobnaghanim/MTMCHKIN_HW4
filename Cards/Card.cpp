#include "Card.h"


Card::Card(string name) {
    m_name = name;
}

string Card::getName() {
    return m_name;
}

std::ostream &operator<<(ostream &os, const Card &card) {
    os << card.m_name;
    return os;
}



