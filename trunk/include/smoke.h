#ifndef SMOKE_H
#define SMOKE_H

#include "scene-element.h"

class Smoke: public SceneElement
{

public:

	Smoke(float x, float y, float z);
	
	virtual void animate(int timerInterval);
	
	virtual void render(void);
	
private:

	float _x, _y, _z;
	float _height;
	float _scale;
	float _alpha;

};

#endif
