#include "scene-composite.h"

using namespace std;

void SceneComposite::animate(int timerInterval)
{
	for (vector<SceneElement>::iterator i = _children.begin(); i != _children.end(); ++i) {
		(*i).animate(timerInterval);
	}
}

void SceneComposite::render(void)
{
	for (vector<SceneElement>::iterator i = _children.begin(); i != _children.end(); ++i) {
		(*i).render();
	}
}

void SceneComposite::addChild(SceneElement& element)
{
	_children.push_back(element);
}

vector<SceneElement> SceneComposite::getChildren(void)
{
	return _children;
}
