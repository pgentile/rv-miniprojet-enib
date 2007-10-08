#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "scene-composite.h"

class Transformation: public SceneComposite
{

public:

	virtual void render(void);

protected:

	virtual void _transform(void) = 0;

};

#endif
