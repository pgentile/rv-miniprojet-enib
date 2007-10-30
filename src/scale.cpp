#include "scale.h"
#include <GL/glut.h>

Scale::Scale(Size size)
{
	_size = size;
}

Scale::Scale(GLfloat width, GLfloat height, GLfloat depth)
{
	_size = Size(width, height, depth);
}

Scale Scale::uniform(GLfloat factor)
{
	return Scale(factor, factor, factor);
}

void Scale::apply(void)
{
	glScalef(_size.width(), _size.height(), _size.depth());
}

