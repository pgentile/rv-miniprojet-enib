#include "window.h"
#include <GL/glut.h>

void _w_onKeyPress(unsigned char key, int x, int y);
void _w_onSpecialKeyPress(int key, int x, int y);
void _w_display(void);
void _w_reshape(int width, int height);

Window* _w_window = (Window*) 0;

Window::Window(void)
{
	setPosition(0, 0);
	setSize(500, 300);
	setTitle("<Titre non defini>");
}

Window::~Window(void)
{
}

void Window::setPosition(int x, int y)
{
	_position.x = x;
	_position.y = y;
}

Position2D Window::getPosition()
{
	return _position;
}

void Window::setSize(int width, int height)
{
	_size.width = width;
	_size.height = height;
}

Size2D Window::getSize(void)
{
	return _size;
}

void Window::setTitle(string title)
{
	_title = title;
}

string Window::getTitle(void)
{
	return _title;
}

void Window::create(int argc, char** argv, Window& window)
{
	_w_window = &window;
	// Initialiser OpenGL & GLUT
	glutInit(&argc, argv);
	window.initGl();
	// Creer la fenetre
	Position2D position = window.getPosition();
	glutInitWindowPosition(position.x, position.y);
	Size2D size = window.getSize();
	glutInitWindowSize(size.width, size.height);
	glutCreateWindow(window.getTitle().data());
	// Initialiser les evenements GLUT
	glutDisplayFunc(_w_display);
	glutReshapeFunc(_w_reshape);
	glutKeyboardFunc(_w_onKeyPress);
	glutSpecialFunc(_w_onSpecialKeyPress);
	// Boucle d'evenements
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

void _w_display(void)
{
	glMatrixMode(GL_MODELVIEW);
	_w_window->display();
}

void _w_reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	_w_window->changeProjection(width, height);
	glMatrixMode(GL_MODELVIEW);
}
