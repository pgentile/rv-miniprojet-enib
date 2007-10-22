#include "poof-effect.h"
#include "poof.h"
#include <GL/glut.h>

void PoofEffect::animate(int timerInterval)
{
	static int remainingIntervals = 0;
	if (remainingIntervals == 0) {
		addChild(new Poof(0.0));
		remainingIntervals = 75;
	}
	remainingIntervals--;

	SceneComposite::animate(timerInterval);
}

void PoofEffect::render(void)
{
	float scaleXY = 15.0;
	float zPos = -5.0;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glBegin(GL_POLYGON);
	glColor4f(1.0, 0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0 * scaleXY, 1.0 * scaleXY, zPos);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0 * scaleXY, 1.0 * scaleXY, zPos);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0 * scaleXY, -1.0 * scaleXY, zPos);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0 * scaleXY, -1.0 * scaleXY, zPos);
	glEnd();

	SceneComposite::render();
	
	glDisable(GL_BLEND);
}

void PoofEffect::init(void)
{

	SceneComposite::init();
}
