#ifndef POSITIONED_ELEMENT_H
#define POSITIONED_ELEMENT_H

#include <GL/glut.h>

class PositionedElement
{

public:

	PositionedElement(void);

	inline GLfloat x(void) { return _x; }
	inline GLfloat y(void) { return _y; }
	inline GLfloat z(void) { return _z; }

	inline void setX(GLfloat x) { _x = x; }
	inline void setY(GLfloat y) { _y = y; }
	inline void setZ(GLfloat z) { _z = z; }

private:

	GLfloat _x, _y, _z;

};

#endif

