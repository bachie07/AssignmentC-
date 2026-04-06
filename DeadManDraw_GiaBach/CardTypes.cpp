#include "CardTypes.h"
#include "Player.h"
#include "Game.h"
#include <map>
#include <vector>
#include <algorithm>

//CannonCard

CannonCard::CannonCard(int value) :

	Card("Cannon", value, Cannon) { }


std::string CannonCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void CannonCard::play(Game& game, Player& player) {

	Player* opponent = game.getOpponent();

	std::map<CardType, Card*> topCardMap;

	std::map<int, Card*> displayMap;

	CardCollection opponentBank = opponent->getBank();

	int choice;

	int counter = 1;


	std::cout << "Discard the top card of any suit from the other player's Bank to the Discard Pile" << "\n";

	
	for (Card* card : opponentBank) {

		if (topCardMap.find(card->_type) == topCardMap.end()) {

			topCardMap[card->_type] = card;

		}

		else if (card->value > topCardMap[card->_type]->value) {

			topCardMap[card->_type] = card;

		}

	}

	if (opponentBank.empty()) {
		std::cout << "No cards in the other player's Bank. Continue Play. \n";
		return;
	}

	for (const auto& cardDetail : topCardMap) { // display options to remove

		displayMap[counter] = cardDetail.second;

		std::cout << "(" << counter << ") " <<cardDetail.second->str() << "\n";

		counter++;
	}

	std::cout << "Which card do you pick?: ";

	std::cin >> choice;


	for (Card* card : opponentBank) {

		if (card == displayMap[choice]) {

			opponent->removeFromBank(card);
			game.addToDiscardPile(card);

		}
	}
	
	std::cout << displayMap[choice]->str() << "removed succesfully" << std::endl;

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

	Player* opponent = game.getOpponent();

	std::map<CardType, Card*> topCardMap;

	std::map<int, Card*> displayMap;

	CardCollection opponentBank = opponent->getBank();

	int choice;

	int counter = 1;


	std::cout << "Steal the top card of any suit from the other player's Bank to your play Area" << "\n";


	for (Card* card : opponentBank) {

		if (topCardMap.find(card->_type) == topCardMap.end()) {

			topCardMap[card->_type] = card;

		}

		else if (card->value > topCardMap[card->_type]->value) {

			topCardMap[card->_type] = card;

		}

	}

	if (opponentBank.empty()) {
		std::cout << "No cards in the other player's Bank. Continue Play. \n";
		return;
	}

	for (const auto& cardDetail : topCardMap) { // display options to remove

		displayMap[counter] = cardDetail.second;

		std::cout << "(" << counter << ") " << cardDetail.second->str() << "\n";

		counter++;
	}

	std::cout << "Which card do you pick?: ";

	std::cin >> choice;

	for (Card* card : opponentBank) {

		if (card == displayMap[choice]) {

			opponent->removeFromBank(card);
			player.addToPlayArea(card);

			if (player.isBust()) {

				for (Card* card : player.getPlayArea()) { // add play area cards to discard pile
					game.addToDiscardPile(card);
				}

				std::cout << "BUST! " << player.getName() << " losses all cards in play area" << "\n" << std::endl;

				player.clearPlayArea(); // clear play area

			}
			else {
				card->play(game, player);
				std::cout << displayMap[choice]->str() << "added succesfully" << std::endl;
			}

		}
	}
	
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
	 
	std::cout << " No effect but Mermaids are worth more" << "\n" << std::endl;
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








