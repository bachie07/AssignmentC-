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

    std::cout << "--- Round " << _currentRound << ", Turn " << _currentTurn << " ---" << std::endl;

    controlTurn();

    
}

void Game::endGame() {

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

    while (continueTurn) {

        Card* cardDrawn = drawCard(); // draw card

        _currentPlayer->addToPlayArea(cardDrawn);

        std::cout << _currentPlayer->getName() << " draws a " << cardDrawn->str() << std::endl;

        bool isBust = _currentPlayer->isBust(); // check bust

        if (isBust == true) { // move to discard pile

            for (Card* card : _currentPlayer->getPlayArea()) { // add play area cards to discard pile
                _discardPile.push_back(card);
            }

            _currentPlayer->clearPlayArea();
        }

        else {
            cardDrawn->play(*this, *_currentPlayer); // 
            askDrawAgain();
            _currentPlayer->printPlayArea();

            if (askDrawAgain() == false) {

                _currentPlayer->moveCardToBank();
                break;

            }
        }




    }


}

Card* Game::drawCard() {

    Card* cardDrawn = _deck.front();

    _deck.erase(_deck.begin());

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

    _currentPlayer = _players[1];

}



Game::~Game(){}





