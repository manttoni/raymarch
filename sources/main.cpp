#include "../headers/Sphere.hpp"
#include "../headers/Camera.hpp"
#include "../headers/Header.hpp"
#include "../headers/Scene.hpp"
#include "../headers/Ray.hpp"
#include <vector>
#include <float.h>
#include <memory>
#include <SDL2/SDL.h>
#include <iostream>

float closest_dist(Ray &r, Scene &s)
{
	float closest = FLT_MAX;
	for(const auto &o : s.getObjects())
	{
		float dist = o->sdf(r.getPos());
		if (dist < closest)
			closest = dist;
	}
	return closest;
}

void dothething(Scene &scene, SDL_Renderer *renderer)
{
	Camera c = scene.getCamera();
	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			Ray r(x, y, c);
			bool hit = false;
			for (int i = 0; i < 80; ++i)
			{
				float dist = closest_dist(r, scene);
				r.setPos(r.getPos() + r.getDir() * dist);
				if (dist < 0.001)
					hit = true;
			}
			if (hit)
			{
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			}
			else
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	SDL_RenderPresent(renderer);
}

int main(void)
{
	std::vector<std::unique_ptr<Object>> objs;
	objs.push_back(std::make_unique<Sphere>(Vec3(0,0,0), 5, Color(255,0,0)));
	
	Light l(Vec3(7,7,7), 1, Color(255,255,255));
	std::vector<Light> lights;
	lights.push_back(l);

	Camera c(Vec3(10,0,0), Vec3(-1,0,0), 90);

	Scene scene(objs, lights, c);

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* win = SDL_CreateWindow(	"raymarch",
										SDL_WINDOWPOS_CENTERED,
										SDL_WINDOWPOS_CENTERED, 
										800, 600,
										SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	dothething(scene, renderer);

	SDL_Delay(3000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();

	return 0;
}