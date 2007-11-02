#include "window.h"
#include "scene.h"
#include "textured-rectangle.h"
#include "translation.h"
#include "rotation.h"
#include "scale.h"
#include "depth-test-context.h"
#include "alpha-test-context.h"
#include "tree.h"
#include "text-enter.h"
#include "text-parking.h"
#include "soucoupe.h"
#include "smoke-generator.h"
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
		case 'e': /* Indique ou est l'entree */
			_displayEnter();
			break;
    		case 'p':  /* Indique ou sont les parkings */
			_displayParking();
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
		GLfloat ambientLight[]={0.7,0.7,0.7,1.0};    	             // set ambient light parameters
		glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);

		GLfloat diffuseLight[]={0.8,0.8,0.8,1.0};    	             // set diffuse light parameters
		glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
		
		GLfloat specularLight[]={0.5,0.5,0.5,1.0};  	               // set specular light parameters
		glLightfv(GL_LIGHT0,GL_SPECULAR,specularLight);

		GLfloat lightPos[]={-60.0,5.0,7.0,0.0};      	              // set light position
		glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
		          	        
		glEnable(GL_LIGHTING);                       	              // enable lighting
		//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight); 	     // set light model
		glEnable(GL_COLOR_MATERIAL);                 	              // activate material
		glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
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

	// Soucoupe
	Soucoupe soucoupe;
	soucoupe.addContext(new DepthTestContext());
	soucoupe.setX(-3.5);
	soucoupe.setY(-3.5);
	soucoupe.setZ(6.0);

	// Cockpit de la soucoupe
	SoucoupeCockpit cockpit;
	cockpit.addTransformation(new Translation(0.0,2.7,0.0));
	cockpit.addContext(new DepthTestContext());
	
	// Boules de Lumière de la Soucoupe
	SoucoupeLightSphere sphere1(GL_LIGHT0);
	SoucoupeLightSphere sphere2(GL_LIGHT1);
	SoucoupeLightSphere sphere3(GL_LIGHT2);
	SoucoupeLightSphere sphere4(GL_LIGHT3);
	SoucoupeLightSphere sphere5(GL_LIGHT4);
	SoucoupeLightSphere sphere6(GL_LIGHT5);
	
	sphere1.addContext(new DepthTestContext());
	sphere2.addContext(new DepthTestContext());
	sphere3.addContext(new DepthTestContext());
	sphere4.addContext(new DepthTestContext());
	sphere5.addContext(new DepthTestContext());
	sphere6.addContext(new DepthTestContext());
	
	
	sphere1.addTransformation(new Translation(0.0, 1.2, -4.0));
	sphere2.addTransformation(new Rotation(60.0, 0.0, 1.0, 0.0));
	sphere2.addTransformation(new Translation(0.0, 1.2, -4.0));
	sphere3.addTransformation(new Rotation(120.0, 0.0, 1.0, 0.0));
	sphere3.addTransformation(new Translation(0.0, 1.2, -4.0));
	sphere4.addTransformation(new Rotation(180.0, 0.0, 1.0, 0.0));
	sphere4.addTransformation(new Translation(0.0, 1.2, -4.0));
	sphere5.addTransformation(new Rotation(240.0, 0.0, 1.0, 0.0));
	sphere5.addTransformation(new Translation(0.0, 1.2, -4.0));
	sphere6.addTransformation(new Rotation(300.0, 0.0, 1.0, 0.0));
	sphere6.addTransformation(new Translation(0.0, 1.2, -4.0));
	
	soucoupe.addChild(&cockpit);
	soucoupe.addChild(&sphere1);
	soucoupe.addChild(&sphere2);
	soucoupe.addChild(&sphere3);
	soucoupe.addChild(&sphere4);
	soucoupe.addChild(&sphere5);
	soucoupe.addChild(&sphere6);
	// Générateur de fumée
	SmokeGenerator smokeGenerator(&soucoupe);
	scene.addChild(&smokeGenerator);

	scene.addChild(&soucoupe);

	Window::loop();

	return 0;
}

