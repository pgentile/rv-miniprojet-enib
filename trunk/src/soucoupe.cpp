#include "soucoupe.h"
#include "png-loader.h"
#include "translation.h"
#include "rotation.h"
#include "lighting-context.h"
#include "depth-test-context.h"
#include "soucoupe-light-sphere.h"
#include "soucoupe-cockpit.h"
#include <GL/glut.h>

extern void _drawUFO();

GLenum lightNumbers[] = {GL_LIGHT0,GL_LIGHT1,GL_LIGHT2,GL_LIGHT3,GL_LIGHT4,GL_LIGHT5,GL_LIGHT6,GL_LIGHT7};
int nbLights = 0;
GLenum getLightNumber()
{
	nbLights++;
	if(nbLights > 8) nbLights = 0;
	return lightNumbers[nbLights-1];
}

Soucoupe::Soucoupe()
{
	
	_angle = 0.0;
	
	// Cockpit de la soucoupe
	SoucoupeCockpit* cockpit = new SoucoupeCockpit;
	cockpit->addTransformation(new Translation(0.0,2.7,0.0));
	cockpit->addContext(new LightingContext());
	cockpit->addContext(new DepthTestContext());
	
	// Boules de Lumière de la Soucoupe                              
	SoucoupeLightSphere* sphere1 = new SoucoupeLightSphere(getLightNumber());
	SoucoupeLightSphere* sphere2 = new SoucoupeLightSphere(getLightNumber());
	SoucoupeLightSphere* sphere3 = new SoucoupeLightSphere(getLightNumber());
	SoucoupeLightSphere* sphere4 = new SoucoupeLightSphere(getLightNumber());
	
	
	sphere1->addContext(new DepthTestContext());
	sphere1->addContext(new LightingContext());
	sphere2->addContext(new DepthTestContext());
	sphere2->addContext(new LightingContext());
	sphere3->addContext(new DepthTestContext());
	sphere3->addContext(new LightingContext());
	sphere4->addContext(new DepthTestContext());
	sphere4->addContext(new LightingContext());

	
	
	sphere1->addTransformation(new Translation(0.0, 1.2, -4.0));
	sphere2->addTransformation(new Rotation(90.0, 0.0, 1.0, 0.0));
	sphere2->addTransformation(new Translation(0.0, 1.2, -4.0));
	sphere3->addTransformation(new Rotation(180.0, 0.0, 1.0, 0.0));
	sphere3->addTransformation(new Translation(0.0, 1.2, -4.0));
	sphere4->addTransformation(new Rotation(270.0, 0.0, 1.0, 0.0));
	sphere4->addTransformation(new Translation(0.0, 1.2, -4.0));

	            
	addChild(cockpit);
	addChild(sphere1);
	addChild(sphere2);
	addChild(sphere3);
	addChild(sphere4);
	
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
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
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

