#include "../headers/Camera.hpp"
#include "../headers/Vec3.hpp"
#include "../headers/Header.hpp"
#include <cmath>

Camera::Camera(const Vec3 &pos, const Vec3 &dir, int fov) : pos(pos), dir(dir.normalize()), fov(fov)
{
	setViewDistance(fov);
	Vec3 up(0, 1, 0);
	h = dir.cross(up);
	v = h.cross(dir);
}

void Camera::setViewDistance(int fov)
{
	float fov_rad;

	fov_rad = fov * M_PI / 180;
	view_distance = ((X / 2) / tan(fov_rad / 2));
}