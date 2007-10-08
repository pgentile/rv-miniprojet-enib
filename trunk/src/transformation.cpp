#include "transformation.h"
#include <GL/glut.h>

void Transformation::render(void)
{
	glPushMatrix();
	_transform();
	SceneComposite::render();
	glPopMatrix();
}