#include "window.h"
#include "scene.h"
#include "scene-element.h"
#include <GL/glut.h>
#include <string>
#include <iostream>

#define ESC_KEY 27

using namespace std;


/**
 * Fenêtre paramétrée
 */
class LightsWindow: public Window
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
class LightsScene: public Scene
{

public:

	virtual void init(void)
	{
		Scene::init();

		_angle = 0.0;
	}

	virtual void animate(int timerInterval)
	{
		Scene::animate(timerInterval);

		_angle += 1.0;
		if (_angle >= 360.0) {
			_angle -= 360.0;
		}
	}

	virtual void render(void)
	{

		float globalAmbient[] = { 0.4, 0.4, 0.4, 1.0 };
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

		float light0Ambient[] = { 1.0, 1.0, 1.0, 1.0 };
		float light0Diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
		float light0Specular[] = { 1.0, 1.0, 1.0, 1.0 };
		float light0Position[] = { 0.0, 6.0, 0.0, 1.0 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
		glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
		glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.1);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);

		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_COLOR_MATERIAL);

		Scene::render();

		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);
		
	}

protected:

	virtual void _setCamera(void)
	{
		gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glRotatef(_angle, 0.0, 1.0, 0.0);
	}

private:

	float _angle;

};


/**
 * Axes définissant le repère courant
 */
class Axes: public SceneElement
{

public:

	virtual void animate(int)
	{
	}

	virtual void render(void)
	{
		glBegin(GL_LINES);

		// X
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);

		// Y
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);

		// Z
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 1.0);

		glEnd();
	}

};


/**
 * Sphère
 */
class Sphere: public SceneElement
{

public:

	Sphere(float r)
	{
		_r = r;
		_x = _y = _z = 0.0;
	}

	Sphere(float r, float x, float y, float z)
	{
		_r = r;
		_x = x;
		_y = y;
		_z = z;
	}

	virtual void animate(int)
	{
	}

	virtual void render(void)
	{
		glTranslatef(_x, _y, _z);
		glColor3f(1.0, 0.0, 0.0);
		glutSolidSphere(_r, 30, 30);
	}

private:

	float _r;
	float _x, _y, _z;

};


/**
 * Plan
 */
class Plane: public SceneElement
{

public:

	Plane(void)
	{
		_x = _y = _z = 0.0;
	}

	Plane(float x, float y, float z)
	{
		_x = x;
		_y = y;
		_z = z;
	}

	virtual void animate(int)
	{
	}

	virtual void render(void)
	{
		glTranslatef(_x, _y, _z);
		glBegin(GL_QUADS);
		glColor3f(0.5, 0.5, 0.5);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex2f(2.0, 1.0);
		glVertex2f(2.0, -20.0);
		glVertex2f(-2.0, -20.0);
		glVertex2f(-2.0, 1.0);
		glEnd();
	}

private:

	float _x, _y, _z;

};


/**
 * Main
 */
int main(int argc, char** argv)
{
	LightsWindow window;
	LightsScene scene;

	Axes axes;
	Sphere sphere(0.5, 0.0, 0.0, 1.5);
	Plane plane(0.0, 0.0, 2.5);

	scene.addChild(&axes);
	scene.addChild(&sphere);
	scene.addChild(&plane);

	scene.init();
	window.setScene(&scene);
	window.setTitle("Test des lumieres");
	Window::create(argc, argv, window);

	return 0;
}

