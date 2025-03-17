#include "Sphere.hpp"
#include "Camera.hpp"
#include <vector>
#include "Header.hpp"
#include <float.h>

void collisions(Ray &r, Set &s)
{
	float closest = FLT_MAX;
	for(Object o : s.getObjs())
	{
		closest = o.SDF(r.pos, o)
	}
}

void dothething(Set set)
{
	Camera c = set.getCamera();
	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			Ray r(y, x, c);
			collisions(r, set);
		}
	}
}

int main(void)
{
	Sphere s(Vec3(0,0,0), 1, Color(255,0,0));
	vector<Object> objs;
	objs.push_back(s);
	
	Light l(Vec3(7,7,7), 1, Color(255,255,255));
	vector<Light> lights;
	lights.push_back(l);

	Camera c(Vec3(10,0,0), Vec3(-1,0,0), 90);

	Set set(objs, lights, c);

	dothething(set);

	return 0;
}