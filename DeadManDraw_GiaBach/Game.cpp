#include "Game.h"
#include "game_title.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"



Game::Game(){}

void Game::startGame() {

    std::cout << GAME_TITLE << std::endl;

    initialisePlayer();

    std::cout << "Welcome" << _players[0]->getName() << "to Dead Man Draw!" << std::endl;
    
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

    std::cout << Game::_players[0]->getName() << _players[1]->getName() << std::endl;

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





