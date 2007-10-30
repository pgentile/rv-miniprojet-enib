#ifndef DEPTH_TEST_CONTEXT_H
#define DEPTH_TEST_CONTEXT_H

#include "context.h"

/**
 * Contexte de test de profondeur
 */
class DepthTestContext: public Context
{

public:

	void start(void);

	void stop(void);

};

#endif

