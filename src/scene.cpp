#include "scene.h"
#include <GL/glut.h>

void Scene::_render(void)
{
	glLoadIdentity();
	_setupLighting();
	_setCamera();
	CompositeElement::_render();
}

