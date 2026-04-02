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


    std::cout << GAME_TITLE << std::endl;

    std::cout << "Starting Dead Man's Draw++!\n" << std::endl;

    _currentRound = 1;

    _currentTurn = 1;

    initialisePlayer();

    createDeck();

    shuffleDeck();

    std::cout << "--- Round " << _currentRound << ", Turn " << _currentTurn << " ---" << std::endl;



    
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

    std::cout << _deck.size();

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


}

Card* Game::drawCard() {

    Card* cardDrawn = _deck.front();

    _deck.erase(_deck.begin());

    return cardDrawn;
}

bool Game::askDrawAgain() {

    return false;

}

void Game::switchPlayer() {

}

Game::~Game(){}





