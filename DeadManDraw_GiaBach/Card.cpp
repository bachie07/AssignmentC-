#include "Card.h"

Card::Card(std::string suit, int value, CardType type)  : 

    suit(suit), value(value), _type(type)

{ }

const CardType& Card::type() const { 

    return _type;

}

