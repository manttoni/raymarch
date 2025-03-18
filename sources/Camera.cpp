#include "../headers/Camera.hpp"
#include "../headers/Vec3.hpp"
#include "../headers/Header.hpp"
#include "../headers/Object.hpp"
#include <cmath>

Camera::Camera(const Vec3 &pos, const Vec3 &dir, int fov) : Object(pos), dir(dir), fov(fov)
{
	setViewDistance(fov);
}

void Camera::setViewDistance(int fov)
{
	float fov_rad;

	fov_rad = fov * M_PI / 180;
	view_distance = ((X / 2) / tan(fov_rad / 2));
}