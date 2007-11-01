#ifndef SCENE_H
#define SCENE_H

#include "composite-element.h"
#include <vector>

using namespace std;

/**
 * Scène
 */
class Scene: public CompositeElement
{

protected:

	virtual void _render(void);

	virtual void _setCamera(void) = 0;
	virtual void _setupLighting(void) = 0;
};

#endif

