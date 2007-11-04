#include "landing-animation.h"
#include <iostream>

LandingAnimation::LandingAnimation(Soucoupe * soucoupe, float landingSpeed, GLfloat landingX, GLfloat landingY, GLfloat landingZ)
{
	_soucoupe = soucoupe;
	_landingX = landingX;
	_landingY = landingY;
	_landingZ = landingZ;
	_landingSpeed = landingSpeed;
}

void LandingAnimation::apply(void)
{
	if( _soucoupe->y() > _landingY + 0.1 )
	{
		double xTranslation = ( _landingX - _soucoupe->x() ) * _landingSpeed;
		double yTranslation = ( _landingY - _soucoupe->y() ) * _landingSpeed;
		double zTranslation = ( _landingZ - _soucoupe->z() ) * _landingSpeed;
		
		_soucoupe->setX( _soucoupe->x() + xTranslation );
		_soucoupe->setY( _soucoupe->y() + yTranslation );
		_soucoupe->setZ( _soucoupe->z() + zTranslation );
	}
}

