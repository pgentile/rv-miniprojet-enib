#include "element.h"
#include <GL/glut.h>

Element::Element(void)
{
	_visible = true;
}

void Element::animate(int timerInterval)
{
	if (!_visible) { // Ne rien faire si caché
		return;
	}
	// Appliquer les animations des transformations
	if (_transformations.size() > 0) {
		for (vector<Transformation*>::iterator i = _transformations.begin(); i != _transformations.end(); ++i) {
			(*i)->animate(timerInterval);
		}
	}
	// Appliquer les animations de l'élément
	_animate(timerInterval);
}

void Element::render(void)
{
	if (!_visible) { // Ne rien faire si caché
		return;
	}
	int size = _transformations.size();
	if (size > 0) { // Appliquer les transformations avant de générer l'objet
		glPushMatrix();
		for (vector<Transformation*>::iterator i = _transformations.begin(); i != _transformations.end(); ++i) {
			(*i)->apply();
		}
		_startContext();
		_preRender();
		_render();
		_postRender();
		_stopContext();
		glPopMatrix();
	} else {
		_startContext();
		_preRender();
		_render();
		_postRender();
		_stopContext();
	}
}

void Element::addTransformation(Transformation* transformation)
{
	_transformations.push_back(transformation);
}

void Element::addContext(Context* context)
{
	_contexts.push_back(context);
}

void Element::_animate(int timerInterval)
{
	// NE RIEN FAIRE...
}

void Element::_preRender(void)
{
	// NE RIEN FAIRE...
}

void Element::_postRender(void)
{
	// NE RIEN FAIRE...
}

void Element::_startContext(void)
{
	if (_contexts.size() > 0) {
		for (vector<Context*>::iterator i = _contexts.begin(); i != _contexts.end(); ++i) {
			(*i)->start();
		}
	}
}

void Element::_stopContext(void)
{
	if (_contexts.size() > 0) {
		for (vector<Context*>::iterator i = _contexts.begin(); i != _contexts.end(); ++i) {
			(*i)->stop();
		}
	}
}

