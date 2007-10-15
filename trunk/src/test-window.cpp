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

void TestWindow::initGl(void)
{
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(5.0);
}

void TestWindow::changeProjection(int width, int height)
{
	gluPerspective(60.0, (float) width / height, 0.1, 60.0);
}

void TestWindow::clearGl()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
