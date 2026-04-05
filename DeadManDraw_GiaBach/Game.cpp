#include "Game.h"
#include "game_title.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Card.h"
#include <list>
#include "CardTypes.h"
#include <algorithm>
#include <random>


Game::Game(){}

void Game::startGame() {

    _currentRound = 1;

    _currentTurn = 1;

    createDeck();

    shuffleDeck();

    std::cout << GAME_TITLE << std::endl;

    std::cout << "Starting Dead Man's Draw++!\n" << std::endl;

    initialisePlayer();

    _currentPlayer = _players[0];

    while (!_deck.empty() && _currentTurn < 20) {

        std::cout << "--- Round " << _currentRound << ", Turn " << _currentTurn << " ---\n" << std::endl;

        controlTurn();
        _currentTurn++;
        
        if (_currentTurn % 2 == 1) {

            _currentRound++;
        }

    }

    endGame();

    


}

void Game::endGame() {

    std::cout << "Game ended, thanks for playing Dead Man's Draw!" << std::endl;
         
}


void Game::createDeck() {

    for (int value = 2; value <= 7; value++) {

        _deck.push_back(new CannonCard(value));
        _deck.push_back(new ChestCard(value));
        _deck.push_back(new KeyCard(value));
        _deck.push_back(new SwordCard(value));
        _deck.push_back(new HookCard(value));
        _deck.push_back(new OracleCard(value));
        _deck.push_back(new MapCard(value));
        _deck.push_back(new KrakenCard(value));

    }

    for (int value = 4; value <= 9; value++){

        _deck.push_back(new MermaidCard(value));

    }

}

void Game::shuffleDeck() {

    std::random_device rd;

    std::mt19937 g(rd());

    std::shuffle(_deck.begin(), _deck.end(), g);

}

void Game::initialisePlayer() {

    srand(std::time(0));

    std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };

    std::string _player1Name = names[rand() % 10];

    _players[0] = new Player(_player1Name);

    std::string _player2Name = names[rand() % 10];

    _players[1] = new Player(_player2Name);

}

void Game::controlTurn() {

    bool continueTurn = true;

    std::cout << _currentPlayer->getName() << "'s turn.\n" << std::endl;

    while (continueTurn) {

        _currentPlayer->printBank();

        _currentPlayer->printScore();

        Card* cardDrawn = drawCard(); // draw card

        _currentPlayer->addToPlayArea(cardDrawn);

        std::cout << _currentPlayer->getName() << " draws a " << cardDrawn->str() << "\n" << std::endl;

        bool isBust = _currentPlayer->isBust(); // check bust

        if (isBust == true) { // move to discard pile

            for (Card* card : _currentPlayer->getPlayArea()) { // add play area cards to discard pile
                _discardPile.push_back(card);
            }

            std::cout << "BUST! " << _currentPlayer->getName() << " losses all cards in play area" << "\n" << std::endl;

            _currentPlayer->clearPlayArea(); // clear play area
            switchPlayer(); //  switch player 
            continueTurn = false;

        }

        else {
            cardDrawn->play(*this, *_currentPlayer); // play card ability 
            _currentPlayer->printPlayArea(); // print play area
            bool drawAgain = askDrawAgain();

            if (drawAgain == false) { // if player doesnt play again

                _currentPlayer->moveCardToBank();
                _currentPlayer->printBank();
                _currentPlayer->printScore();
                switchPlayer();
                break;

            }
            else {
                continueTurn = true;
            }
        }

    }

}

Card* Game::drawCard() {

    Card* cardDrawn = _deck.front(); // draw from front deck

    _deck.erase(_deck.begin()); // erase from deck

    return cardDrawn;
}


bool Game::askDrawAgain() {

    std::string drawAgain;

    std::cout << "Draw Again? (y/n): ";

    std::cin >> drawAgain;

    if (drawAgain == "y") {
        return true;
    }
    else {
        return false;
    }

}

void Game::switchPlayer() {

    if (_currentPlayer = _players[0]) {
        _currentPlayer = _players[1];
    }
    else {
        _currentPlayer = _players[0];
    }

}

CardCollection Game::getDiscardPile() {

    return _discardPile;

}

Player* Game::getOpponent() {

    if (_currentPlayer == _players[0]) {

        return _players[1];

    }

    else {
        return _players[0];
    }

}



Game::~Game(){}





