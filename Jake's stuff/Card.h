
#ifndef CARD_H
#define CARD_H

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>


extern float pixelToWindow(float, char);

class Card
{
public:
	char suit;
	int value;
	GLfloat vertices[96];
	GLfloat tex_coords[48];
	GLuint card_vao[1];
	GLuint card_buffer[1];

	Card(char, int, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void setVertices(GLfloat, GLfloat, GLfloat);
	void setTexCoords(GLfloat, GLfloat, GLfloat, GLfloat);
	float pixelToTex(float, char);
	void initializeCard();
	void drawCard();
};

#endif