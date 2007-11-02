#include "soucoupe.h"
#include "png-loader.h"
#include <GL/glut.h>

extern void _drawUFO();

Soucoupe::Soucoupe()
{
	_angle = 0.0;
}

void Soucoupe::_animate(int timerInterval)
{
	_angle += 2.0;
	if (_angle > 360.0) {
		_angle -= 360.0;
	}
	
	CompositeElement::_animate(timerInterval);
}
	
void Soucoupe::_render(void)
{
	// Material Parameters
	GLfloat off[] = {0.0, 0.0, 0.0, 0.0};
	GLfloat white[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat red[] = {1.0, 0.0, 0.0, 1.0};
	GLfloat grey[] = {0.55, 0.58, 0.59, 1.0};
	GLfloat shiny[] = {100.0};
	GLfloat dull[] = {0.0};
	GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	
	// Loading Texture
	unsigned int texture = PngLoader::load("textures/metal.png");

	glTranslatef(x(), y(), z());

	glRotatef(_angle, 0.0, 1.0, 0.0);
	glRotatef(_angle, 0.0, 0.0, 1.0);
	glScalef(0.2, 0.2, 0.2);
	
	glBindTexture(GL_TEXTURE_2D, texture);
	
	// Enable texture
	glEnable(GL_TEXTURE_2D);
	
	// Params alakon
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR); 
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	
	// enable texture coordinate generation
	glEnable(GL_TEXTURE_GEN_S); 
	glEnable(GL_TEXTURE_GEN_T); 

	// generate the texture coordinates
	static GLfloat sgenparams[] = { 0.4, 0, 0, 0 }; 
	static GLfloat tgenparams[] = { 0, 0.5, 0, 0 };
	glTexGenfv(GL_S, GL_OBJECT_PLANE, sgenparams);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, tgenparams);

	// Materials
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shiny);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, off);
	
	_drawUFO();
	
	// disable texture coordinate generation
	glDisable(GL_TEXTURE_GEN_T); 
	glDisable(GL_TEXTURE_GEN_S); 
	
	glDisable(GL_TEXTURE_2D);
	
	CompositeElement::_render();
	
}

