#include "soucoupe-cockpit.h"
#include "png-loader.h"
#include <GL/glut.h>
#include <iostream>

SoucoupeCockpit::SoucoupeCockpit()
{
}

void SoucoupeCockpit::_animate(int timerInterval)
{
	
}
	
void SoucoupeCockpit::_render(void)
{
	GLfloat off[] = {0.0, 0.0, 0.0, 0.0};
	GLfloat white[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat red[] = {1.0, 0.0, 0.0, 1.0};
	GLfloat deep_blue[] = {0.1, 0.5, 0.8, 1.0};
	GLfloat shiny[] = {10.0};
	GLfloat dull[] = {0.0};
	GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	
	

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTranslatef(x(), y(), z());
	
	// Materials
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, deep_blue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shiny);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, deep_blue);
	
	// Render Sphere
	glColor4f(0.0,0.0,0.5,0.6);
	glutSolidSphere(1.8 , 15 , 15 );

	glDisable(GL_BLEND);

	
}

