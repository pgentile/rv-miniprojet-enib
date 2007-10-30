#ifndef SCALE_H
#define SCALE_H

#include "transformation.h"
#include "size.h"
#include <GL/glut.h>

using namespace std;

/**
 * Mise à l'échelle
 */
class Scale: public Transformation
{

public:

	Scale(Size size);

	Scale(GLfloat width = 1.0, GLfloat height = 1.0, GLfloat depth = 1.0);

	virtual void apply(void);

	static Scale uniform(GLfloat factor);

private:

	Size _size;

};

#endif

