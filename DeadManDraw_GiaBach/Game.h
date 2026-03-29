#pragma once
#include "Player.h"
#include "Card.h"



class Game {


private: 

    CardCollection _deck;

    CardCollection _discardPile;

    int _currentTurn;

    int _currentRound;

    Player* _currentPlayer;

    Player* _players[2];


public:

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

    ~Game();

};