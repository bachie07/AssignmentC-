#include "Player.h"
#include <map>
#include <numeric>
#include <string>
#include <iostream>
#include <algorithm>
#include <CardTypes.h>

Player::Player(std::string name) :

    playerName(name) {}



bool Player::playCard(Card* card, Game& game) {

    return true;

}


bool Player::isBust() {

    if (_PlayArea.empty()) {
        return false;
    }

    Card* newCard = _PlayArea.back();

    for (Card* card : _PlayArea) {

        if (card->_type == newCard->_type && card->value != newCard->value) {

            return true;

        }
    }
    return false;
}

void Player::moveCardToBank(Game& game, Player& player) {

    bool hasChest = false;
    bool hasKey = false;

    for (Card* card : _PlayArea) {

        if (card->_type == Chest) {
            hasChest = true;
        }
        if (card->_type == Key) {
            hasKey = true;
        }

        if (hasChest && hasKey) {
            card->willAddToBank(game, player);
        }

    }

    _Bank.insert(_Bank.end(), _PlayArea.begin(), _PlayArea.end());

    _PlayArea.clear();

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

    std::cout << "\n";

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
    std::cout << "\n";
}

int Player::getScore() const{

    std::map<CardType, int> scoreMap; 

    for (Card* card : _Bank) {

        if (scoreMap.find(card->_type) == scoreMap.end()) {

            scoreMap[card->_type] = card->value;
        }
        else if (card->value > scoreMap[card->_type]) {

            scoreMap[card->_type] = card->value;
        }
    }

    int total = std::accumulate(scoreMap.begin(), scoreMap.end(), 0,
        [](int current_sum, const auto& pair) {
            return current_sum + pair.second;
        });


    return total;
}

void Player::printScore() {

    std::cout << "| Score: " << getScore() << "\n" << std::endl;

} 

void Player::addToPlayArea(Card* card) {

    _PlayArea.push_back(card);

}

void Player::clearPlayArea() {

    _PlayArea.clear();
}

std::string Player::getName() const {

    return playerName;

}

const CardCollection& Player::getBank() const {
    
    return _Bank;

}

void Player::removeFromBank(Card* card) {

    CardCollection& bank = _Bank;

    bank.erase(std::remove(bank.begin(), bank.end(), card), bank.end());
}

void Player::addToBank(Card* card) {

    CardCollection& bank = _Bank;
    bank.insert(bank.begin(), card);

}

CardCollection Player::getPlayArea() const {

    return _PlayArea;
}






    