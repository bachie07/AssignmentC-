#include "Game.h"
#include "game_title.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include <Card.h>



Game::Game(){}

void Game::startGame() {


    std::cout << GAME_TITLE << std::endl;

    std::cout << "Starting Dead Man's Draw++!\n" << std::endl;


    int i = 0;

    _currentRound = 1;

    _currentTurn = 1;

    while (i < 5) {

        initialisePlayer();

        std::cout << "--- Round " << _currentRound << ", Turn " << _currentTurn << " ---" << std::endl;

        std::cout << _players[0]->getName() << "'s Bank:" << _players[0]->getBank() << std::endl;

        i++

    }

    
}

void Game::endGame() {

}


void Game::createDeck() {




}

void Game::shuffleDeck() {

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

    return nullptr;

}

bool Game::askDrawAgain() {

    return false;

}

void Game::switchPlayer() {

}

Game::~Game(){}





