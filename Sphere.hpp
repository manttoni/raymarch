#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Object.hpp"

class Sphere : public Object
{
	private:
		float r;
		Color color;
	public:
		// constructors
		Sphere(Vec3 &position, float r, Color &c) : position(position), r(r), color(c) {}

		float getD() const { return d; }
		Color& getColor() const { return color; }

		float SDF(Vec3 pos, float r) { return len(p) - r; }
};

#endif