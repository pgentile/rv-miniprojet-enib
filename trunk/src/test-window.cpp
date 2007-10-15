#include "test-window.h"
#include <GL/glut.h>

void TestWindow::onKeyPress(unsigned char key, int, int)
{
	switch (key) {

	case 'q':
		exit(0);
		break;

	}
}

void TestWindow::changeProjection(int width, int height)
{
	gluPerspective(60.0, (float) width / height, 0.1, 60.0);
}
