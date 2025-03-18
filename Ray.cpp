#include "Ray.hpp"
#include "Vec3.hpp"
#include "Camera.hpp"
#include "Header.hpp"

Ray::Ray(int y, int x, Camera &c)
{
	dir = c.getDir() * c.getViewDistance();
	dir = dir + c.getPos();
	dir = dir + c.getH() * (-X / 2 + x);
	dir = dir + c.getV() * (-Y / 2 + y);
	dir.normalize();
}