#ifndef CUBE_H
#define CUBE_H

#include "scene-element.h"

class Cube: public SceneElement
{

public:

	Cube(float x, float y, float z);
	
	virtual void animate(int timerInterval);
	
	virtual void render(void);

	virtual void init(void);
	
private:

	float _angle;

	float _x, _y, _z;

};

#endif
