#ifndef TEXT_ENTER_H
#define TEXT_ENTER_H

#include "element.h"
#include "textured-rectangle.h"

/**
 * Text
 */
class TextEnter: public Element
{

public:

	TextEnter(void);

protected:

	void _animate(int timerInterval);

	void _render(void);

private:

	TexturedRectangle* _board;

};

#endif

