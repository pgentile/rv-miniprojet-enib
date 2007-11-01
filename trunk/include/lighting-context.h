#ifndef LIGHTNING_CONTEXT_H
#define LIGHTNING_CONTEXT_H

#include "context.h"
#include <vector>
#include <GL/glut.h>

using namespace std;

/**
 * Contexte d'affichage des lumières
 */
class LightingContext: public Context
{

public:

	LightingContext(void);

	LightingContext(GLenum light);

	LightingContext(int number, GLenum* lights);

	void start(void);

	void stop(void);

private:

	vector<GLenum> _lights;

};

#endif

