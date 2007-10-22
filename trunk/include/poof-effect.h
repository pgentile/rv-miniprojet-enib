#ifndef POOF_EFFECT_H
#define POOF_EFFECT_H

#include "scene-composite.h"

using namespace std;

class PoofEffect: public SceneComposite
{

public:
	
	virtual void animate(int timerInterval);

	virtual void render(void);

	virtual void init(void);

};

#endif
