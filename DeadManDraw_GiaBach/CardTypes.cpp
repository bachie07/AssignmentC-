#include "CardTypes.h"


//CannonCard

CannonCard::CannonCard(int value) :

	Card("Cannon", value, Cannon) { }


std::string CannonCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void CannonCard::play(Game& game, Player& player) {

	// implement later

}


//Chest Card


ChestCard::ChestCard(int value) :

	Card("Chest", value, Chest) { }


std::string ChestCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void ChestCard::play(Game& game, Player& player) {

	// implement later

}

void ChestCard::willAddToBank(Game& game, Player& player) {

	// implement later
}


//Key Card


KeyCard::KeyCard(int value) :

	Card("Key", value, Key) {}


std::string KeyCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void KeyCard::play(Game& game, Player& player) {

	// implement later

}

void KeyCard::willAddToBank(Game& game, Player& player) {

	// implement later
}




//Sword Card


SwordCard::SwordCard(int value) : 

	Card("Sword", value, Sword) { }




std::string SwordCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void SwordCard::play(Game& game, Player& player) {

	//implement later
}



//Map Card


MapCard::MapCard(int value) :

	Card("Map", value, Map) {
}




std::string MapCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void MapCard::play(Game& game, Player& player) {

	//implement later
}


//Kraken

KrakenCard::KrakenCard(int value) :

	Card("Kraken", value, Kraken) {
}




std::string KrakenCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void KrakenCard::play(Game& game, Player& player) {

	//implement later
}



//Mermaid

MermaidCard::MermaidCard(int value) :

	Card("Mermaid", value, Mermaid) {
}



std::string MermaidCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void MermaidCard::play(Game& game, Player& player) {

	//implement later
}


//Oracle

OracleCard::OracleCard(int value) :

	Card("Oracle", value, Oracle) {
}




std::string OracleCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void OracleCard::play(Game& game, Player& player) {

	//implement later
}



//Hook 

HookCard::HookCard(int value) :

	Card("Hook", value, Hook) {
}




std::string HookCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void HookCard::play(Game& game, Player& player) {

	//implement later

}








