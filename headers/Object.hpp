#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Vec3.hpp"
#include "Color.hpp"

class Object
{
	protected:
		Vec3 pos;
		Color color;
	public:
		Object(const Vec3 &pos, const Color &color) : pos(pos), color(color) {}
		Object(const Vec3 &pos) : pos(pos), color(Color(255,255,255)) {}
		Vec3 getPos() const { return pos; }
		Color getColor() const { return color; }
		virtual float sdf(const Vec3 &pos) const = 0;
};

#endif