#include "smoke-generator.h"
#include "blending-context.h"
#include "element.h"
#include "smoke.h"

SmokeGenerator::SmokeGenerator(PositionedElement* sourceElement, int smokeNumber)
{
	_sourceElement = sourceElement;
	_smokeNumber = smokeNumber;
	addContext(new BlendingContext(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	for (int i = 0; i < smokeNumber; ++i) {
		Smoke* smoke = new Smoke();
		smoke->setVisible(false);
		addChild(smoke);
	}
}

void SmokeGenerator::_animate(int timerInterval)
{
	static int remainingIntervals = 0;
	static int i = 0;
	if (remainingIntervals <= 0) {
		vector<Element*>& elements = getElements();
		Smoke* smoke = (Smoke*) elements[i];

		smoke->setVisible(true);
		smoke->setX(_sourceElement->x());
		smoke->setY(_sourceElement->y());
		smoke->setZ(_sourceElement->z());
		smoke->setScaleWidth(1.0);
		smoke->setScaleHeight(1.0);
		smoke->setAlpha(1.0);
		
		i = (i + 1) % _smokeNumber;
		remainingIntervals = 45;
	}
	remainingIntervals--;
	CompositeElement::_animate(timerInterval);
}

void SmokeGenerator::_render(void)
{
	CompositeElement::_render();
}

