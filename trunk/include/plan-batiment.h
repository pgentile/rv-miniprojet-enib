#ifndef PLAN_BATIMENT_H
#define PLAN_BATIMENT_H

#include "scene-element.h"

class PlanBatiment: public SceneElement
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
