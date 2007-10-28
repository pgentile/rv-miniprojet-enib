#include "smoke.h"
#include "png-loader.h"
#include <GL/glut.h>

Smoke::Smoke(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
	_height = 0.0;
	_scale = 0.1;
	_alpha = 1.0;
}

void Smoke::animate(int)
{
	_height += 0.018;
	_scale += 0.005;
	if (_alpha > 0.0) {
		_alpha -= 0.001;
	}
}

void Smoke::render(void)
{
	unsigned int texture = PngLoader::load("poof.png");
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTranslatef(_x, _y + _height, _z);
	glScalef(_scale, _scale, 1.0);

	glBegin(GL_POLYGON);
	glColor4f(1.0, 1.0, 1.0, _alpha);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

