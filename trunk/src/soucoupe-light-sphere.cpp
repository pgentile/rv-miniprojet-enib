#include "soucoupe-light-sphere.h"
#include "png-loader.h"
#include <GL/glut.h>
#include <iostream>

SoucoupeLightSphere::SoucoupeLightSphere(GLenum lightNumber)
{
	_lightNumber = lightNumber;
	_color = COLOR_RED;
	_colorCounter = 0;
}

void SoucoupeLightSphere::_animate(int timerInterval)
{
	_colorCounter++;
	
	if(_colorCounter > 30) 
	{
		_color = !_color;
		_colorCounter = 0;
	}
}
	
void SoucoupeLightSphere::_setColor()
{
	GLfloat white[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat red[] = {1.0, 0.0, 0.0, 1.0};
	
	if( _color == COLOR_RED ) glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, red);
	else glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	
}

void SoucoupeLightSphere::_setLights()
{
	if( _color == COLOR_RED ) { 
		GLfloat ambientLight[] = { 1.0f, 0.0f, 0.0f, 0.2f };
		GLfloat diffuseLight[] = { 1.0f, 0.0f, 0.0f, 1.0f };
		GLfloat specularLight[] = { 1.0f, 0.0f, 0.0f, 1.0f };
		GLfloat position[] = { x(),  y() , z() , 1.0f };
		glLightfv(_lightNumber, GL_AMBIENT, ambientLight);
		glLightfv(_lightNumber, GL_DIFFUSE, diffuseLight);
		glLightfv(_lightNumber, GL_SPECULAR, specularLight);
		glLightfv(_lightNumber, GL_POSITION, position);
	}
	else {
		GLfloat ambientLight[] = { 1.0f, 1.0f, 1.0f, 0.6f };
		GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat position[] = { x(),  y() , z() , 1.0f };
		glLightfv(_lightNumber, GL_AMBIENT, ambientLight);
		glLightfv(_lightNumber, GL_DIFFUSE, diffuseLight);
		glLightfv(_lightNumber, GL_SPECULAR, specularLight);
		glLightfv(_lightNumber, GL_POSITION, position);

	}
	glLightf(_lightNumber,GL_CONSTANT_ATTENUATION,.1f);
	glLightf(_lightNumber,GL_LINEAR_ATTENUATION,2.0f);
	glLightf(_lightNumber,GL_QUADRATIC_ATTENUATION,10.0f);
}
void SoucoupeLightSphere::_render(void)
{
	GLfloat off[] = {0.0, 0.0, 0.0, 0.0};
	GLfloat white[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat red[] = {1.0, 0.0, 0.0, 1.0};
	GLfloat deep_blue[] = {0.1, 0.5, 0.8, 1.0};
	GLfloat shiny[] = {10.0};
	GLfloat dull[] = {0.0};
	GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	
	// Enable Light
	glEnable(_lightNumber);
	
	// Create light components
	_setLights();
	
	// Light Emission
	
	

// Assign created components to GL_LIGHT0
	

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shiny);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, red);

	
	 
	// Render Sphere
	_setColor();
	
	glutSolidSphere(0.6 , 15 , 15 );
	
	// Disable Light
	//glDisable(_lightNumber);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, off);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, off);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, off);
	
}

