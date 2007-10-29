#ifndef SMOKE_GENERATOR_H
#define SMOKE_GENERATOR_H

#include "scene-composite.h"
#include "positioned-element.h"
#include "smoke.h"

#define SMOKE_CLOUDS_MAX 30

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

	Smoke* _smokeClouds;

	

};

#endif
