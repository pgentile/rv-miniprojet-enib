#ifndef POOF_H
#define POOF_H

#include "scene-element.h"

class Poof: public SceneElement
{

public:

	Poof(void);
	
	Poof(float angle);
	
	virtual void animate(int timerInterval);
	
	virtual void render(void);
	
	virtual void init(void);
	
private:

	float _angle;
	float _height;
	float _scale;
	float _alpha;

};

#endif
