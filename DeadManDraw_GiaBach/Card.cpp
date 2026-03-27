
#include <iostream>
#include <string>
#include <vector>


class Card {

public:
    std::string suit;
    int value;

    Card(std::string suit, int value) :

        suit(suit), value(value)

    {
    }

    virtual std::string str() const = 0;


};
