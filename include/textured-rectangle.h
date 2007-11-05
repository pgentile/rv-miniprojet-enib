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

	TexturedRectangle(string name,string texturePath, Size size);

	TexturedRectangle(string name,string texturePath, GLfloat width, GLfloat height);

	void setTexture(string texturePath);
	string getName(void);
	
protected:

	virtual void _preRender(void);

	virtual void _render(void);

	virtual void _postRender(void);

private:

	unsigned int _texture;
	string _name;
	Size _size;

};

#endif

