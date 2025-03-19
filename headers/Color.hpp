#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>

class Color
{
	private:
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	public:
		Color() : r(0), g(0), b(0), a(255) {} // aka background color
		Color(char r, char g, char b, char a);
		Color(char r, char g, char b);
		uint32_t get32() const { return r << 24 | g << 16 | b << 8 | a; }
		unsigned char getR() const { return r; }
		unsigned char getG() const { return g; }
		unsigned char getB() const { return b; }
		unsigned char getA() const { return a; }

};

#endif