#include "Player.h"


Player::Player(std::string name) :

    playerName(name) {}



bool Player::playCard(Card* card, Game& game) {

    return true;

}


bool Player::isBust() {

    return true;
}

void Player::moveCardToBank() {

}

void Player::print() {

}

int Player::getScore() const{

    return score;

}

std::string Player::getName() const {

    return playerName;

}

CardCollection Player::getBank() const {
    
    return _Bank;
}






    