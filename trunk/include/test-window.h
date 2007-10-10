#ifndef TEST_WINDOW_H
#define TEST_WINDOW_H

#include "window.h"

class TestWindow: public Window
{

public:

	TestWindow(void);

	virtual void onKeyPress(unsigned char key, int x, int y);

	virtual void onTick(int timerInterval);

	virtual void initGl(void);

	virtual void changeProjection(int width, int height);

	virtual void display(void);

private:

	float _angle;

};

#endif
