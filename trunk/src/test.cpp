#include "test-window.h"

int main(int argc, char** argv)
{
	TestWindow window;
	Window::create(argc, argv, window);
	return 0;
}
