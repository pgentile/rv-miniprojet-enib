#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

/**
 * Transformation
 */
class Transformation
{

public:

	virtual void animate(int timerInterval);

	virtual void apply(void) = 0;

};

#endif

