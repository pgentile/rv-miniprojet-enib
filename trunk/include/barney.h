#ifndef BARNEY_H
#define BARNEY_H

#include "scene-element.h"

class Barney: public SceneElement
{

public:
	
	virtual void animate(int timerInterval);
	
	virtual void render(void);
	
protected:

	virtual void _init(void);
	
private:

	float _angle;

};

#endif
