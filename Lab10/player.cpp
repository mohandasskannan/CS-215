/* Mohandass Kannan
 * File: player.cpp
 * Course: CS215-00x
 *
 */

#include "player.h"
#include <random>

// default constructor
Player::Player()
{
	numCards = 0;
	cards = {};
}

// alternate constructor
Player::Player(vector<Card> ini_cards)
{
	numCards = ini_cards.size();
	for (int i = 0; i < ini_cards.size(); i++) {
		cards.push_back(ini_cards[i]);
	}
}

// returns the number of cards in the list
int Player::getNumCards() const
{
	return numCards;
}

// return a card from the front of the cards deck
Card Player::play_a_card()
{
	Card toDeal = cards.front();
	cards.pop_front();
	numCards--;
	return toDeal;
}

void Player::addCards(vector<Card> winningCards)
{

	// add the cards to winning cards
	for (int i = 0; i < winningCards.size(); i++) {
		cards.push_back(winningCards[i]);
		numCards++;
	}
}

// when the cards are tied, each player will drop three cards
vector<Card> Player::dropCards()
{
	vector<Card> drop;
	// drops three cards
	int dropCount = min(3, (int)cards.size());
	
	// for every card out of the three, add it to the dropped 
	// cards and remove it from the front of the actual cards list
	for (int i = 0; i < dropCount; i++) {
		drop.push_back(cards.front());
		cards.pop_front();
		numCards--;
	}

	// When you run out of cards, print this
	if (numCards == 0) {
		cout << endl;
		cout << "Not enough cards!" << endl;
		if (dropCount < 3)
		{
			return vector<Card>();
		}
		
	}


	// return the dropped cards
	return drop;
}

// prints the player's cards
void Player::print() const
{
	int count = 0;

	// prints out every card in cards with a space in between
	for (const auto& card : cards) {
		card.print();
		cout << " ";

		count++;

		// formatting
		if (count % 8 == 0)
		{
			cout << endl;
		}
		

	}
	cout << endl;
}
