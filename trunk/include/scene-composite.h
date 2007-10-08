#ifndef SCENE_COMPOSITE_H
#define SCENE_COMPOSITE_H

#include "scene-element.h"
#include <vector>

using namespace std;

class SceneComposite: public SceneElement
{

public:
	
	virtual void animate(int timerInterval);

	virtual void render(void);
	
	void addChild(SceneElement& element);
	vector<SceneElement> getChildren(void);
	
private:

	vector<SceneElement> _children;

};

#endif
