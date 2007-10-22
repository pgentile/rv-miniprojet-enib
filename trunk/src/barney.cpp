#include "barney.h"
#include "png-loader.h"
#include <GL/glut.h>

#include <iostream>

void Barney::animate(int timerInterval)
{
	_angle += 2.0;
	if (_angle > 360.0) {
		_angle -= 360.0;
	}
}

void Barney::render(void)
{
	unsigned int texture = PngLoader::load("barney.png");

	glRotatef(_angle, 0.0, 1.0, 0.0);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.9);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_POLYGON);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	
	glDisable(GL_ALPHA_TEST);
	glDisable(GL_DEPTH_TEST);
}

void Barney::init(void)
{
	_angle = 0.0;
	std::cout << "barney" << std::endl;
}
