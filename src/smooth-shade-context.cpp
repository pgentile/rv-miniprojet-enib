#include "smooth-shade-context.h"
#include <GL/glut.h>

void SmoothShadeContext::start(void)
{
	glShadeModel(GL_SMOOTH);
}

void SmoothShadeContext::stop(void)
{
	glShadeModel(GL_FLAT);
}

