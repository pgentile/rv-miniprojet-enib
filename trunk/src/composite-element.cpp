#include "composite-element.h"
#include <GL/glut.h>

void CompositeElement::addChild(Element* element)
{
	_elements.push_back(element);
}

void CompositeElement::_animate(int timerInterval)
{
	for (vector<Element*>::iterator i = _elements.begin(); i != _elements.end(); ++i) {
		(*i)->animate(timerInterval);
	}
}

void CompositeElement::_render(void)
{
	glPushMatrix();
	for (vector<Element*>::iterator i = _elements.begin(); i != _elements.end(); ++i) {
		(*i)->render();
	}
	glPopMatrix();
}

