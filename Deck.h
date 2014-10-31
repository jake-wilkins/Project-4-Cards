/* Deck.h
* Author: Hunter Ripsom-Gardiner
* Date: 10/30/14 
* Course: CSC 5210 Graphics
* Description: A class to represent a deck of cards. contains a 
* vector of cards. Has the ability to shuffle itself, to cut itself 
* into two equal halves, to add a card, and to remove a card. Can 
* also return the fact that the deck is empty.
*/

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdio>
// Local Utilities Includes
#include "vgl.h"
#include "vec.h"
#include "LoadShaders.h"
#include <vector>

#include <vmath.h>
#include "Card.h"

class Deck{
private:
	std::vector<Card> deckVector;

public:
	void drawSelf();
	
};