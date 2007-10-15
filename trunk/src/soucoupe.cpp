#include "soucoupe.h"
#include "png-loader.h"
#include <GL/glut.h>

extern void _drawUFO();

void Soucoupe::animate(int timerInterval)
{
	_angle += 2.0;
	if (_angle > 360.0) {
		_angle -= 360.0;
	}
}
	
void Soucoupe::render(void)
{
	unsigned int texture = PngLoader::load("bois.png");
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glRotatef(_angle, 1.0, 0.0, 0.0);
	glRotatef(_angle, 0.0, 0.0, 1.0);
	
	glBindTexture(GL_TEXTURE_2D, texture);
	
	// Enable texture
	glEnable(GL_TEXTURE_2D);
	
	// Params alakon
	glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR ); 
	glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR );
	
	// enable texture coordinate generation
	glEnable( GL_TEXTURE_GEN_S ); 
	glEnable( GL_TEXTURE_GEN_T ); 

	// generate the texture coordinates
	static GLfloat sgenparams[] = { 0.1, 0, 0, 0 }; 
	static GLfloat tgenparams[] = { 0, 0.1, 0, 0 };
	glTexGenfv( GL_S, GL_OBJECT_PLANE, sgenparams );
	glTexGenfv( GL_T, GL_OBJECT_PLANE, tgenparams );

        glEnable(GL_DEPTH_TEST);
	_drawUFO();
	glDisable(GL_DEPTH_TEST);
	// disable texture coordinate generation
	glDisable( GL_TEXTURE_GEN_T ); 
	glDisable( GL_TEXTURE_GEN_S ); 
	
	glDisable(GL_TEXTURE_2D);
	
}
	
void Soucoupe::_init(void)
{
	_angle = 0.0;
	
	

}
