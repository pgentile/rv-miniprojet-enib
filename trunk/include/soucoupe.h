#ifndef SOUCOUPE_H
#define SOUCOUPE_H

#include "element.h"
#include <GL/glut.h>

class Soucoupe: public Element
{

public:

	Soucoupe(void);

protected:
	
	virtual void _animate(int timerInterval);
	
	virtual void _render(void);
	
private:

	GLfloat _angle;

};

#endif
