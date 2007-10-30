#include "window.h"
#include <GL/glut.h>

void _w_onKeyPress(unsigned char key, int x, int y);
void _w_onSpecialKeyPress(int key, int x, int y);
void _w_onTick(int value);
void _w_display(void);
void _w_reshape(int width, int height);

Window* _w_window = (Window*) 0;

Window::Window(void)
{
	setPosition(0, 0);
	setSize(500, 300);
	setTitle("<Titre non defini>");
	setRefreshRate(50);
}

void Window::setPosition(int x, int y)
{
	_position.x = x;
	_position.y = y;
}

void Window::setSize(int width, int height)
{
	_size.width = width;
	_size.height = height;
}

void Window::setTitle(string title)
{
	_title = title;
}

string Window::getTitle(void)
{
	return _title;
}

void Window::setScene(Scene* scene)
{
	_scene = scene;
}

Scene* Window::getScene(void)
{
	return _scene;
}

void Window::setRefreshRate(unsigned int rate)
{
	_refreshRate = rate;
}

unsigned int Window::getRefreshRate(void)
{
	return _refreshRate;
}

unsigned int Window::getTimerInterval(void)
{
	return (unsigned int) (1000.0 / _refreshRate);
}

void Window::onKeyPress(unsigned char, int, int)
{
	// Ne rien faire
}

void Window::onSpecialKeyPress(int, int, int)
{
	// Ne rien faire
}

void Window::onTick(int timerInterval)
{
	if (_scene != (Scene*) 0) {
		_scene->animate(timerInterval);
	}
}

void Window::display(void)
{
	if (_scene != (Scene*) 0) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		_scene->render();
		glutSwapBuffers();
	}
}

void Window::create(int argc, char** argv, Window& window)
{
	_w_window = &window;
	// Initialiser GLUT & OpenGL
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);
	// Creer la fenetre
	glutInitWindowPosition(window._position.x, window._position.y);
	glutInitWindowSize(window._size.width, window._size.height);
	glutCreateWindow(window.getTitle().c_str());
	// Initialiser les evenements GLUT
	glutDisplayFunc(_w_display);
	glutReshapeFunc(_w_reshape);
	glutKeyboardFunc(_w_onKeyPress);
	glutSpecialFunc(_w_onSpecialKeyPress);
	glutTimerFunc(_w_window->getTimerInterval(), _w_onTick, 0);
}

void Window::loop(void)
{
	glutMainLoop();
}

void _w_onKeyPress(unsigned char key, int x, int y)
{
	_w_window->onKeyPress(key, x, y);
}

void _w_onSpecialKeyPress(int key, int x, int y)
{
	_w_window->onSpecialKeyPress(key, x, y);
}

void _w_onTick(int value)
{
	int timerInterval = _w_window->getTimerInterval();
	_w_window->onTick(timerInterval);
	glutPostRedisplay();
	glutTimerFunc(timerInterval, _w_onTick, value);
}

void _w_display(void)
{
	glMatrixMode(GL_MODELVIEW);
	_w_window->display();
}

void _w_reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	_w_window->changeProjection(width, height);
	glMatrixMode(GL_MODELVIEW);
}

