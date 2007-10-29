#include "smoke-generator.h"
#include "smoke.h"
#include <GL/glut.h>

SmokeGenerator::SmokeGenerator(PositionedElement* followedElement)
{
	_followedElement = followedElement;
	_smokeClouds = new Smoke[SMOKE_CLOUDS_MAX];
}

void SmokeGenerator::animate(int timerInterval)
{
	static int remainingIntervals = 0;
	static int currentCloud = 0;
	if (remainingIntervals <= 0) {
		float x = _followedElement->getX();
		float y = _followedElement->getY();
		float z = _followedElement->getZ();
		vector<SceneElement*>& children = getChildren();
		int size = children.size();
		if (size == SMOKE_CLOUDS_MAX) {
			Smoke* smoke = (Smoke*) children[currentCloud];
			smoke->reset(x, y, z);
			currentCloud++;
			if (currentCloud == SMOKE_CLOUDS_MAX) {
				currentCloud -= SMOKE_CLOUDS_MAX;
			}
		} else {
			Smoke* smoke = _smokeClouds + size;
			smoke->reset(x, y, z);
			addChild(smoke);
		}
		remainingIntervals = 100;
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

