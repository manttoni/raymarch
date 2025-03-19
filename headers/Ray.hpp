#ifndef RAY_HPP
#define RAY_HPP

#include "Vec3.hpp"
#include "Camera.hpp"

class Ray
{
	private:
		Vec3 dir;
		Vec3 pos;
	public:
		Ray(int x, int y, Camera &c);

		Vec3 getDir() const { return dir; }
		Vec3 getPos() const { return pos; }

		void setDir(Vec3 dir) { this->dir = dir; }
		void setPos(Vec3 pos) { this->pos = pos; }
};

#endif