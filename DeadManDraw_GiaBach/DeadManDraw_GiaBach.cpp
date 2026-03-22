// DeadManDraw_GiaBach.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>


class Player {

public:
    std::string name;
    int score;

    Player(std::string playerName, int playerScore) :
        name(playerName), score(playerScore)

    {
    }

    void print() {
        std::cout << "My name is " << name << std::endl;
        std::cout << "My score is " << score << std::endl;
    }
};

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

class MermaidCard : public Card {

public:
    MermaidCard(int value) :
        Card("Mermaid", value)

    {
    }

    std::string str() const override {

        return suit + "(" + std::to_string(value) + ")";

    }


};


class CannonCard : public Card {

public:
    CannonCard(int value) :
        Card("Cannon", value)
    {

    }

    std::string str() const override {

        return suit + "(" + std::to_string(value) + ")";
    }

};




int main()
{

    std::vector<Card*> deck;

    Card* myCard = new CannonCard(7);

    Card* myCard2 = new MermaidCard(10);




    deck.push_back(myCard);
    
    deck.push_back(myCard2);

    for (Card* card : deck) {

        std::cout << card->str() << std::endl;

        delete card;

    }


}


