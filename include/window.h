#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include "scene.h"

using namespace std;

class Window
{

public:

	Window(void);

	void setPosition(int x, int y);

	void setSize(int width, int height);

	void setTitle(string title);
	string getTitle(void);
	
	void setScene(Scene* scene);
	Scene* getScene(void);
	
	void setRefreshRate(unsigned int rate);
	unsigned int getRefreshRate(void);
	unsigned int getTimerInterval(void);

	virtual void onKeyPress(unsigned char key, int x, int y);
	virtual void onSpecialKeyPress(int key, int x, int y);
	virtual void onTick(int timerInterval);

	virtual void changeProjection(int width, int height) = 0;

	virtual void display(void);

	static void create(int argc, char** argv, Window& window);

	static void loop(void);

private:

	struct {
		int x, y;
	} _position;

	struct {
		int width, height;
	} _size;

	string _title;
	
	unsigned int _refreshRate;
	
	Scene* _scene;

};

#endif
