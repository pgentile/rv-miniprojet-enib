#ifndef SIZE_H
#define SIZE_H

#include <GL/glut.h>

/**
 * Définition d'une taille d'un objet 3D
 */
class Size
{

public:

	Size(GLfloat width = 0.0, GLfloat height = 0.0, GLfloat depth = 0.0);

	Size(GLfloat* p);

	inline GLfloat width(void) { return _width; }
	inline GLfloat height(void) { return _height; }
	inline GLfloat depth(void) { return _depth; }

private:

	GLfloat _width, _height, _depth;

};

#endif

