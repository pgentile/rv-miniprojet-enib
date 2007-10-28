#include "smoke-generator.h"
#include "smoke.h"
#include <GL/glut.h>

SmokeGenerator::SmokeGenerator(PositionedElement* followedElement)
{
	_followedElement = followedElement;
}

void SmokeGenerator::animate(int timerInterval)
{
	static int remainingIntervals = 0;
	if (remainingIntervals <= 0) {
		vector<SceneElement*>& children = getChildren();
		if (children.size() == 50) {
			SceneElement* smoke = children[0];
			children.erase(children.begin());
			delete smoke;
		}
		float x = _followedElement->getX();
		float y = _followedElement->getY();
		float z = _followedElement->getZ();
		Smoke* smoke = new Smoke(x, y, z);
		smoke->init();
		addChild(smoke);
		remainingIntervals = 25;
	}
	remainingIntervals--;
	SceneComposite::animate(timerInterval);
}

void SmokeGenerator::render(void)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	SceneComposite::render();
	glDisable(GL_BLEND);
}

PositionedElement* SmokeGenerator::getFollowedElement(void)
{
	return _followedElement;
}

