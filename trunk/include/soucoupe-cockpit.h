#ifndef SOUCOUPE_COCKPIT_H
#define SOUCOUPE_COCKPIT_H

#include "element.h"
#include "positioned-element.h"
#include <GL/glut.h>

class SoucoupeCockpit: public Element, public PositionedElement
{

public:

	SoucoupeCockpit(void);

protected:
	
	virtual void _animate(int timerInterval);
	
	virtual void _render(void);
	
private:

	GLfloat _angle;

};

#endif
