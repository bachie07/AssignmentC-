#pragma once
#include <string>
#include "Card.h"

class Player {

public:

    Player(std::string name);
    
    bool playCard(Card* card, Game& game);

    bool isBust();

    void moveCardToBank();

    void printBank();

    void printPlayArea();

    std::string getScore() const;

    void addToPlayArea(Card* card); // add to UML

    void clearPlayArea(); // add to UML
    
    std::string getName() const; 

    CardCollection getBank() const;

    CardCollection getPlayArea() const;

    virtual ~Player() {}



    

private: 

    std::string playerName;

    int score;

    CardCollection _PlayArea;

    CardCollection _Bank;


};