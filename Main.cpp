#include "Renderer/Renderer.h"
#include "Objects/Sphere.h"
#include "Objects/Scene.h"
#include "Objects/Plane.h"
#include "Renderer/Camera.h"
#include <iostream>

int main(int argc, char** argv)
{
	const int width = 800;
	const int height = 600;
	const int samples = 1;

	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow(width, height); //800 600

	Canvas canvas(width, height, renderer);
	Camera camera({ 0, 1, 3 }, { 0, 0, 0 }, { 0, 1, 0 }, 70.0f, width / (float)height);
	
	Scene scene;
	//Spheres
	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, .5f, 1 }, 0.5f, std::make_unique<Lambertian>(color3{ 1, 1, 0.01f })));
	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 1.2f, .5f, 1 }, 0.5f, std::make_unique<Metal>(color3{ 1, 1, 1 }, 0.2f)));
	//scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, -100.5, 1 }, 100.0f, std::make_unique<Lambertian>(color3{ 0.2f, 0.2f, 0.2f })));

	//Plane
	scene.AddObject(std::make_unique<Plane>(glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 1, 0 }, std::make_unique<Metal>(color3{ 1,1, 1 }, 0.1f)));


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
		renderer.Render(canvas, scene, camera, samples);
		canvas.Update();

		renderer.CopyCanvas(canvas);
		renderer.Present();

	}
	renderer.ShutDown();

	return 0;
}