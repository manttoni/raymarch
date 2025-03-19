#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Object.hpp"
#include "Vec3.hpp"

class Sphere : public Object
{
	private:
		float r;
	public:
		// constructors
		Sphere(const Vec3 &pos, float r, const Color &c) : Object(pos, c), r(r) {}

		float getRadius() const { return r; }

		float sdf(const Vec3 &pos) const override { return (pos - this->pos).len() - r; }
};

#endif