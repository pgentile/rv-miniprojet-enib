#ifndef LANDING_ANIMATION_H
#define LANDING_ANIMATION_H

#include "transformation.h"
#include "vector.h"
#include "soucoupe.h"
#include <GL/glut.h>

using namespace std;

/**
 * Landing Animation
 */
class LandingAnimation: public Transformation
{

public:

	LandingAnimation(Soucoupe * soucoupe, float landingSpeed, GLfloat landingX, GLfloat landingY, GLfloat landingZ);

	virtual void apply(void);

private:

	Soucoupe * _soucoupe;
	float _landingSpeed;
	GLfloat _landingX;
	GLfloat _landingY;
	GLfloat _landingZ;
};

#endif
