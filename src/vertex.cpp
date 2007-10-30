#include "vertex.h"

Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z)
{
	_x = x;
	_y = y;
	_z = z;
}

Vertex::Vertex(GLfloat* p)
{
	_x = p[0];
	_y = p[1];
	_z = p[2];
}

