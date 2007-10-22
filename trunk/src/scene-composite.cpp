#include "scene-composite.h"
#include <GL/glut.h>

using namespace std;

void SceneComposite::animate(int timerInterval)
{
	for (vector<SceneElement*>::iterator i = _children.begin(); i != _children.end(); ++i) {
		(*i)->animate(timerInterval);
	}
}

void SceneComposite::render(void)
{
	for (vector<SceneElement*>::iterator i = _children.begin(); i != _children.end(); ++i) {
		glPushMatrix();
		(*i)->render();
		glPopMatrix();
	}
}

void SceneComposite::init(void)
{
	for (vector<SceneElement*>::iterator i = _children.begin(); i != _children.end(); ++i) {
		(*i)->init();
	}
}

void SceneComposite::addChild(SceneElement* element)
{
	_children.push_back(element);
}

vector<SceneElement*> SceneComposite::getChildren(void)
{
	return _children;
}
