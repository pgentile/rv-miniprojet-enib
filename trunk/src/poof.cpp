#include "poof.h"
#include "png-loader.h"
#include <GL/glut.h>

Poof::Poof(void)
{
	_angle = 0.0;
	_height = 0.0;
	_scale = 0.1;
	_alpha = 1.0;
}

Poof::Poof(float angle)
{
	_angle = angle;
	_height = 0.0;
	_scale = 0.1;
	_alpha = 1.0;
}

void Poof::animate(int)
{
	_height += 0.005;
	_scale += 0.005;
	if (_alpha > 0.0) {
		_alpha -= 0.001;
	}
}

void Poof::render(void)
{
	unsigned int texture = PngLoader::load("poof.png");
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glRotatef(_angle, 0.0, 0.0, 1.0);
	glTranslatef(0.0, _height, 0.0);
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

void Poof::init(void)
{
}
