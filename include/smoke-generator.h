#ifndef SMOKE_GENERATOR_H
#define SMOKE_GENERATOR_H

#include "composite-element.h"
#include "positioned-element.h"

#define SMOKE_NUMBER 100

using namespace std;

class SmokeGenerator: public CompositeElement
{

public:

	SmokeGenerator(PositionedElement* sourceElement, int smokeNumber = SMOKE_NUMBER);

	inline PositionedElement* getSourceElement(void) { return _sourceElement; }

protected:

	virtual void _animate(int timerInterval);

	virtual void _render(void);
	
private:

	PositionedElement* _sourceElement;

	int _smokeNumber;

};

#endif
