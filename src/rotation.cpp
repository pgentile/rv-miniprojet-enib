#include "rotation.h"

Rotation::Rotation(GLfloat angle, Vector vector)
{
	_angle = angle;
	_vector = vector;
}

Rotation::Rotation(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
	_angle = angle;
	_vector = Vector(x, y, z);
}

void Rotation::apply(void)
{
	glRotatef(_angle, _vector.x(), _vector.y(), _vector.z());
}

