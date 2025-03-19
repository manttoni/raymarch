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

void color_pixel(SDL_Renderer *renderer, const Color &c, const int x, const int y)
{
	SDL_SetRenderDrawColor(renderer, c.getR(), c.getG(), c.getB(), c.getA());
	SDL_RenderDrawPoint(renderer, x, y);
}

// loop through all objects and find the closest
float closest_dist(Ray &r, const Scene &s, Color *c)
{
	float closest = FLT_MAX;
	for(const auto &o : s.getObjects())
	{
		float dist = o->sdf(r.getPos());
		if (dist < closest)
		{
			if (dist < EPSILON)
				*c = o->getColor();
			closest = dist;
		}
	}
	return closest;
}

// march with ray until it hits something or jumps enough times or too far
Color single_ray(Ray &r, Scene &scene)
{
	Color c;
	for (int i = 0; i < 80; ++i)
	{
		float dist = closest_dist(r, scene, &c);
		r.march(dist);
		if (dist < EPSILON || dist > RENDER_DIST)
			break;
	}
	return c;
}

void apply_light(Ray &r, Scene &scene, Color *c)
{
	for(const auto &l : scene.getLights())
	{
		Ray light_ray(r.getPos(), l.getPos());
		light_ray.march(0.1);
		single_ray(light_ray, scene);
		if ((r.getPos() - light_ray.getPos()).len() >= (r.getPos() - l.getPos()).len())
		{
			return;
		}
	}
	*c = Color();
}

// loop through all pixels
void start(Scene &scene, SDL_Renderer *renderer)
{
	Camera c = scene.getCamera();
	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			Ray r(x, y, c);
			Color c = single_ray(r, scene);
			apply_light(r, scene, &c);
			color_pixel(renderer, c, x, y);
		}
		std::cout << 100 * y / Y << "%\r";
	}
	std::cout << "Ready!" << std::flush;
}

int main(void)
{
	std::vector<std::unique_ptr<Object>> objs;
	objs.push_back(std::make_unique<Sphere>(Vec3(0,0,0), 5, Color(255,0,0)));
	
	Light l(Vec3(10,10,0), 1, Color(255,255,255));
	std::vector<Light> lights;
	lights.push_back(l);
	
	Camera c(Vec3(10,0,0), Vec3(-1,0,0), 90);
	
	Scene scene(objs, lights, c);
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* win = SDL_CreateWindow(	"raymarch",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 
		X, Y,
		SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
		
	start(scene, renderer);
		
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();

	return 0;
}