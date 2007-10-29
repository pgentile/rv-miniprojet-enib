#include "smoke.h"
#include "png-loader.h"
#include <GL/glut.h>

Smoke::Smoke(void)
{
	reset(0.0, 0.0, 0.0);
}

void Smoke::animate(int)
{
	_height += 0.008;
	_scale += 0.002;
	if (_alpha > 0.0) {
		_alpha -= 0.0002;
	}
}

void Smoke::reset(float x, float y, float z)
{
	setX(x);
	setY(y);
	setZ(z);
	_height = 0.0;
	_scale = 0.5;
	_alpha = 1.0;
}

void Smoke::render(void)
{
	unsigned int texture = PngLoader::load("poof.png");
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTranslatef(getX(), getY() + _height, getZ());
	glScalef(_scale * 1.5, _scale, 1.0);

	glBegin(GL_POLYGON);
	glColor4f(1.0, 1.0, 1.0, _alpha);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

