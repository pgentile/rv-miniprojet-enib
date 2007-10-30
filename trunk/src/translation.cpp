#include "translation.h"

Translation::Translation(Vector vector)
{
	_vector = vector;
}

Translation::Translation(GLfloat x, GLfloat y, GLfloat z)
{
	_vector = Vector(x, y, z);
}

void Translation::apply(void)
{
	glTranslatef(_vector.x(), _vector.y(), _vector.z());
}

