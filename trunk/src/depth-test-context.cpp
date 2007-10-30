#include "depth-test-context.h"
#include <GL/glut.h>

void DepthTestContext::start(void)
{
	glEnable(GL_DEPTH_TEST);
}

void DepthTestContext::stop(void)
{
	glDisable(GL_DEPTH_TEST);
}

