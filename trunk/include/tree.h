#ifndef TREE_H
#define TREE_H

#include "element.h"
#include "textured-rectangle.h"

/**
 * Arbre
 */
class Tree: public Element
{

public:

	Tree(void);

protected:

	void _animate(int timerInterval);

	void _render(void);

private:

	TexturedRectangle* _board;

};

#endif

