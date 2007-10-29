#include "window.h"
#include "scene.h"
#include "scene-element.h"
#include "positioned-element.h"
#include "png-loader.h"
#include "smoke-generator.h"
#include "tree.h"
#include <GL/glut.h>
#include <string>
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

		case ESC_KEY:
			exit(0);
			break;

		}
	}

	virtual void changeProjection(int width, int height)
	{
		gluPerspective(60.0, (float) width / height, 0.1, 60.0);
	}

};


/**
 * Scène paramétrée
 */
class EnibScene: public Scene
{

public:

	virtual void init(void)
	{
		Scene::init();
	}

	virtual void render(void)
	{

		glEnable(GL_DEPTH_TEST);
		Scene::render();
		glDisable(GL_DEPTH_TEST);
	}

protected:

	virtual void _setCamera(void)
	{
		gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	}

};


/**
 * Plan texturé avec l'ENIB
 */
class EnibPlane: public SceneElement
{

public:

	void animate(int)
	{
	}

	void render(void)
	{
		static int texture = PngLoader::load("batimentEnib.png");
		static float width = 1.8 * 2.7;
		static float height = 1.0 * 2.7;

		glEnable(GL_DEPTH_TEST);


		glAlphaFunc(GL_GREATER, 0.9);
		glEnable(GL_ALPHA_TEST);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTranslatef(0.0, -1.5, 0.0);
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(0.0, 1.0); glVertex2f(-width, height);
		glTexCoord2f(1.0, 1.0); glVertex2f(width, height);
		glTexCoord2f(1.0, 0.0); glVertex2f(width, -height);
		glTexCoord2f(0.0, 0.0); glVertex2f(-width, -height);
		glEnd();

		glDisable(GL_TEXTURE_2D);
		glDisable(GL_ALPHA_TEST);
		glDisable(GL_DEPTH_TEST);
	}

};


/**
 * Plan texturé avec le ciel
 */
class SkyPlane: public SceneElement
{

public:

	void animate(int)
	{
	}

	void render(void)
	{
		static int texture = PngLoader::load("sky.png");
		static float width = 1.8 * 12.0;
		static float height = 1.0 * 12.0;
		static float zIndex = -15.0;

		glEnable(GL_DEPTH_TEST);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);

		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(-width, height, zIndex);
		glTexCoord2f(1.0, 1.0); glVertex3f(width, height, zIndex);
		glTexCoord2f(1.0, 0.0); glVertex3f(width, -height, zIndex);
		glTexCoord2f(0.0, 0.0); glVertex3f(-width, -height, zIndex);
		glEnd();

		glDisable(GL_TEXTURE_2D);
		glDisable(GL_DEPTH_TEST);
	}

};


/**
 * Sphère
 */
class Sphere: public SceneElement, public PositionedElement
{

public:

	Sphere(float x, float y, float z)
	{
		setX(x);
		setY(y);
		setZ(z);
	}

	void animate(int)
	{
	}

	void render(void)
	{
		glEnable(GL_DEPTH_TEST);

		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(getX(), getY(), getZ());
		glutWireSphere(1.0, 25, 25);

		glDisable(GL_DEPTH_TEST);
	}

};


/**
 * Main
 */
int main(int argc, char** argv)
{
	EnibWindow window;
	EnibScene scene;

	EnibPlane enibPlane;
	SkyPlane skyPlane;
	Sphere sphere(0.0, -2.0, -3.0);
	SmokeGenerator smokeGenerator(&sphere);
	

	scene.addChild(&skyPlane);
	scene.addChild(&smokeGenerator);
	scene.addChild(&enibPlane);
	scene.addChild(&sphere);

	scene.init();
	window.setScene(&scene);
	window.setTitle("ENIB Attack");
	Window::create(argc, argv, window);

	return 0;
}

