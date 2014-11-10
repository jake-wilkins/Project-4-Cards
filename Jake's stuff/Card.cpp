#include <cstdio>
#include <iostream>

#include "Card.h"
#define CARD_WIDTH 0.005

Card::Card(char suit, int value, GLfloat x, GLfloat y, GLfloat z, GLfloat tex_x, GLfloat tex_y, GLfloat tex_x2, GLfloat tex_y2)
{ 
	this->suit = suit;
	this->value = value;
	this->setVertices(x, y, z);
	this->setTexCoords(tex_x, tex_y, tex_x2, tex_y2);
}

float Card::pixelToTex(float pixel, char dimension)
{
	if (dimension == 'x')
		return (pixel / 950);
	if (dimension == 'y')
		return (pixel / 392);
}

void Card::setVertices(GLfloat x, GLfloat y, GLfloat z)
{
	for (int i = 3; i < 96; i += 4)
	{
		vertices[i] = 1.0;
	}


	// Card back
	vertices[0] = pixelToWindow(x, 'x');
	vertices[1] = pixelToWindow(y, 'y');
	vertices[2] = z;

	vertices[12] = pixelToWindow(x + 71, 'x');
	vertices[13] = pixelToWindow(y, 'y');
	vertices[14] = z;

	vertices[8] = pixelToWindow(x + 71, 'x');
	vertices[9] = pixelToWindow(y - 95, 'y');
	vertices[10] = z;

	vertices[4] = pixelToWindow(x, 'x');
	vertices[5] = pixelToWindow(y - 95, 'y');
	vertices[6] = z;

	// Card face
	vertices[16] = pixelToWindow(x, 'x');
	vertices[17] = pixelToWindow(y, 'y');
	vertices[18] = z + CARD_WIDTH;

	vertices[20] = pixelToWindow(x, 'x');
	vertices[21] = pixelToWindow(y - 95, 'y');
	vertices[22] = z + CARD_WIDTH;

	vertices[24] = pixelToWindow(x + 71, 'x');	
	vertices[25] = pixelToWindow(y - 95, 'y');
	vertices[26] = z + CARD_WIDTH;

	vertices[28] = pixelToWindow(x + 71, 'x');	
	vertices[29] = pixelToWindow(y, 'y');
	vertices[30] = z + CARD_WIDTH;

	// Card left edge
	vertices[32] = pixelToWindow(x, 'x');
	vertices[33] = pixelToWindow(y, 'y');
	vertices[34] = z;
	
	vertices[36] = pixelToWindow(x, 'x');	
	vertices[37] = pixelToWindow(y, 'y');
	vertices[38] = z + CARD_WIDTH;
	
	vertices[40] = pixelToWindow(x, 'x');	
	vertices[41] = pixelToWindow(y - 95, 'y');
	vertices[42] = z + CARD_WIDTH;

	vertices[44] = pixelToWindow(x, 'x');	
	vertices[45] = pixelToWindow(y - 95, 'y');
	vertices[46] = z;
	

	// Card right edge
	vertices[48] = pixelToWindow(x + 71, 'x');
	vertices[49] = pixelToWindow(y, 'y');
	vertices[50] = z;
	
	vertices[52] = pixelToWindow(x + 71, 'x');
	vertices[53] = pixelToWindow(y - 95, 'y');
	vertices[54] = z;
	
	vertices[56] = pixelToWindow(x + 71, 'x');
	vertices[57] = pixelToWindow(y - 95, 'y');
	vertices[58] = z + CARD_WIDTH;
	
	vertices[60] = pixelToWindow(x + 71, 'x');
	vertices[61] = pixelToWindow(y, 'y');
	vertices[62] = z + CARD_WIDTH;
	

	// Card top edge
	vertices[64] = pixelToWindow(x, 'x');
	vertices[65] = pixelToWindow(y, 'y');
	vertices[66] = z;
	
	vertices[68] = pixelToWindow(x + 71, 'x');	
	vertices[69] = pixelToWindow(y, 'y');
	vertices[70] = z;
	
	vertices[72] = pixelToWindow(x + 71, 'x');	
	vertices[73] = pixelToWindow(y, 'y');
	vertices[74] = z + CARD_WIDTH;
	
	vertices[76] = pixelToWindow(x, 'x');
	vertices[77] = pixelToWindow(y, 'y');
	vertices[78] = z + CARD_WIDTH;
	

	// Card bottom edge
	vertices[80] = pixelToWindow(x + 71, 'x');
	vertices[81] = pixelToWindow(y - 95, 'y');
	vertices[82] = z;
	
	vertices[84] = pixelToWindow(x + 71, 'x');
	vertices[85] = pixelToWindow(y - 95, 'y');
	vertices[86] = z + CARD_WIDTH;
	
	vertices[88] = pixelToWindow(x, 'x');	
	vertices[89] = pixelToWindow(y - 95, 'y');
	vertices[90] = z + CARD_WIDTH;
	
	vertices[92] = pixelToWindow(x, 'x');	
	vertices[93] = pixelToWindow(y - 95, 'y');
	vertices[94] = z;
}

void Card::setTexCoords(GLfloat start_x, GLfloat start_y, GLfloat end_x, GLfloat end_y)
{
	// Card back
	tex_coords[0] = 1;
	tex_coords[1] = 0;

	tex_coords[2] = 1;
	tex_coords[3] = 1;

	tex_coords[4] = 0;
	tex_coords[5] = 1;
	
	tex_coords[6] = 0;
	tex_coords[7] = 0;

	// Card face
	tex_coords[8] = pixelToTex(start_x, 'x');
	tex_coords[9] = pixelToTex(start_y, 'y');
	tex_coords[10] = pixelToTex(start_x, 'x');
	tex_coords[11] = pixelToTex(end_y, 'y');
	tex_coords[12] = pixelToTex(end_x, 'x');
	tex_coords[13] = pixelToTex(end_y, 'y');
	tex_coords[14] = pixelToTex(end_x, 'x');
	tex_coords[15] = pixelToTex(start_y, 'y');

	// Card left edge
	tex_coords[16] = 0;
	tex_coords[17] = 0;
	tex_coords[18] = 0;
	tex_coords[19] = 1;
	tex_coords[20] = 1;
	tex_coords[21] = 1;
	tex_coords[22] = 1;
	tex_coords[23] = 0;

	// Card right edge
	tex_coords[24] = 0;
	tex_coords[25] = 0;
	tex_coords[26] = 0;
	tex_coords[27] = 1;
	tex_coords[28] = 1;
	tex_coords[29] = 1;
	tex_coords[30] = 1;
	tex_coords[31] = 0;

	// Card top edge
	tex_coords[32] = 0;
	tex_coords[33] = 0;
	tex_coords[34] = 0;
	tex_coords[35] = 1;
	tex_coords[36] = 1;
	tex_coords[37] = 1;
	tex_coords[38] = 1;
	tex_coords[39] = 0;

	// Card bottom edge
	tex_coords[40] = 0;
	tex_coords[41] = 0;
	tex_coords[42] = 0;
	tex_coords[43] = 1;
	tex_coords[44] = 1;
	tex_coords[45] = 1;
	tex_coords[46] = 1;
	tex_coords[47] = 0;
}

void Card::initializeCard()
{
	glGenVertexArrays(1, card_vao);
	glGenBuffers(1, card_buffer);

	glBindVertexArray(card_vao[0]);
	glBindBuffer(GL_ARRAY_BUFFER, card_buffer[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(tex_coords), NULL, GL_DYNAMIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(tex_coords), tex_coords);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*) sizeof(vertices));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

}

void Card::drawCard()
{
	
	glBindVertexArray(card_vao[0]);
	glActiveTexture(GL_TEXTURE0);

	// Draw the card face
	glBindTexture(GL_TEXTURE_2D, 2);
	glDrawArrays(GL_TRIANGLE_FAN, 4, 4);

	// Draw the card back
	glBindTexture(GL_TEXTURE_2D, 1);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	
	// Draw the edges of the card
	glBindTexture(GL_TEXTURE_2D, 3);
	glDrawArrays(GL_TRIANGLE_FAN, 8, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 16, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 20, 4);


}