#pragma once
#include <string>
#include "Card.h"

class Player {

public:

    Player(std::string name);
    
    bool playCard(Card* card, Game& game);

    bool isBust();

    void moveCardToBank(Game& game, Player& player);

    void printBank();

    void printPlayArea();

    int getScore() const;

    void addToPlayArea(Card* card); // add to UML

    void clearPlayArea(); // add to UML

    void printScore(); 
    
    std::string getName() const; 

    const CardCollection& getBank() const; // add to UML

    void removeFromBank(Card* card);

    void addToBank(Card* card);

    CardCollection getPlayArea() const;

    virtual ~Player() {}




    

private: 

    std::string playerName;

    int score;

    CardCollection _PlayArea;

    CardCollection _Bank;


};