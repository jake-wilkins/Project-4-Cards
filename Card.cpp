/* Card.cpp
* Author: Hunter Ripsom-Gardiner
* Date: 10/30/14 
* Course: CSC 5210 Graphics
* Description: A class to represent a single card. Contains a value, a suit, 
* six faces and a vertex array to hold its position in space.
*/

#include "Card.h"

void Card::drawSelf()
{
	for (std::vector<Face>::iterator it = faceVector.begin() ; it != faceVector.end(); it++)
	{
		//for each face draw itself.
		it->drawSelf();
	}
}