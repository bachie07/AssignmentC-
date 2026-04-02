#pragma once
#include "Card.h"


class CannonCard : public Card {

public:
    CannonCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override;


};

class ChestCard : public Card {

public:

    ChestCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override;

    void willAddToBank(Game& game, Player& player) override;


};

class KeyCard : public Card {

public:

    KeyCard(int value);
    
    std::string str() const override;

    void play(Game& game, Player& player) override; 

    void willAddToBank(Game& game, Player& player) {};

};


class SwordCard : public Card {
public:

    SwordCard(int value); 

    std::string str() const override;
    
    void play(Game& game, Player& player) override; 

};


class MapCard : public Card {
public:

    MapCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 


};


class KrakenCard : public Card {
public:
    
    KrakenCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 


};


class MermaidCard : public Card {
public:

    MermaidCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 




};


class OracleCard : public Card {
public:

    OracleCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 




};

class HookCard : public Card {
public:

    HookCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 


};





