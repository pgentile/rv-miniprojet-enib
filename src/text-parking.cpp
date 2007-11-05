#include "text-parking.h"
#include "alpha-test-context.h"
#include "translation.h"
#include "scale.h"
#include <GL/glut.h>

TextParking::TextParking(void)
{
	// Texte parking devant Enib
	_boardFront = new TexturedRectangle("parking","textures/ParkingEnib.png", 1.0 * 5, 1.0 * 3);
	_boardFront->addContext(new AlphaTestContext(GL_GREATER, 0.2));
	_boardFront->addTransformation(new Translation(10.5, -5.5, 0.0));
  	_boardFront->addTransformation(new Scale(0.8, 0.8, 0.8));
	// Texte parking derriere Enib
	_boardBack = new TexturedRectangle("parking2","textures/ParkingEnib2.png", 1.0 * 5, 1.0 * 3);
	_boardBack->addContext(new AlphaTestContext(GL_GREATER, 0.2));
	_boardBack->addTransformation(new Translation(-12.0, -2.0, 0.0));
	_boardBack->addTransformation(new Scale(0.8, 0.8, 0.8));

	setVisible(false);
}

void TextParking::_animate(int timerInterval)
{
	_boardFront->animate(timerInterval);
	_boardBack->animate(timerInterval);
}

void TextParking::_render(void)
{
	_boardFront->render();
	_boardBack->render();
}
