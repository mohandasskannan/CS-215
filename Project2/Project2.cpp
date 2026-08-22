/*
 * Mohandass Kannan
 * Course: CS215-00x
 * Project: Main Project
 * Purpose: This is a project that plays the card game "WAR". It uses a shuffling 
 * card system and compares cards and then moves them around two different players. 
 * The game ends when a player or both the players run out of cards to put into the pile.
 * 
 */
#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

int main()
{
    // Avoid magic numbers
    const int HANDS = 26;    // each player holds 52/2 = 26 cards to begin the game

    // create an object of Deck class to represent standard 52-card deck
    // create a 52-card deck first
    // for testing purpose:  DO NOT shuffle the cards
    Deck testDeck;
    testDeck.createDeck();
    //testDeck.shuffleDeck();

    bool end_option = true;

    // The purpose of this part is to test whether the definition of Player class is correct 
    // deal 26 cards from the deck to store into cards_for_Player (represent cards given to the player)
    // another 26 cards put on the pile (left on the table) 
    vector<Card> cards_for_Player1;
    vector<Card> cards_for_Player2;
    vector<Card> pile;      // represents the pile of cards on the table


    // Deal the cards to player 1 and player 2
    for (int i = 0; i < HANDS; i++)
    {
        
        cards_for_Player1.push_back(testDeck.deal_a_card());
        cards_for_Player2.push_back(testDeck.deal_a_card());

    }

    // initalize
    Player player1(cards_for_Player1);
    Player player2(cards_for_Player2);


    // start the loop for a turn of the game
    while (true) {
    // deal and display a player 1 card and then add it to the pile, and print
    cout << "Player 1 plays: ";
    Card faceup1 = player1.play_a_card();
    pile.push_back(faceup1);
    faceup1.print();
    cout << endl;
    // deal and display a player 2 card and then add it to the pile, and print
    cout << "Player 2 plays: ";
    Card faceup2 = player2.play_a_card();
    pile.push_back(faceup2);
    faceup2.print();
    cout << endl;
    // print out the size of the pile
    cout << "----------------------------------------------" << endl;
    cout << endl;
    cout << "There are " << pile.size() << " cards on the pile!" << endl;
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;


    // Compare player 1 and player 2's cards
    // This is if player 2 wins
    if (faceup1.compareTo(faceup2) == -1) {
        cout << "Player 2 wins...get all cards from the pile!" << endl;
        player2.addCards(pile);
        pile.clear();
    }
    // If player 1 wins
    else if (faceup1.compareTo(faceup2) == 1) {
        cout << "Player 1 wins...get all cards from the pile!" << endl;
        player1.addCards(pile);
        pile.clear();
    }
    // If there is a tie
    else {

        cout << "It is a tie...for this round!" << endl;
        cout << "Each player drops three cards(face down) on the pile, then" << endl;
        cout << "play one more card(face up)" << endl;

        // end the loop when there are not enough cards to drop
        if (player1.getNumCards() < 4)
        {
            break;
        }


        if (player2.getNumCards() < 4)
        {
            break;
        }

        // Make a vector to store the dropped cards
        vector<Card> dropCards1 = player1.dropCards();
        vector<Card> dropCards2 = player2.dropCards();

        // For every dropped card in dropCards(), add it to the pile
        for (int i = 0; i < 3; i++) {
            pile.push_back(dropCards1[i]);
        }

        for (int i = 0; i < 3; i++) {
            pile.push_back(dropCards2[i]);
        }

        // Display the pile size again
        cout << "----------------------------------------------" << endl;
        cout << endl;
        cout << "There are " << pile.size() << " cards on the pile!" << endl;
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;

    }

    // When either player has 0 cards, end the loop

    if (player1.getNumCards() == 0 || player2.getNumCards() == 0) {
        break;
    }


    // Boolean to keep the program going without user input. If end option is true, input is required.
    // If end option is false, no input is required
    if (end_option) {
        string keepgoing;
        cout << "Do you want to continue? (N or n to quit)" << endl;
        // use getline
        getline(cin, keepgoing);
        if (keepgoing == "N" || keepgoing == "n") {
            cout << "You choose to quit the game!" << endl << endl;
            cout << "Player1 has " << player1.getNumCards() << " cards left! " << endl << endl;
            cout << "Player2 has " << player2.getNumCards() << " cards left! " << endl << endl;
            return 0;
        }
    }
        
    }

    // Check for score when finished
    int n1 = player1.getNumCards();
    int n2 = player2.getNumCards();

    // If there is a tie
    if (n1 == n2) {
        cout << "Game is over!" << endl;
        cout << "It is a tie game!" << endl;
        cout << "Player1 has " << player1.getNumCards() << " cards in hand!" << endl;
        cout << "Player2 has " << player2.getNumCards() << " cards in hand!" << endl;

    }
    // If Player 2 wins the game
    else if (n1 == 0) {
        cout << "Game is over!" << endl;
        cout << "Player 2 wins the game!" << endl;
        cout << "Player1 has " << player1.getNumCards() << " cards in hand!" << endl;
        cout << "Player2 has " << player2.getNumCards() << " cards in hand!" << endl;

    }
    // If Player 1 wins the game
    else if (n2 == 0) {
        cout << "Game is over!" << endl;
        cout << "Player 1 wins the game!" << endl;
        cout << "Player1 has " << player1.getNumCards() << " cards in hand!" << endl;
        cout << "Player2 has " << player2.getNumCards() << " cards in hand!" << endl;

    }
    // done
    return 0;
}
