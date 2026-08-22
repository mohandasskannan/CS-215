/* Mohandass Kannan
 * File: deck.cpp
 * Course: CS215-00x
 * 
 */

#include "deck.h"
#include <random>



// make 52 cards and make 13 of each suit
void Deck::createDeck()
{
	for (int i = 0; i < POINTS; i++)
	{
		for (char j : {'D', 'S', 'C', 'H'})
		{
			Card toAdd(j, i + CARD_START);
			deck.push_back(toAdd);
		}
	}
}

// shuffles the deck
void Deck::shuffleDeck()
{
	srand(time(0));
	random_shuffle(deck.begin(), deck.end());

}

// makes a variable that gets the last card in the deck, and then returns and deletes it
Card Deck::deal_a_card()
{
	Card toMake = deck[deck.size() - 1];
	deck.pop_back();
	return toMake;

}
