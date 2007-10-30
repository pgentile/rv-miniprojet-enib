#include "composite-element.h"
#include <GL/glut.h>

void CompositeElement::_animate(int timerInterval)
{
	for (vector<Element*>::iterator i = _elements.begin(); i != _elements.end(); ++i) {
		(*i)->animate(timerInterval);
	}
}

void CompositeElement::_render(void)
{
	for (vector<Element*>::iterator i = _elements.begin(); i != _elements.end(); ++i) {
		glPushMatrix();
		(*i)->render();
		glPopMatrix();
	}
}

