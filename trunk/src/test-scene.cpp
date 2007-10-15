#include "test-scene.h"
#include <GL/glut.h>

void TestScene::_setCamera(void)
{
	gluLookAt(2.5, 2.5, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
