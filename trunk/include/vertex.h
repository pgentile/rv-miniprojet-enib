#ifndef VERTEX_H
#define VERTEX_H

#include <GL/glut.h>

/**
 * Définition d'un vertex
 */
class Vertex
{

public:

	Vertex(GLfloat x = 0.0, GLfloat y = 0.0, GLfloat z = 0.0);

	Vertex(GLfloat* p);

	inline GLfloat x(void) { return _x; }
	inline GLfloat y(void) { return _y; }
	inline GLfloat z(void) { return _z; }

private:

	GLfloat _x, _y, _z;

};

#endif

