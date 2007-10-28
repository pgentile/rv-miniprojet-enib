#ifndef SMOKE_GENERATOR_H
#define SMOKE_GENERATOR_H

#include "scene-composite.h"
#include "positioned-element.h"

using namespace std;

class SmokeGenerator: public SceneComposite
{

public:

	SmokeGenerator(PositionedElement* followedElement);
	
	virtual void animate(int timerInterval);

	virtual void render(void);

	PositionedElement* getFollowedElement(void);
	
private:

	PositionedElement* _followedElement;

};

#endif
