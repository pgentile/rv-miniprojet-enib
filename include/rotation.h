#ifndef ROTATION_H
#define ROTATION_H

#include "transformation.h"
#include "vector.h"
#include <GL/glut.h>

using namespace std;

/**
 * Rotation
 */
class Rotation: public Transformation
{

public:

	Rotation(GLfloat angle, Vector vector);

	Rotation(GLfloat angle, GLfloat x = 0.0, GLfloat y = 0.0, GLfloat z = 0.0);

	virtual void apply(void);

private:

	Vector _vector;

	GLfloat _angle;

};

#endif

