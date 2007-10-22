#ifndef ARRIERE_PLAN_H
#define ARRIERE_PLAN_H

#include "scene-element.h"

class ArrierePlan: public SceneElement
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
