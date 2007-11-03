#ifndef TEXT_PARKING_H
#define TEXT_PARKING_H

#include "element.h"
#include "textured-rectangle.h"
#include <string>

/**
 * Text
 */
class TextParking: public Element
{

public:

	TextParking(void);

protected:

	void _animate(int timerInterval);

	void _render(void);

private:

	TexturedRectangle* _boardFront;
	TexturedRectangle* _boardBack;

};

#endif

