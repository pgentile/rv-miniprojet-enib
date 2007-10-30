#ifndef ALPHA_TEST_CONTEXT_H
#define ALPHA_TEST_CONTEXT_H

#include "context.h"
#include <GL/glut.h>

/**
 * Contexte de test de canal alpha
 */
class AlphaTestContext: public Context
{

public:

	AlphaTestContext(GLenum func, GLclampf ref);

	void start(void);

	void stop(void);

private:

	GLenum _func;

	GLclampf _ref;

};

#endif

