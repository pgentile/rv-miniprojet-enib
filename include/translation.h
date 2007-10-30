#ifndef TRANSLATION_H
#define TRANSLATION_H

#include "transformation.h"
#include "vector.h"
#include <GL/glut.h>

using namespace std;

/**
 * Translation
 */
class Translation: public Transformation
{

public:

	Translation(Vector vector);

	Translation(GLfloat x = 0.0, GLfloat y = 0.0, GLfloat z = 0.0);

	virtual void apply(void);

private:

	Vector _vector;

};

#endif

