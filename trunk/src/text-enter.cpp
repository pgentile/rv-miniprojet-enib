#include "text-enter.h"
#include "alpha-test-context.h"
#include <GL/glut.h>

TextEnter::TextEnter(void)
{
	// Texte Entree Enib
	_board = new TexturedRectangle("textures/EntreeEnib.png", 1.0 * 5, 1.0 * 3);
	_board->addContext(new AlphaTestContext(GL_GREATER, 0.2));

	setVisible(false);
}

void TextEnter::_animate(int timerInterval)
{
	_board->animate(timerInterval);
}

void TextEnter::_render(void)
{
	_board->render();
}
