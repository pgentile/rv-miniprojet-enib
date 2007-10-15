#ifndef SOUCOUPE_H
#define SOUCOUPE_H

#include "scene-element.h"

class Soucoupe: public SceneElement
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
