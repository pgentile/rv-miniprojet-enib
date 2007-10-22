#include "arriere-plan.h"
#include "png-loader.h"
#include <GL/glut.h>

void ArrierePlan::animate(int timerInterval)
{
	// Rien
}

void ArrierePlan::render(void)
{
	unsigned int texture = PngLoader::load("fireSky.png");

	
	glTranslatef(0.0,0.4,0.0);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);

	// ArrierePlan

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glEnable(GL_DEPTH_TEST);
	glBegin(GL_POLYGON);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-6.0, 5, 1.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(6.0, 5, 1.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(6.0, -5, 1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-6.0, -5, 1.0);
	glEnd();
	glDisable(GL_DEPTH_TEST);


	glDisable(GL_TEXTURE_2D);
	
	glDisable(GL_ALPHA_TEST);
	glDisable(GL_DEPTH_TEST);
}

void ArrierePlan::_init(void)
{
	_angle = 0.0;
}
