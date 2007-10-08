#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include "common.h"

using namespace std;

class Window
{

public:

	Window(void);
	~Window(void);

	void setPosition(int x, int y);
	Position2D getPosition(void);

	void setSize(int width, int height);
	Size2D getSize(void);

	void setTitle(string title);
	string getTitle(void);

	virtual void onKeyPress(unsigned char key, int x, int y) = 0;
	virtual void onSpecialKeyPress(int key, int x, int y) = 0;

	virtual void initGl(void) = 0;

	virtual void changeProjection(int width, int height) = 0;

	virtual void display(void) = 0;

	static void create(int argc, char** argv, Window& window);

private:

	Position2D _position;

	Size2D _size;

	string _title;

};

#endif
