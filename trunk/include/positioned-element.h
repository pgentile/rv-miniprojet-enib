#ifndef POSITIONED_ELEMENT_H
#define POSITIONED_ELEMENT_H

class PositionedElement
{

public:
	
	PositionedElement(void);

	float getX(void);
	void setX(float x);

	float getY(void);
	void setY(float y);

	float getZ(void);
	void setZ(float z);
private:

	float _x, _y, _z;

};

#endif
