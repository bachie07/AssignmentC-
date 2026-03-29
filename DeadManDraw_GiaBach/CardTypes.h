#pragma once
#include "Card.h"


class CannonCard : public Card {

public:
    CannonCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override;


};

class ChestCard : public Card {

    ChestCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override;

    void willAddtoBank(Game& game, Player& player) {};



};

class KeyCard : public Card {

    KeyCard(int value);
    
    std::string str() const override;

    void play(Game& game, Player& player) override; 

    void willAddtoBank(Game& game, Player& player) {};

};


class SwordCard : public Card {

    SwordCard(int value); 

    std::string str() const override;
    
    void play(Game& game, Player& player) override; 

};


class MapCard : public Card {

    MapCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 


};


class KrakenCard : public Card {
    
    KrakenCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 


};


class MermaidCard : public Card {

    MermaidCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 




};


class OracleCard : public Card {

    OracleCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 




};

class HookCard : public Card {

    HookCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 

};





