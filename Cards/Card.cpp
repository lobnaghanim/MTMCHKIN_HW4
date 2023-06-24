#include "Card.h"


Card::Card(string name) {
    m_name = name;
}

std::ostream &operator<<(ostream &os, const Card &card) {
    printCardDetails(os, card.m_name);
    card.print(os);
    printEndOfCardDetails(os);
    return os;
}




