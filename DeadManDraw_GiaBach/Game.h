#pragma once
#include "Player.h"



class Game {


public: 

    CardCollection deck;

    CardCollection discardPile;

    int _currentTurn;

    int _currentRound;

    Player* _currentPlayer;

    Game();

    void startGame();

    void endGame();

    void createDeck();

    void shuffleDeck();

    void initialisePlayer();

    void controlTurn();

    Card* drawCard();

    bool askDrawAgain();

    void switchPlayer();

    virtual ~Game() {};

};