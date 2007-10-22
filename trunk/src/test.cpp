#include "test-window.h"
#include "test-scene.h"
#include "tree.h"
#include "barney.h"

int main(int argc, char** argv)
{
	TestWindow window;
	TestScene scene;
	Tree tree;
	Barney barney;
	
	scene.addChild(&tree);
	scene.addChild(&barney);
	
	scene.init();
	window.setScene(&scene);
	Window::create(argc, argv, window);
	return 0;
}
