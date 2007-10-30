#include "size.h"

Size::Size(GLfloat width, GLfloat height, GLfloat depth)
{
	_width = width;
	_height = height;
	_depth = depth;
}

Size::Size(GLfloat* p)
{
	_width = p[0];
	_height = p[1];
	_depth = p[2];
}

