#include "tree.h"
#include "depth-test-context.h"
#include "alpha-test-context.h"
#include <GL/glut.h>

Tree::Tree(void)
{
	addContext(new DepthTestContext());
	_board = new TexturedRectangle("textures/tree.png", 2.0, 4.0);
	_board->addContext(new AlphaTestContext(GL_GREATER, 0.10));
}

void Tree::_animate(int timerInterval)
{
	_board->animate(timerInterval);
}

void Tree::_render(void)
{
	_board->render();
	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	_board->render();
	glPopMatrix();
}

