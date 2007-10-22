#ifndef AVANT_PLAN_H
#define AVANT_PLAN_H

#include "scene-element.h"

class AvantPlan: public SceneElement
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
