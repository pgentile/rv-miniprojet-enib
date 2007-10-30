#ifndef VECTOR_H
#define VECTOR_H

#include <GL/glut.h>

/**
 * Définition d'un vecteur
 */
class Vector
{

public:

	Vector(GLfloat x = 0.0, GLfloat y = 0.0, GLfloat z = 0.0);

	Vector(GLfloat* p);

	inline GLfloat x(void) { return _x; }
	inline GLfloat y(void) { return _y; }
	inline GLfloat z(void) { return _z; }

private:

	GLfloat _x, _y, _z;

};

#endif

