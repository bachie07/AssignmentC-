#include "Game.h"
#include "game_title.h"
#include <iostream>
#include "Player.h"



Game::Game(){}

void Game::startGame() {

    std::cout << GAME_TITLE << std::endl;

    initialisePlayer();

}

void Game::endGame() {

}


void Game::createDeck() {


}

void Game::shuffleDeck() {

}

void Game::initialisePlayer() {

    std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };

    std::string _player1Name = names[rand() % 10];

    Player player1(_player1Name);

    std::string _player2Name = names[rand() % 10];

    Player player2(_player2Name);

    std::cout << player1.getName() << player2.getName() << std::endl;

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





