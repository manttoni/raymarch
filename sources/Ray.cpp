#include "../headers/Ray.hpp"
#include "../headers/Vec3.hpp"
#include "../headers/Camera.hpp"
#include "../headers/Header.hpp"

Ray::Ray(int x, int y, Camera &c)
{
	pos = c.getPos();
	dir = c.getDir() * c.getViewDistance();
	dir = dir + c.getPos();
	dir = dir + c.getH() * (-X / 2 + x);
	dir = dir + c.getV() * (-Y / 2 + y);
	dir = dir.normalize();
}

void Ray::march(const float dist)
{
	pos = pos + dir * dist;
}