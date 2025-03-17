#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Vec3.hpp"
#include "Object.hpp"

class Camera : public Object
{
	private:
		Vec3 dir;
		int fov;
		Vec3 h, v;
		float view_distance;
	public:
		// constructors
		Camera(Vec3 &pos, Vec3 &dir, int fov);

		Vec3 getDir() const { return dir; }
		int getFov() const { return fov; }

		void setViewDistance(int fov);
};

#endif