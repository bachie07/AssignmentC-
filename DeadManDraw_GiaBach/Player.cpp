#include "Player.h"
#include <map>

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

void Player::printBank() {

    std::map<CardType, CardCollection> cardMap;

    std::cout << playerName << "'s Bank: " << std::endl;

    for(Card* card : _Bank){ // loop through bank

        cardMap[card->_type].push_back(card); // create new key entry if found, otherwise add to existing
         
    }

    for (const auto& cardDetail : cardMap) { // loop through cardMap
        
        std::cout << "    ";

        for (const Card* card : cardDetail.second) { // loop through value which store collection

            std::cout << card->str() << " ";

        }
        std::cout << "\n";
    }

}

void Player::printPlayArea() {

    std::map<CardType, CardCollection> cardMap;

    std::cout << playerName << "'s Play Area:" << std::endl;

    for (Card* card : _PlayArea) { // loop through bank

        cardMap[card->_type].push_back(card); // create new key entry if found, otherwise add to existing

    }

    for (const auto& cardDetail : cardMap) { // loop through cardMap

        std::cout << "    ";

        for (const Card* card : cardDetail.second) { // loop through value which store collection

            std::cout << card->str() << " ";

        }
        std::cout << "\n";
    }


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






    