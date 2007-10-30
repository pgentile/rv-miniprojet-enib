#ifndef TEXTURED_RECTANGLE_H
#define TEXTURED_RECTANGLE_H

#include "element.h"
#include "size.h"
#include <string>
#include <GL/glut.h>

using namespace std;

/**
 * Elément composé d'autres éléments
 */
class TexturedRectangle: public Element
{

public:

	TexturedRectangle(string texturePath, Size size);

	TexturedRectangle(string texturePath, GLfloat width, GLfloat height);

protected:

	virtual void _preRender(void);

	virtual void _render(void);

	virtual void _postRender(void);

private:

	unsigned int _texture;

	Size _size;

};

#endif

