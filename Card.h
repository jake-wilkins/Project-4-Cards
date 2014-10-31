/* Card.h
* Author: Hunter Ripsom-Gardiner
* Date: 10/30/14 
* Course: CSC 5210 Graphics
* Description: A class to represent a single card. Contains a value, a suit, 
* six faces and a vertex array to hold its position in space.
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

#include "Face.h"

//the numerical values of the face cards and ace.
enum { J = 11, Q = 12, K = 13, A = 14};
//the types of suit
enum { HEART, CLUB, DIAMOND, SPADE };

class Card{
private:
	int value;
	int suit;
	std::vector<Face> faceVector;

public:
	void drawSelf();
	
};