#pragma once

#include <iostream>
#include <string>
#include <vector>

class Game;
class Player;

enum CardType {

    Cannon,
    Chest,
    Key,
    Anchor,
    Sword,
    Hook,
    Oracle,
    Map,
    Mermaid,
    Kraken
};

class Card {


public:
    std::string suit;
    int value;
    CardType _type;


    Card(std::string suit, int value, CardType type);


    virtual std::string str() const = 0;


    virtual void play(Game& game, Player& player) = 0;

    virtual void willAddToBank(Game& game, Player& player) {}; 

    const CardType& type() const; 

    virtual ~Card() {}


};
