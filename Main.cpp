/* Main.cpp
* Author: Hunter Ripsom-Gardiner
* Date: 10/30/14 
* Course: CSC 5210 Graphics
* Description: A class to represent a game of the card game war.
* contains a deck of 52 cards and splits the deck for the two players.
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

#include "lodepng.h"

using std::cout;
using std::endl;
using std::cerr;

const GLuint WIN_HEIGHT = 512;
const GLuint WIN_WIDTH = 512;

// Enumerations
// Vertex array objects
enum {  NUM_VAOS };
// Buffers
enum {  NUM_BUFFERS };
// textures
enum { NUM_TEXTURES };

// Data is stored in these arrays
//GLuint VAOs[ NUM_VAOS ];
//GLuint Buffers[ NUM_BUFFERS ];
//GLuint Textures[ NUM_TEXTURES ];

//the initialized function.
void init()
{ 
	ShaderInfo shaders[] = {
		{GL_VERTEX_SHADER, "vertices.vert"},
		{GL_FRAGMENT_SHADER, "fragments.frag"},
		{GL_NONE, NULL}
	};
	GLuint vertexOffset = 0;
	GLuint program = LoadShaders( shaders );
	glUseProgram( program );

	//alows you to use 2D textures
	glEnable(GL_TEXTURE_2D);
	
	
}

//the display function.
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);


	glFlush();
}

//A function that handles keyboard input. takes as input the key 
//clicked and the mouse's current position.
void keyboard(unsigned char key, int x, int y)
{
	switch( key ) 
	{
	case 'q':
	case 'Q':
		exit(0);
		break;

	//if any other key is pressed a message is output.
	default:
		cerr << "Invalid key pressed: " << key << endl;
		break;
	}

	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	//the display mode is in red, green, blue, transparancy mode.
	glutInitDisplayMode(GLUT_RGBA);
	//make the window have size equal to the 
	//constants X and Y declared at the top of the program.
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT); 
	//using GLUT version 4.1. You need to use a ',' instead of a '.' because reasons.
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("Hunter and Alex's Awesome Camera Thing"); //name the window

	glewExperimental=GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}

	init();
	glutDisplayFunc(display);
	glutKeyboardFunc( keyboard ); 
	glutMainLoop();

	return 0;
}