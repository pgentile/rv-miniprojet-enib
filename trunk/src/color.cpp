#include "color.h"

Color::Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	_r = r;
	_g = g;
	_b = b;
	_a = a;
}

Color::Color(GLfloat* p)
{
	_r = p[0];
	_g = p[1];
	_b = p[2];
	_a = p[3];
}

