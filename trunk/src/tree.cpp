#include "tree.h"
#include "png-loader.h"
#include <GL/glut.h>

#include <iostream>

void Tree::animate(int)
{
	// Ne rien faire
}

void Tree::render(void)
{
	unsigned int texture = PngLoader::load("tree.png");

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.8);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	for (int i = 0; i < 2; i++) {
		glPushMatrix();
		glRotatef((180.0 *  i) / 2, 0.0, 1.0, 0.0);
		_renderBillboard();
		glPopMatrix();
	}

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA_TEST);
	glDisable(GL_DEPTH_TEST);
}

void Tree::_renderBillboard(void)
{
	glBegin(GL_POLYGON);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
	glEnd();
}
