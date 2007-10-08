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

void TestWindow::onSpecialKeyPress(int, int, int)
{
}

void TestWindow::initGl(void)
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(5.0);
}

void TestWindow::changeProjection(int width, int height)
{
	glLoadIdentity();
	gluPerspective(60.0, (float) width / height, 0.1, 60.0);
}

void TestWindow::display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glColor3f(1.0, 1.0, 1.0);
	glutWireCube(1.0);

	glutSwapBuffers();
}
