#include "../headers/Sphere.hpp"
#include "../headers/Camera.hpp"
#include "../headers/Header.hpp"
#include "../headers/Scene.hpp"
#include "../headers/Ray.hpp"
#include <vector>
#include <float.h>
#include <memory>

void collisions(Ray &r, Scene &s)
{
	float closest = FLT_MAX;
	for(const auto &o : s.getObjects())
	{
		int dist = o->sdf(r.getPos());
		if (dist < closest)
			closest = dist;
	}
}

void dothething(Scene &scene)
{
	Camera c = scene.getCamera();
	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			Ray r(y, x, c);
			collisions(r, scene);
		}
	}
}

int main(void)
{
	std::vector<std::unique_ptr<Object>> objs;
	objs.push_back(std::make_unique<Sphere>(Vec3(0,0,0), 1, Color(255,0,0)));
	
	Light l(Vec3(7,7,7), 1, Color(255,255,255));
	std::vector<Light> lights;
	lights.push_back(l);

	Camera c(Vec3(10,0,0), Vec3(-1,0,0), 90);

	Scene scene(objs, lights, c);

	dothething(scene);

	return 0;
}