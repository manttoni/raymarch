#ifndef LIGHT_HPP
#define LIGHT_HPP

class Light : public Object
{
	private:
		float brightness;
		Color color;
	public:
		Light(Vec3 &location, float brightness, Color &c) : brightness(brighness), color(c) {}
};

#endif