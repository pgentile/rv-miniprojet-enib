#include "scene.h"
#include <GL/glut.h>

void Scene::render(void)
{
	glLoadIdentity();
	_setCamera();
	SceneComposite::render();
	glutSwapBuffers();
}
