/* Author: Jake Wilkins
* CSC 5210 Graphics
* Date: 10/29/2014
* Last Updated: 11/4/2014
*
*
*
*/

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <cstdio>
#include <iostream>
#include <vector>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include "vgl.h"
#include "LoadShaders.h"
#include "lodepng.h"

#include "Card.h"
#define CARD_WIDTH 0.005

using namespace glm;

GLint WIN_WIDTH = 1024;
GLint WIN_HEIGHT = 768;

enum { TEX_1, TEX_2, TEX_3, TEX_4, NUM_TEX };
GLuint textures[NUM_TEX];

std::vector<Card*> p1_draw, p1_discard, p2_draw, p2_discard;

glm::mat4 Model;

GLuint MatrixID; 

GLfloat table_coords[] = {
	-0.9, 0.9, 1.0, 1.0,
	-0.9, -0.9, 1.0, 1.0,
	0.9, -0.9, 1.0, 1.0,
	0.9, 0.9, 1.0, 1.0,

	0.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	1.0f, 0.0f
};

GLuint VAOs[10];
GLuint Buffers[10];

// Create cards: (suit, #, x, y, z, tex x, tex y, tex x2, tex y2)
Card* clubs_A = new Card('c', 14, 488, 431, (0.5 - CARD_WIDTH), 1, 1, 72, 96);
Card* clubs_2 = new Card('c', 2, 488, 431, (1.0 - CARD_WIDTH), 74, 1, 145, 96);
Card* clubs_3 = new Card('c', 3, 488, 431, (1.0 - CARD_WIDTH), 147, 1, 218, 96);
Card* clubs_4 = new Card('c', 4, 488, 431, (1.0 - CARD_WIDTH), 220, 1, 291, 96);
Card* clubs_5 = new Card('c', 5, 488, 431, (1.0 - CARD_WIDTH), 293, 1, 364, 96);
Card* clubs_6 = new Card('c', 6, 488, 431, (1.0 - CARD_WIDTH), 366, 1, 437, 96);
Card* clubs_7 = new Card('c', 7, 488, 431, (1.0 - CARD_WIDTH), 439, 1, 510, 96);
Card* clubs_8 = new Card('c', 8, 488, 431, (1.0 - CARD_WIDTH), 512, 1, 583, 96);
Card* clubs_9 = new Card('c', 9, 488, 431, (1.0 - CARD_WIDTH), 585, 1, 646, 96);
Card* clubs_10 = new Card('c', 10, 488, 431, (1.0 - CARD_WIDTH), 648, 1, 709, 96);
Card* clubs_J = new Card('c', 11, 488, 431, (1.0 - CARD_WIDTH), 711, 1, 772, 96);
Card* clubs_Q = new Card('c', 12, 488, 431, (1.0 - CARD_WIDTH), 774, 1, 835, 96);
Card* clubs_K = new Card('c', 13, 488, 431, (1.0 - CARD_WIDTH), 837, 1, 898, 96);

Card* spades_A = new Card('s', 14, 488, 431, (1.0 - CARD_WIDTH), 1, 99, 72, 195);
Card* spades_2 = new Card('s', 2, 488, 431, (1.0 - CARD_WIDTH), 74, 99, 145, 195);
Card* spades_3 = new Card('s', 3, 488, 431, (1.0 - CARD_WIDTH), 147, 99, 218, 195);
Card* spades_4 = new Card('s', 4, 488, 431, (1.0 - CARD_WIDTH), 220, 99, 291, 195);
Card* spades_5 = new Card('s', 5, 488, 431, (1.0 - CARD_WIDTH), 293, 99, 364, 195);
Card* spades_6 = new Card('s', 6, 488, 431, (1.0 - CARD_WIDTH), 366, 99, 437, 195);
Card* spades_7 = new Card('s', 7, 488, 431, (1.0 - CARD_WIDTH), 439, 99, 510, 195);
Card* spades_8 = new Card('s', 8, 488, 431, (1.0 - CARD_WIDTH), 512, 99, 583, 195);
Card* spades_9 = new Card('s', 9, 488, 431, (1.0 - CARD_WIDTH), 585, 99, 646, 195);
Card* spades_10 = new Card('s', 10, 488, 431, (1.0 - CARD_WIDTH), 648, 99, 709, 195);
Card* spades_J = new Card('s', 11, 488, 431, (1.0 - CARD_WIDTH), 711, 99, 772, 195);
Card* spades_Q = new Card('s', 12, 488, 431, (1.0 - CARD_WIDTH), 774, 99, 835, 195);
Card* spades_K = new Card('s', 13, 488, 431, (1.0 - CARD_WIDTH), 837, 99, 898, 195);

Card* hearts_A = new Card('h', 14, 488, 431, (1.0 - CARD_WIDTH), 1, 197, 72, 292);
Card* hearts_2 = new Card('h', 2, 488, 431, (1.0 - CARD_WIDTH), 74, 197, 145, 292);
Card* hearts_3 = new Card('h', 3, 488, 431, (1.0 - CARD_WIDTH), 147, 197, 218, 292);
Card* hearts_4 = new Card('h', 4, 488, 431, (1.0 - CARD_WIDTH), 220, 197, 291, 292);
Card* hearts_5 = new Card('h', 5, 488, 431, (1.0 - CARD_WIDTH), 293, 197, 364, 292);
Card* hearts_6 = new Card('h', 6, 488, 431, (1.0 - CARD_WIDTH), 366, 197, 437, 292);
Card* hearts_7 = new Card('h', 7, 488, 431, (1.0 - CARD_WIDTH), 439, 197, 510, 292);
Card* hearts_8 = new Card('h', 8, 488, 431, (1.0 - CARD_WIDTH), 512, 197, 583, 292);
Card* hearts_9 = new Card('h', 9, 488, 431, (1.0 - CARD_WIDTH), 585, 197, 646, 292);
Card* hearts_10 = new Card('h', 10, 488, 431, (1.0 - CARD_WIDTH), 648, 197, 709, 292);
Card* hearts_J = new Card('h', 11, 488, 431, (1.0 - CARD_WIDTH), 711, 197, 772, 292);
Card* hearts_Q = new Card('h', 12, 488, 431, (1.0 - CARD_WIDTH), 774, 197, 835, 292);
Card* hearts_K = new Card('h', 13, 488, 431, (1.0 - CARD_WIDTH), 837, 197, 898, 292);

Card* diamonds_A = new Card('d', 14, 488, 431, (1.0 - CARD_WIDTH), 1, 295, 72, 390);
Card* diamonds_2 = new Card('d', 2, 488, 431, (1.0 - CARD_WIDTH), 74, 295, 145, 390);
Card* diamonds_3 = new Card('d', 3, 488, 431, (1.0 - CARD_WIDTH), 147, 295, 218, 390);
Card* diamonds_4 = new Card('d', 4, 488, 431, (1.0 - CARD_WIDTH), 220, 295, 291, 390);
Card* diamonds_5 = new Card('d', 5, 488, 431, (1.0 - CARD_WIDTH), 293, 295, 364, 390);
Card* diamonds_6 = new Card('d', 6, 488, 431, (1.0 - CARD_WIDTH), 366, 295, 437, 390);
Card* diamonds_7 = new Card('d', 7, 488, 431, (1.0 - CARD_WIDTH), 439, 295, 510, 390);
Card* diamonds_8 = new Card('d', 8, 488, 431, (1.0 - CARD_WIDTH), 512, 295, 583, 390);
Card* diamonds_9 = new Card('d', 9, 488, 431, (1.0 - CARD_WIDTH), 585, 295, 646, 390);
Card* diamonds_10 = new Card('d', 10, 488, 431, (1.0 - CARD_WIDTH), 648, 295, 709, 390);
Card* diamonds_J = new Card('d', 11, 488, 431, (1.0 - CARD_WIDTH), 711, 295, 772, 390);
Card* diamonds_Q = new Card('d', 12, 488, 431, (1.0 - CARD_WIDTH), 774, 295, 835, 390);
Card* diamonds_K = new Card('d', 13, 488, 431, (1.0 - CARD_WIDTH), 837, 295, 898, 390);


Card* deck[52] = { clubs_A, clubs_2, clubs_3, clubs_4, clubs_5, clubs_6, clubs_7, clubs_8, clubs_9, clubs_10, clubs_J, clubs_Q, clubs_K,
	spades_A, spades_2, spades_3, spades_4, spades_5, spades_6, spades_7, spades_8, spades_9, spades_10, spades_J, spades_Q, spades_K,
	hearts_A, hearts_2, hearts_3, hearts_4, hearts_5, hearts_6, hearts_7, hearts_8, hearts_9, hearts_10, hearts_J, hearts_Q, hearts_K,
	diamonds_A, diamonds_2, diamonds_3, diamonds_4, diamonds_5, diamonds_6, diamonds_7, diamonds_8, diamonds_9, diamonds_10, diamonds_J, diamonds_Q, diamonds_K,
};


float pixelToWindow(float pixel, char dimension)
{
	if (dimension == 'x')
		return (pixel / (WIN_WIDTH/2)) - 1;
	else if (dimension == 'y')
		return (pixel / (WIN_HEIGHT/2)) - 1;
}

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glActiveTexture(GL_TEXTURE0);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	ShaderInfo shaders[] = {
			{ GL_VERTEX_SHADER, "card_game.vert" },
			{ GL_FRAGMENT_SHADER, "card_game.frag" },
			{ GL_NONE, NULL }
	};
	GLuint program = LoadShaders(shaders);
	glUseProgram(program);

	MatrixID = glGetUniformLocation(program, "MVPMatrix");

	glGenTextures(NUM_TEX, textures);

	//===============================================
	// Texture for the card backs, TEX_1
	//===============================================
	char* tex_1_filename = "CARDBACK.png";
	std::vector<unsigned char> card_back_tex;
	unsigned tex_1_width, tex_1_height;
	unsigned tex_1_error = lodepng::decode(card_back_tex, tex_1_width, tex_1_height, tex_1_filename);
	if (tex_1_error) std::cout << "error " << tex_1_error << ": " << lodepng_error_text(tex_1_error) << std::endl;
	else std::cout << "File loaded!" << std::endl;

	glBindTexture(GL_TEXTURE_2D, textures[TEX_1]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex_1_width, tex_1_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &card_back_tex[0]);

	//===============================================
	// Texture for the card faces, TEX_2
	//===============================================
	char* tex_2_filename = "classic-playing-cards.png";
	std::vector<unsigned char> card_faces_tex;
	unsigned tex_2_width, tex_2_height;
	unsigned tex_2_error = lodepng::decode(card_faces_tex, tex_2_width, tex_2_height, tex_2_filename);
	if (tex_2_error) std::cout << "error " << tex_2_error << ": " << lodepng_error_text(tex_2_error) << std::endl;
	else std::cout << "File loaded!" << std::endl;

	glBindTexture(GL_TEXTURE_2D, textures[TEX_2]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex_2_width, tex_2_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &card_faces_tex[0]);

	//===============================================
	// Texture for the card edges, TEX_3
	//===============================================
	char* tex_3_filename = "card_edge.png";
	std::vector<unsigned char> card_edge_tex;
	unsigned tex_3_width, tex_3_height;
	unsigned tex_3_error = lodepng::decode(card_edge_tex, tex_3_width, tex_3_height, tex_3_filename);
	if (tex_3_error) std::cout << "error " << tex_3_error << ": " << lodepng_error_text(tex_3_error) << std::endl;
	else std::cout << "File loaded!" << std::endl;

	glBindTexture(GL_TEXTURE_2D, textures[TEX_3]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex_3_width, tex_3_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &card_edge_tex[0]);

	//===============================================
	// Texture for the table, TEX_4
	//===============================================
	char* tex_4_filename = "green-fabric.png";
	std::vector<unsigned char> table_tex;
	unsigned tex_4_width, tex_4_height;
	unsigned tex_4_error = lodepng::decode(table_tex, tex_4_width, tex_4_height, tex_4_filename);
	if (tex_4_error) std::cout << "error " << tex_4_error << ": " << lodepng_error_text(tex_4_error) << std::endl;
	else std::cout << "File loaded!" << std::endl;

	
	glBindTexture(GL_TEXTURE_2D, textures[TEX_4]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex_4_width, tex_4_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &table_tex[0]);
	
	// Initialize the deck of cards.
	for (int i = 0; i < 52; i++)
	{
		deck[i]->initializeCard();
	}

	glGenVertexArrays(10, VAOs);
	glGenBuffers(10, Buffers);
	
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(table_coords), table_coords, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*) (16 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);


}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);


	// 90 degree FoV (1/2 pi radians, that's the 1.57), a 4:3 aspect ratio, from 0.1 to 2.0. 
	// 0.1 is the minimum, essentially. Depth testing won't work if z_near is too close (0.0).
	glm::mat4 Projection = glm::perspective(half_pi<float>(), float(4 / 3), 0.1f, 2.0f);

	// Eye at (0.0, 0.0, 0.0), camera looking at (0.0, 0.0, 0.5), up vector is (0, 1, 0)
	glm::mat4 View = glm::lookAt(glm::vec3(0.0, -0.5, 0.0), glm::vec3(0, 0, 0.5), glm::vec3(0, 1, 0));

	// Loads the identity matrix since model doesn't transform.
	Model = glm::mat4(1.0f);

	// MVP matrix.
	glm::mat4 MVP = Projection * View * Model;
	

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(VAOs[0]);
	glBindTexture(GL_TEXTURE_2D, textures[TEX_4]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	

	// Draw the cards
	for (int i = 0; i < 52; i++)
	{
		deck[i]->drawCard();
	}

	std::cout << "Display stuff" << std::endl;
	glutSwapBuffers();
}

void key(unsigned char key, int x, int y)
{
	if (tolower(key) == 'r')
	{
		
	}

	if (tolower(key) == 'q')
	{
		exit(0);
	}
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutInitWindowPosition((1920 - 1024) / 2, (768 / 1080) / 2);
	glutInitContextVersion(4,0);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("Card Game Simulation");

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err)
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutMainLoop();

	return 0;

}