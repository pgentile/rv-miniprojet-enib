#include "avant-plan.h"
#include "png-loader.h"
#include <GL/glut.h>

void AvantPlan::animate(int timerInterval)
{
	// Rien
}

void AvantPlan::render(void)
{
	unsigned int texture = PngLoader::load("transparent.png");

	
	
	
	//glTranslatef(0.0,0.6,0.0);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);

	
	glBindTexture(GL_TEXTURE_2D, texture);
	
	// AvantPlan
	glEnable(GL_TEXTURE_2D);
	
	
	
	glBegin(GL_POLYGON);
	
		/*
		glTexCoord2f(0.0, 1.0); glVertex3f(-6.0, 5, 3.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(6.0, 5, 3.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(6.0, -5, 3.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(-6.0, -5, 3.0);
		*/
		
		glTexCoord3f(0, 1.0, 6.5); glVertex3f(-5.0, -1.0, 1.0);
		glTexCoord3f(1.0, 1.0, 6.5); glVertex3f(5.0, -1.0, 1.0);
		glTexCoord3f(1.0, 0.0, 6.5); glVertex3f(5.0, -1.0, 6.5);
		glTexCoord3f(0.0, 0.0, 6.5); glVertex3f(-5.0, -1.0, 6.5);
		
		
	glEnd();

	
	glDisable(GL_TEXTURE_2D);
	
	glDisable(GL_ALPHA_TEST);
	glDisable(GL_DEPTH_TEST);
}

void AvantPlan::_init(void)
{
	_angle = 0.0;
}
