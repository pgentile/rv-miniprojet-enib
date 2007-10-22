#include "plan-batiment.h"
#include "png-loader.h"
#include <GL/glut.h>

void PlanBatiment::animate(int timerInterval)
{
	// Rien
}

void PlanBatiment::render(void)
{
	unsigned int texture = PngLoader::load("batimentEnib.png");

	glTranslatef(0.0,-0.6,0.0);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);

	// PlanBatiment

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_POLYGON);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-4.0, 2.0, 2.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.0, 2.0, 2.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.0, -2.0, 2.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-4.0, -2.0, 2.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	
	glDisable(GL_ALPHA_TEST);
	glDisable(GL_DEPTH_TEST);
}

void PlanBatiment::_init(void)
{
	_angle = 0.0;
}
