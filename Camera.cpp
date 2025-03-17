#include "Camera.hpp"
#include "Vec3.hpp"

#include <cmath>
#include "Header.hpp" // lol

using namespace Camera;

Camera(Vec3 &pos, Vec3 &dir, int fov) : pos(pos), dir(dir), fov(fov)
{
	setViewDistance(fov);
}

void setViewDistance(int fov)
{
	float fov_rad;

	fov_rad = fov * M_PI / 180;
	view_distance = ((X / 2) / tan(fov_rad / 2));
}