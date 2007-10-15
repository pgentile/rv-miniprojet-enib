#include "barney.h"
#include "png-loader.h"
#include <GL/glut.h>

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
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
	
void Barney::_init(void)
{
	_angle = 0.0;
}
