#include "test-window.h"
#include "test-scene.h"
#include "barney.h"
#include "soucoupe.h"

int main(int argc, char** argv)
{
	TestWindow window;
	TestScene scene;
	Barney barney;
	scene.addChild(&barney);
	window.setScene(&scene);
	Window::create(argc, argv, window);
	return 0;
}
