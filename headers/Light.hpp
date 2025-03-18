#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Object.hpp"
#include "Color.hpp"
#include "Vec3.hpp"

class Light : public Object
{
	private:
		float brightness;
		Color color;
	public:
		Light(const Vec3 &pos, float brightness, const Color &c) : Object(pos), brightness(brightness), color(c) {}
};

#endif