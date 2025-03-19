#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>

class Color
{
	private:
		char r;
		char g;
		char b;
		char a;
	public:
		Color(char r, char g, char b, char a);
		Color(char r, char g, char b);
		uint32_t get32() const { return r << 24 | g << 16 | b << 8 | a; }

};

#endif