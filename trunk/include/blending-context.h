#ifndef BLENDING_CONTEXT_H
#define BLENDING_CONTEXT_H

#include "context.h"
#include <GL/glut.h>

/**
 * Contexte de fusion des couleurs
 */
class BlendingContext: public Context
{

public:

	BlendingContext(GLenum srcFactor, GLenum destFactor);

	void start(void);

	void stop(void);

private:

	GLenum _srcFactor, _destFactor;

};

#endif

