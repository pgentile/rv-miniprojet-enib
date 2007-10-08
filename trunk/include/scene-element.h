#ifndef SCENE_ELEMENT_H
#define SCENE_ELEMENT_H

class SceneElement
{

public:

	SceneElement(void);
	
	virtual void animate(int timerInterval);
	
	virtual void render(void) = 0;
	
protected:

	virtual void _init(void);

};

#endif
