#include "window.h"
#include "scene.h"
#include "textured-rectangle.h"
#include "translation.h"
#include "rotation.h"
#include "scale.h"
#include "depth-test-context.h"
#include "alpha-test-context.h"
#include "tree.h"
#include "soucoupe.h"
#include "smoke-generator.h"
#include "positioned-element.h"
#include "element.h"
#include <GL/glut.h>

#define ESC_KEY 27

using namespace std;


/**
 * Fenêtre paramétrée
 */
class EnibWindow: public Window
{

public:

	virtual void onKeyPress(unsigned char key, int x, int y)
	{
		switch (key) {

		case ESC_KEY:
			exit(0);
			break;

		}
	}

	virtual void changeProjection(int width, int height)
	{
		gluPerspective(60.0, (float) width / height, 0.1, 70.0);
	}

};


/**
 * Scène paramétrée
 */
class EnibScene: public Scene
{

protected:

	virtual void _setCamera(void)
	{
		gluLookAt(0.0, 0.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	}

};


class Sphere: public Element, public PositionedElement
{

protected:

	virtual void _animate(int)
	{
		setX(x() + 0.007);
	}

	virtual void _render(void)
	{
		glTranslatef(x(), y(), z());
		glColor3f(1.0, 0.0, 0.0);
		glutWireSphere(0.5, 10, 10);
	}

};


/**
 * Main
 */
int main(int argc, char** argv)
{
	EnibWindow window;
	EnibScene scene;

	window.setScene(&scene);
	window.setTitle("ENIB Attack");
	Window::create(argc, argv, window);

	// Ciel de l'ENIB
	TexturedRectangle sky("textures/sky.png", 33.0 * 4, 33.0 * 3);
	sky.addTransformation(new Translation(0.0, 0.0, -50.0));
	sky.addContext(new DepthTestContext());
	scene.addChild(&sky);

	// Bâtiment de l'ENIB
	TexturedRectangle enib("textures/batimentEnib.png", 6.0 * 5, 6.0 * 3);
	enib.addTransformation(new Translation(0.0, -6.0, 0.0));
	enib.addContext(new AlphaTestContext(GL_GREATER, 0.95));
	enib.addContext(new DepthTestContext());
	scene.addChild(&enib);

	// Arbre 1
	Tree tree1;
	tree1.addTransformation(new Translation(1.5, -1.85, 5.0));
	scene.addChild(&tree1);

	// Arbre 2
	Tree tree2;
	tree2.addTransformation(new Translation(6.0, -1.65, 4.5));
	scene.addChild(&tree2);

	// Arbre 3
	Tree tree3;
	tree3.addTransformation(new Translation(8.0, -1.65, 4.0));
	scene.addChild(&tree3);

	// Soucoupe
	Soucoupe soucoupe;
	soucoupe.setX(-3.5);
	soucoupe.setY(-3.5);
	soucoupe.setZ(6.0);

	// Générateur de fumée
	SmokeGenerator smokeGenerator(&soucoupe);
	scene.addChild(&smokeGenerator);

	scene.addChild(&soucoupe);

	Window::loop();

	return 0;
}

