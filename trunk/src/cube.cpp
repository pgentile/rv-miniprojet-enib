#include "cube.h"
#include <GL/glut.h>

Cube::Cube(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
}

void Cube::animate(int)
{
	_angle += 3.0;
	if (_angle > 360.0) {
		_angle -= 360.0;
	}
}

void Cube::render(void)
{
	glTranslatef(_x, _y, _z);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glutWireCube(1.0);
}

void Cube::init(void)
{
	_angle = 0.0;
}
