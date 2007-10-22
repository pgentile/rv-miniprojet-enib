#include "test-window.h"
#include "test-scene.h"
#include "tree.h"
#include "barney.h"
#include "poof-effect.h"

int main(int argc, char** argv)
{
	TestWindow window;
	TestScene scene;
	Tree tree;
	Barney barney;
	PoofEffect poofEffect;
	
	//scene.addChild(&tree);
	//scene.addChild(&barney);
	scene.addChild(&poofEffect);
	
	scene.init();
	window.setScene(&scene);
	Window::create(argc, argv, window);
	return 0;
}
