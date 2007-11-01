#ifndef SOUCOUPE_LIGHT_SPHERE_H
#define SOUCOUPE_LIGHT_SPHERE_H

#include "element.h"
#include "positioned-element.h"
#include <GL/glut.h>

enum sphereColor {
	COLOR_RED,
	COLOR_WHITE
};

class SoucoupeLightSphere : public Element, public PositionedElement
{

public:

	SoucoupeLightSphere(GLenum lightNumber);

protected:
	
	virtual void _animate(int timerInterval);
	
	void _setColor();
	void _setLights();
	virtual void _render(void);
	
private:

	int _color;
	int _colorCounter;
	GLenum _lightNumber;
	GLfloat _angle;

};

#endif
