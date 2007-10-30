#ifndef CONTEXT_H
#define CONTEXT_H

/**
 * Contexte d'un élément
 */
class Context
{

public:

	virtual void start(void) = 0;

	virtual void stop(void) = 0;

};

#endif

