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

	std::map<CardType, Card*> topCardMap; // map storing highest card

	std::map<int, Card*> displayMap; // map used to display options for users

	CardCollection opponentBank = opponent->getBank();

	int choice;

	int counter = 1;


	std::cout << "Discard the top card of any suit from the other player's Bank to the Discard Pile" << "\n";

	
	if (opponentBank.empty()) { // return if empty
		std::cout << "No cards in the other player's Bank. Continue Play. \n";
		return;
	}

	for (Card* card : opponentBank) { // loop through bank 

		if (topCardMap.find(card->_type) == topCardMap.end()) { // add if card doesnt exist

			topCardMap[card->_type] = card;

		}

		else if (card->value > topCardMap[card->_type]->value) { // replace if card has higher value

			topCardMap[card->_type] = card;

		}

	}


	for (const auto& cardDetail : topCardMap) { // display options to remove

		displayMap[counter] = cardDetail.second; // store card pointer in display map 

		std::cout << "(" << counter << ") " <<cardDetail.second->str() << "\n"; 

		counter++;
	}

	std::cout << "\n";

	std::cout << "Which card do you pick?: ";

	std::cin >> choice;

	std::cout << "\n";

	while (choice < 1 || choice > counter - 1) {
		std::cout << "Invalid choice. Pick again: ";
		std::cin >> choice;
	}

	for (Card* card : opponentBank) {

		if (card == displayMap[choice]) { // remove if card in bank similar with card of choice

			opponent->removeFromBank(card);
			game.addToDiscardPile(card);

		}
	}
	
	std::cout << displayMap[choice]->str() << " removed succesfully\n" << std::endl;

}




//Chest Card


ChestCard::ChestCard(int value) :

	Card("Chest", value, Chest) { }


std::string ChestCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void ChestCard::play(Game& game, Player& player) {

	std::cout << "  No immediate effect. If banked with a key, draw as many bonus cards from the Discard pile as you moved to your Bank\n";

}

void ChestCard::willAddToBank(Game& game, Player& player) {

	for (Card* card : player.getPlayArea()) {

		if (card->_type == Key) {

			int playAreatotalCards = player.getPlayArea().size();
			
			CardCollection& discardPile = game.getDiscardPile();

			if (discardPile.empty()) {
				std::cout << "No cards in discard pile. Play continues\n";
				return;
			}

			std::cout << "Added ";

			for (int i = 0; i < playAreatotalCards && !discardPile.empty(); i++) {

				Card* bonusCard = discardPile.front();

				player.addToBank(bonusCard);

				std::cout << bonusCard->str() << ", ";

				discardPile.erase(discardPile.begin());

			}
			std::cout << "to your bank\n";

			return;
		}

	}
}





//Key Card


KeyCard::KeyCard(int value) :

	Card("Key", value, Key) {}


std::string KeyCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void KeyCard::play(Game& game, Player& player) {

	std::cout << "No immediate effect. If banked with a chest, draw as many bonus cards from the Discard pile as you moved into your Bank\n";

}

void KeyCard::willAddToBank(Game& game, Player& player) {

	for (Card* card : player.getPlayArea()) {

		if (card->_type == Chest) {

			int playAreatotalCards = player.getPlayArea().size();

			CardCollection& discardPile = game.getDiscardPile();

			if (discardPile.empty()) {
				std::cout << "No cards in discard pile. Play continues\n";
				return;
			}

			std::cout << "Added ";

			for (int i = 0; i < playAreatotalCards && !discardPile.empty(); i++) {

				Card* bonusCard = discardPile.front();

				player.addToBank(bonusCard);

				std::cout << bonusCard->str() << ", ";

				discardPile.erase(discardPile.begin());

			}
			std::cout << "to your bank\n";

			return;
		}

	}
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

	if (opponentBank.empty()) {
		std::cout << "No cards in the other player's Bank. Continue Play.\n";
		return;
	}

	for (Card* card : opponentBank) { // loop through bank

		if (topCardMap.find(card->_type) == topCardMap.end()) { // add if doesnt exist

			topCardMap[card->_type] = card;

		}

		else if (card->value > topCardMap[card->_type]->value) { // replace if card point is higher

			topCardMap[card->_type] = card;

		}

	}


	for (const auto& cardDetail : topCardMap) { // display options to remove

		displayMap[counter] = cardDetail.second;

		std::cout << "(" << counter << ") " << cardDetail.second->str() << "\n";

		counter++;
	}

	std::cout << "\n";

	std::cout << "Which card do you pick?: ";

	std::cin >> choice;

	std::cout << "\n";

	while (choice < 1 || choice > counter - 1) {
		std::cout << "Invalid choice. Pick again: ";
		std::cin >> choice;

	}
	std::cout << player.getName() << "draws a " << displayMap[choice]->str() <<"\n";

	for (Card* card : opponentBank) {

		if (card == displayMap[choice]) { // if card of choice in bank

			opponent->removeFromBank(card); // remove
			player.addToPlayArea(card); // add to play area
			card->play(game, player);

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

	CardCollection& discardPile = game.getDiscardPile();
	
	int choice;

	int displayCount = std::min((int)discardPile.size(), 3);


	if (discardPile.empty()) {
		std::cout << "No cards in the discard pile to pick from. Continue Turn\n";
		return;
	}

	std::cout << "Draw 3 cards from the discard and pick one to add to the play area\n";
		
	for (int i = 0; i < displayCount && !discardPile.empty(); i++) {

		std::cout << "(" << i+1 << ") " << discardPile.at(i)->str() << "\n";

	}

	std::cout << "\n";

	std::cout << "Which card do you pick: ";

	std::cin >> choice;

	std::cout << "\n";

	while (choice > displayCount || choice < 1) {

		std::cout << "\n";

		std::cout << "Which card do you pick: ";

		std::cin >> choice;
		
		std::cout << "\n";
	}

	Card* chosenCard = discardPile.at(choice - 1); // chosen card

	std::cout << player.getName() << "draws a " << chosenCard->str() << "\n";

	discardPile.erase(discardPile.begin() + (choice - 1));
	player.addToPlayArea(chosenCard);

	chosenCard->play(game, player);

}


//Kraken

KrakenCard::KrakenCard(int value) :

	Card("Kraken", value, Kraken) {
}




std::string KrakenCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void KrakenCard::play(Game& game, Player& player) {

	for (int i = 0; i < 3 && !game.getDeck().empty(); i++) {

		Card* cardDrawn = game.drawCard();

		std::cout << player.getName() << " draws a " << cardDrawn->str() << "\n";

		player.addToPlayArea(cardDrawn);

		if (player.isBust()) {
			return;

		}

		cardDrawn->play(game, player);

		}
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

	CardCollection deck = game.getDeck();

	std::cout << "The Oracle sees a " << deck.front()->str() << "\n";

}



//Hook 

HookCard::HookCard(int value) :

	Card("Hook", value, Hook) {
}




std::string HookCard::str() const {

	return suit + "(" + std::to_string(value) + ")";

}

void HookCard::play(Game& game, Player& player) {

	std::map<CardType, Card*> topCardMap;

	std::map<int, Card*> displayMap;

	CardCollection bank = player.getBank();
	
	int counter = 1;

	int choice; 

	std::cout << "Play the top card of any suit from the your Bank into your Play Area \n";

	if (bank.empty()) {
		std::cout << "Current player bank has no cards. Continue Play \n";
		return;
	}

	for (Card* card : bank) {

		if (topCardMap.find(card->_type) == topCardMap.end()) {

			topCardMap[card->_type] = card;

		}

		else if (card->value > topCardMap[card->_type]->value) {

			topCardMap[card->_type] = card;
		}

	}


	for (const auto& cardDetail : topCardMap) {

		displayMap[counter] = cardDetail.second;

		std::cout << "(" << counter << ") " << cardDetail.second->str() << "\n";

		counter++;

	}

	std::cout << "\n";

	std::cout << "\nWhich card do you pick?: ";

	std::cin >> choice;

	std::cout << "\n";

	while (choice < 1 || choice > counter - 1) {
		std::cout << "Invalid choice. Pick again: ";
		std::cin >> choice;

	}

	std::cout << player.getName() << "draws a " << displayMap[choice]->str() << "\n";


	for (Card* card : bank) {

		if (displayMap[choice] == card) {

			player.removeFromBank(card);
			player.addToPlayArea(card);

			card->play(game, player);

			return;

		}

	}

}








