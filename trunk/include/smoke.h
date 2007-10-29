#ifndef SMOKE_H
#define SMOKE_H

#include "scene-element.h"
#include "positioned-element.h"

class Smoke: public SceneElement, public PositionedElement
{

public:

	Smoke(void);
	
	virtual void animate(int timerInterval);
	
	virtual void render(void);

	void reset(float x, float y, float z);
	
private:

	float _height;
	float _scale;
	float _alpha;

};

#endif
