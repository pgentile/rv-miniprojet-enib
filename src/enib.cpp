#include "window.h"
#include "scene.h"
#include "textured-rectangle.h"
#include "translation.h"
#include "rotation.h"
#include "scale.h"
#include "depth-test-context.h"
#include "blending-context.h"
#include "lighting-context.h"
#include "alpha-test-context.h"
#include "tree.h"
#include "text-enter.h"
#include "text-parking.h"
#include "soucoupe.h"
#include "smoke-generator.h"
#include "landing-animation.h"
#include "positioned-element.h"
#include "element.h"
#include "soucoupe-light-sphere.h"
#include "soucoupe-cockpit.h"
#include <GL/glut.h>
#include <iostream>
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
		case 'o': /* Indique ou est l'entree */
			_displayEnter();
			break;
    		case 'p':  /* Indique ou sont les parkings */
			_displayParking();
			break;
		case 'z': /* Fait remonter les soucoupes */
			_ufoUp();
			break;
		case 'q': /* Fait aller les soucoupes sur la gauche */
			_ufoLeft();
		break;
		case 'd': /* Fait aller les soucoupes sur la droite */
			_ufoRight();
		break;
		case 's': /* Fait descendre les soucoupes */
			_ufoDown();
		break;
		case 'a': /* Pousse les soucoupes */
			_ufoFar();
		break;
		case 'e': /* Attire les soucoupes */
			_ufoNear();
		break;
		case ESC_KEY:
			exit(0);
			break;

		}
	}

	virtual void changeProjection(int width, int height)
	{
		gluPerspective(60.0, (float) width / height, 0.1, 70.0);
	}

protected:

	void _ufoUp(void)
	{
		vector<Element*> elements = getScene()->getElements();
		for (vector<Element*>::iterator i = elements.begin(); i != elements.end(); ++i) {
			Soucoupe * soucoupe;
			if ((soucoupe = dynamic_cast<Soucoupe*>(*i)) != 0) {
				soucoupe->setY(soucoupe->y() + 0.3);
			}
		}
	}
	
	void _ufoLeft(void)
	{
		vector<Element*> elements = getScene()->getElements();
		for (vector<Element*>::iterator i = elements.begin(); i != elements.end(); ++i) {
			Soucoupe * soucoupe;
			if ((soucoupe = dynamic_cast<Soucoupe*>(*i)) != 0) {
				soucoupe->setX(soucoupe->x() - 0.3);
			}
		}
	}
	
	void _ufoRight(void)
	{
		vector<Element*> elements = getScene()->getElements();
		for (vector<Element*>::iterator i = elements.begin(); i != elements.end(); ++i) {
			Soucoupe * soucoupe;
			if ((soucoupe = dynamic_cast<Soucoupe*>(*i)) != 0) {
				soucoupe->setX(soucoupe->x() + 0.3);
			}
		}
	}
	
	void _ufoDown(void)
	{
		vector<Element*> elements = getScene()->getElements();
		for (vector<Element*>::iterator i = elements.begin(); i != elements.end(); ++i) {
			Soucoupe * soucoupe;
			if ((soucoupe = dynamic_cast<Soucoupe*>(*i)) != 0) {
				soucoupe->setY(soucoupe->y() - 0.3);
			}
		}
	}	
	
	void _ufoFar(void)
	{
		vector<Element*> elements = getScene()->getElements();
		for (vector<Element*>::iterator i = elements.begin(); i != elements.end(); ++i) {
			Soucoupe * soucoupe;
			if ((soucoupe = dynamic_cast<Soucoupe*>(*i)) != 0) {
				soucoupe->setZ(soucoupe->z() - 0.3);
			}
		}
	}	
	
	void _ufoNear(void)
	{
		vector<Element*> elements = getScene()->getElements();
		for (vector<Element*>::iterator i = elements.begin(); i != elements.end(); ++i) {
			Soucoupe * soucoupe;
			if ((soucoupe = dynamic_cast<Soucoupe*>(*i)) != 0) {
				soucoupe->setZ(soucoupe->z() + 0.3);
			}
		}
	}	
	void _displayEnter(void)
	{
		vector<Element*> elements = getScene()->getElements();
		for (vector<Element*>::iterator i = elements.begin(); i != elements.end(); ++i) {
			if (dynamic_cast<TextEnter*>(*i) != 0) {
				bool visible = (*i)->isVisible();
				(*i)->setVisible(!visible);
			}
		}
	}

	void _displayParking(void)
	{
		vector<Element*> elements = getScene()->getElements();
		for (vector<Element*>::iterator i = elements.begin(); i != elements.end(); ++i) {
			if (dynamic_cast<TextParking*>(*i) != 0) {
				bool visible = (*i)->isVisible();
				(*i)->setVisible(!visible);
			}
		
		}
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
	
	virtual void _setupLighting(void)
	{	
		glEnable(GL_NORMALIZE);
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


	// Texte Entree Enib
	TextEnter entreeEnib;
	entreeEnib.addTransformation(new Translation(-1.0, -6.0, 0.0));
	scene.addChild(&entreeEnib);


	// Texte Parking
	TextParking parking;
	scene.addChild(&parking);



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

	// Soucoupe 1
	
	// Initializing random position
	srand ( time(NULL) );
	double soucoupe1RandX = 20.0 - ( ( rand() % 200 + 1 ) / 5.0 );
	double soucoupe2RandX = 0.0 - ( ( rand() % 100 + 1 ) / 10.0 );
	double soucoupe1RandZ = 5.0 - ( ( rand() % 40 + 1 ) / 10.0 );
	double soucoupe2RandZ = -1.0 - ( ( rand() % 20 + 1 ) / 10.0 );
	
	
	Soucoupe soucoupe1;
	soucoupe1.addContext(new DepthTestContext());
	soucoupe1.addContext(new LightingContext());
	soucoupe1.addContext(new BlendingContext(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA));
	soucoupe1.setX(soucoupe1RandX);
	soucoupe1.setY(12.0);
	soucoupe1.setZ(soucoupe1RandZ);
	soucoupe1.addTransformation(new LandingAnimation(&soucoupe1,0.004,0.0,-4.7,2.0));

	// Soucoupe 2
	Soucoupe soucoupe2;
	soucoupe2.addContext(new DepthTestContext());
	soucoupe2.addContext(new LightingContext());
	soucoupe2.addContext(new BlendingContext(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA));
	soucoupe2.setX(soucoupe2RandX);
	soucoupe2.setY(12.0);
	soucoupe2.setZ(soucoupe2RandX);
	soucoupe2.addTransformation(new LandingAnimation(&soucoupe2,0.004,-1.0,-4.7,-3.0));
	
	// Générateur de fumée
	SmokeGenerator smokeGenerator(&soucoupe1);
	SmokeGenerator smokeGenerator2(&soucoupe2);
	smokeGenerator2.addContext(new DepthTestContext());
	
	scene.addChild(&smokeGenerator);
	scene.addChild(&smokeGenerator2);
	
	scene.addChild(&soucoupe1);
	scene.addChild(&soucoupe2);
	
	Window::loop();

	return 0;
}

