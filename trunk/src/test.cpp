#include "test-window.h"
#include "test-scene.h"
#include "smoke-generator.h"
#include "scene-element.h"
#include "positioned-element.h"
#include "smoke-generator.h"
#include "barney.h"
#include <GL/glut.h>

class Sphere: public SceneElement, public PositionedElement
{

public:

	void animate(int)
	{
		//setX(getX() + 0.01);
		//setY(getY() + 0.007);
	}

	void render(void)
	{
		glTranslatef(getX(), getY(), getZ());
		glColor3f(1.0, 1.0, 0.0);
		glutSolidSphere(1.0, 30, 30);
	}

	void init(void)
	{
		//setX(-5.0);
		setY(-4.0);
		setZ(1.0);
	}

};

int main(int argc, char** argv)
{
	TestWindow window;
	TestScene scene;
	Sphere sphere;
	SmokeGenerator smokeGenerator(&sphere);
	Barney barney;
	
	scene.addChild(&smokeGenerator);
	scene.addChild(&barney);
	scene.addChild(&sphere);

	scene.init();
	window.setScene(&scene);
	Window::create(argc, argv, window);

	return 0;
}

