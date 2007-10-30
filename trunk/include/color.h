#ifndef COLOR_H
#define COLOR_H

#include <GL/glut.h>

/**
 * Définition d'une couleur
 */
class Color
{

public:

	Color(GLfloat r = 1.0, GLfloat g = 1.0, GLfloat b = 1.0, GLfloat a = 1.0);

	Color(GLfloat* p);

	inline GLfloat r(void) { return _r; }
	inline GLfloat g(void) { return _g; }
	inline GLfloat b(void) { return _b; }
	inline GLfloat a(void) { return _a; }

private:

	GLfloat _r, _g, _b, _a;

};

#endif

