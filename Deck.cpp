/* Deck.h
* Author: Hunter Ripsom-Gardiner
* Date: 10/30/14 
* Course: CSC 5210 Graphics
* Description: A class to represent a deck of cards. contains a 
* vector of cards. Has the ability to shuffle itself, to cut itself 
* into two equal halves, to add a card, and to remove a card.
*/

#include "Deck.h"

void Deck::drawSelf()
{
	for (std::vector<Card>::iterator it = deckVector.begin() ; it != deckVector.end(); it++)
	{
		//for each card draw itself.
		it->drawSelf();
	}
}