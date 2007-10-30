#include "vector.h"

Vector::Vector(GLfloat x, GLfloat y, GLfloat z)
{
	_x = x;
	_y = y;
	_z = z;
}

Vector::Vector(GLfloat* p)
{
	_x = p[0];
	_y = p[1];
	_z = p[2];
}

