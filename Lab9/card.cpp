/* Mohandass Kannan
 * File: card.cpp
 * Course: CS215-00x
 * 
 */

#include "card.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

// Default constructor.
	// We allow uninitialized Cards to be created.
	// This allows arrays of Cards.
	// Uninitialized cards should have Invalid for its suit
	// and 0 for its points.


// default constructor for Card
Card::Card()
{
	// Starts at invalid
	suit = 'I';
	// number starts at 0
	point = 0;
}

// Constructor for card, which has a suit and point parameter
Card::Card(char s, int p)
{
	suit = s;
	point = p;
}


// returns the point of a card
int Card::getPoint() const
{
	return point;
}

// returns the suit of a card
char Card::getSuit() const
{
	return suit;
}

// compares the number of a card to another
int Card::compareTo(Card other) const
{
	if (point < other.point)
	{
		return -1;
	}

	if (point > other.point)
	{
		return 1;
	}

	// if the numbers are equal
	return 0;
}

// prints out the card
void Card::print() const
{
	// has a letter for the cards with a greater integer number than 10
	const int STARTLETTERPOINT = 11;
	string face;

	// if the point is greater than 10, have a face value
	if (point >= STARTLETTERPOINT)
	{
		switch(point)
		{
		case 11: face = "J"; break;
		case 12: face = "Q"; break;
		case 13: face = "K"; break;
		case 14: face = "A"; break;
		}
		
	}
	// if it is 10 or less, than convert the string to a number
	else {
		face = to_string(point);
	}
	// Then, switch to suits and print whatever suit the card is with its appropriate face value
	switch (suit) {
	case 'C': cout << CLUB << setw(2) << face << CLUB; break;
	case 'D': cout << DIAMOND << setw(2) << face << DIAMOND; break;
	case 'H': cout << HEART << setw(2) << face << HEART; break;
	default: cout << SPADE << setw(2) << face << SPADE; break;

	}
}

