#include "test-window.h"
#include "test-scene.h"
#include "tree.h"

int main(int argc, char** argv)
{
	TestWindow window;
	TestScene scene;
	Tree tree;
	
	scene.addChild(&tree);
	window.setScene(&scene);
	Window::create(argc, argv, window);
	return 0;
}
