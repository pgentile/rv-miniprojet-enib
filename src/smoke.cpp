#include "smoke.h"
#include "png-loader.h"

Smoke::Smoke(void)
{
	_texture = PngLoader::load("textures/poof.png");
	_scaleWidth = _scaleHeight = 0.0;
	_alpha = 1.0;
}

void Smoke::_animate(int timerInterval)
{
	setY(y() + 0.007);
	setScaleWidth(_scaleWidth * 1.002);
	setScaleHeight(_scaleHeight + 0.003);
	setAlpha(_alpha - 0.0007);
}

void Smoke::_preRender(void)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _texture);
}

void Smoke::_render(void)
{
	glTranslatef(x(), y(), z());
	glScalef(_scaleWidth, _scaleHeight, 1.0);
	glBegin(GL_QUADS);
	glColor4f(1.0, 1.0, 1.0, _alpha);
	glTexCoord2f(0.0, 1.0); glVertex2f(-0.5, 0.5);
	glTexCoord2f(1.0, 1.0); glVertex2f(0.5, 0.5);
	glTexCoord2f(1.0, 0.0); glVertex2f(0.5, -0.5);
	glTexCoord2f(0.0, 0.0); glVertex2f(-0.5, -0.5);
	glEnd();
}

void Smoke::_postRender(void)
{
	glDisable(GL_TEXTURE_2D);
}

