#ifndef SMOKE_H
#define SMOKE_H

#include "element.h"
#include "positioned-element.h"
#include <GL/glut.h>

class Smoke: public Element, public PositionedElement
{

public:

	Smoke(void);

	inline void setScaleWidth(GLfloat width) { _scaleWidth = width; };
	inline void setScaleHeight(GLfloat height) { _scaleHeight = height; };

	inline void setAlpha(GLfloat alpha) { _alpha = alpha; }

protected:

	void _animate(int timerInterval);

	void _preRender(void);

	void _render(void);

	void _postRender(void);

private:

	unsigned int _texture;

	GLfloat _scaleWidth, _scaleHeight;

	GLfloat _alpha;

};

#endif

