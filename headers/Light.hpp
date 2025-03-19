#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Color.hpp"
#include "Vec3.hpp"

class Light
{
	private:
		Vec3 pos;
		float brightness;
		Color color;
	public:
		Light(const Vec3 &pos, float brightness, const Color &c) : pos(pos), brightness(brightness), color(c) {}
};

#endif