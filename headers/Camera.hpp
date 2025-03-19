#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Vec3.hpp"

class Camera
{
	private:
		Vec3 pos;
		Vec3 dir;
		int fov;
		Vec3 h, v;
		float view_distance;
	public:
		// constructors
		Camera(const Vec3 &pos, const Vec3 &dir, int fov);

		Vec3 getDir() const { return dir; }
		int getFov() const { return fov; }

		void setViewDistance(int fov);
		float getViewDistance() const { return view_distance; }
		Vec3 getH() const { return h; }
		Vec3 getV() const { return v; }
		Vec3 getPos() const { return pos; }

		float SDF() = delete;
};

#endif