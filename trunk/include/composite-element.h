#ifndef COMPOSITE_ELEMENT_H
#define COMPOSITE_ELEMENT_H

#include "element.h"
#include <vector>

using namespace std;

/**
 * Elément composé d'autres éléments
 */
class CompositeElement: public Element
{

public:

	void addChild(Element* element);

protected:

	virtual void _animate(int timerInterval);

	virtual void _render(void);

private:

	vector<Element*> _elements;

};

#endif

