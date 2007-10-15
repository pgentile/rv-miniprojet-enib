#ifndef TEST_WINDOW_H
#define TEST_WINDOW_H

#include "window.h"

class TestWindow: public Window
{

public:

	virtual void onKeyPress(unsigned char key, int x, int y);

	virtual void initGl(void);

	virtual void changeProjection(int width, int height);
	
	virtual void clearGl();

private:

	float _angle;

};

#endif
