#include "Ray.hpp"
#include "Vec3.hpp"

using namespace Ray;

Ray(int y, int x, Camera &c)
{
	dir = c.getViewDistance() * c.getDir() + c.pos;
	dir += (-X / 2 + x) * c.h;
	dir += (-Y / 2 + y) * c.v;
	this->normalize();
}