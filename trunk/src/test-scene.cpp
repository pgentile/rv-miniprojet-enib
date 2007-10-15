#include "test-scene.h"
#include <GL/glut.h>

void TestScene::_setCamera(void)
{
	gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
