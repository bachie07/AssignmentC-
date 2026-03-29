#pragma once
#include "Card.h"


class CannonCard : public Card {

public:
    CannonCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override;


};

class ChestCard : Card {

    ChestCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override;


};

class KeyCard : Card {

    KeyCard(int value);
    
    std::string str() const override;

    void play(Game& game, Player& player) override; 



};


class SwordCard : Card {

    SwordCard(int value); 

    std::string str() const override;
    
    void play(Game& game, Player& player) override; 

};


class MapCard : Card {

    MapCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 


};


class KrakenCard : Card {
    
    KrakenCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 


};


class MermaidCard : Card {

    MermaidCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 




};


class OracleCard : Card {

    OracleCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 




};

class HookCard : Card {

    HookCard(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override; 

};





