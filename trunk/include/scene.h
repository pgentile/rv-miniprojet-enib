#ifndef SCENE_H
#define SCENE_H

#include "scene-composite.h"

class Scene: public SceneComposite
{

public:

	virtual void render(void);

protected:

	virtual void _setCamera(void) = 0;

};

#endif
