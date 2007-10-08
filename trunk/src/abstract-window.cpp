#include "abstract-window.h"

AbstractWindow::AbstractWindow(void)
{
}

AbstractWindow::~AbstractWindow(void)
{
}

void AbstractWindow::setPosition(int x, int y)
{
	_position.x = x;
	_position.y = y;
}

void AbstractWindow::setSize(int width, int height)
{
	_size.width = width;
	_size.height = height;
}

void AbstractWindow::setTitle(const char * title)
{
	_title = title;
}

void AbstractWindow::init(void)
{
}

void AbstractWindow::loop(void)
{
}

void AbstractWindow::_handleKey(unsigned char key, int x, int y)
{
}

void AbstractWindow::_handleSpecialKey(int key, int x, int y)
{
}

