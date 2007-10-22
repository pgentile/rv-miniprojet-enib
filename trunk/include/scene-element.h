#ifndef SCENE_ELEMENT_H
#define SCENE_ELEMENT_H

class SceneElement
{

public:

	SceneElement(void);
	
	virtual void animate(int timerInterval) = 0;
	
	virtual void render(void) = 0;

	virtual void init(void);

};

#endif
