#include "Vec3.hpp"

using namespace Vec3;

Vec3() : x(0), y(0), z(0) {}

Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3(const Vec3 &other) : x(other.x), y(other.y), z(other.z) {}

Vec3& operator=(const Vec3 &other)
{
	if (*this == other)
		return *this;
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}

bool operator==(const Vec3 &other) const
{
	return x == other.x && y == other.y && z == other.z;
}

Vec3 operator+(const Vec3 &other) const
{
	return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 operator-(const Vec3 &other) const
{
	return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 operator*(float s, const Vec3 &v) const
{
	return Vec3(s * v.x, s * v.y, s * v.z);
}

Vec3 operator/(float s, const Vec3 &v) const
{
	return Vec3(v.x / s, v.y / s, v.z / s);
}

float dot(const Vec3 &other)
{
	return Vec3(x * other.x, y * other.y, z * other.z);
}

Vec3 cross(const Vec3 &other) const
{
	Vec3 result;
	result.x = this->y * other.z - this->z * other.y;
	result.y = this->z * other.x - this->x * other.z;
	result.z = this->x * other.y - this->y * other.x;
	return result;
}

float len() const
{
	return sqrt(x * x + y * y + z * z);
}

void normalize() // maybe instead return a normalized vector instead of modifying? let see
{
	float l = len();
	x /= l;
	y /= l;
	z /= l;
}

