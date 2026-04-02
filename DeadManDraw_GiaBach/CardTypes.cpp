#include "CardTypes.h"




CannonCard::CannonCard(int value) :

	Card("Cannon", value, Cannon) { }


std::string CannonCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void CannonCard::play(Game& game, Player& player) {

	// implement later

}



ChestCard::ChestCard(int value) :

	Card("Chest", value, Chest) { }


std::string ChestCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void ChestCard::play(Game& game, Player& player) {

	// implement later

}

void willAddToBank(Game& game, Player& player) {

	// implement later
}



KeyCard::KeyCard(int value) :

	Card("Key", value, Key) {}


std::string KeyCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void ChestCard::play(Game& game, Player& player) {

	// implement later

}




