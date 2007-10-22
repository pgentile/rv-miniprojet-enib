#ifndef TREE_H
#define TREE_H

#include "scene-element.h"

class Tree: public SceneElement
{

public:
	
	virtual void animate(int timerInterval);
	
	virtual void render(void);
	
private:

	virtual void _renderBillboard(void);

};

#endif
