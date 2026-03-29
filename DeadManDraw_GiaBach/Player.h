#pragma once
#include <string>
#include "Card.h"

class Player {

public:

    std::string name; 

    int score;

    CardCollection _PlayArea;

    CardCollection _Bank;

    Player(std::string name);

    
    bool playCard(Card* card, Game& game);

    bool isBust();

    void moveCardToBank();

    void print();

    const int getScore() const;
    
    const std::string getName() const; 

    virtual ~Player() {}


};