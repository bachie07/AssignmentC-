#pragma once
#include <string>
#include "Card.h"

class Player {

public:

    std::string playerName; 

    int score;

    CardCollection _PlayArea;

    CardCollection _Bank;

    Player(std::string name);

    
    bool playCard(Card* card, Game& game);

    bool isBust();

    void moveCardToBank();

    void print();

    int getScore() const;
    
    std::string getName() const; 

    virtual ~Player() {}


};