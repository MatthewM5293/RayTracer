#include "Renderer/Renderer.h"
#include <iostream>

int main(int argc, char** argv)
{
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow(800, 600);

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		default:
			break;
		}
	}
	renderer.ShutDown();

	return 0;
}