#include <positioned-element.h>

PositionedElement::PositionedElement(void)
{
	_x = 0.0;
	_y = 0.0;
	_z = 0.0;
}

float PositionedElement::getX(void)
{
	return _x;
}

void PositionedElement::setX(float x)
{
	_x = x;
}

float PositionedElement::getY(void)
{
	return _y;
}

void PositionedElement::setY(float y)
{
	_y = y;
}

float PositionedElement::getZ(void)
{
	return _z;
}

void PositionedElement::setZ(float z)
{
	_z = z;
}

