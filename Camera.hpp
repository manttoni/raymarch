#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Vec3.hpp"


class Camera : public Object
{
	private:
		Vec3 dir;
		int fov;
		Vec3 h, v;
		float view_distance;
	public:
		// constructors
		Camera(Vec3 &pos, Vec3 &dir, int fov) : pos(pos), dir(dir), fov(fov) {}

		Vec3 getDir() const { return dir; }
		Vec3 getFov() const { return fov; }

		void setVievDistance(int fov);
};

#endif