#include "Renderer/Renderer.h"
#include <iostream>

int main(int argc, char** argv)
{
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow(800, 600);

	Canvas canvas(600, 400, renderer);

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
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		default:
			break;
		}

		//render scene
		canvas.Clear({ 0, 0, 0, 1});
		//static
		for (int i = 0; i < 90000; i++)
		{
			canvas.DrawPoint({ random(0, 600), random(0, 400)}, {1, 1, 1, random01()});
		}
		canvas.Update();

		renderer.CopyCanvas(canvas);
		renderer.Present();

	}
	renderer.ShutDown();

	return 0;
}