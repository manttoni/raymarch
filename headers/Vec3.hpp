#ifndef VEC3_HPP
#define VEC3_HPP

class Vec3
{
	private:
		float x, y, z;
	public:
		// Constructors etc
		Vec3();
		Vec3(float x, float y, float z);
		Vec3(const Vec3 &other);
		Vec3& operator=(const Vec3 &other);

		bool operator==(const Vec3 &other) const;

		// math
		Vec3 operator+(const Vec3 &other) const;
		Vec3 operator-(const Vec3 &other) const;
		Vec3 operator*(float s) const;
		Vec3 operator/(float s) const;

		// geo
		float dot(const Vec3 &other) const;
		Vec3 cross(const Vec3 &other) const;
		float len() const;
		void normalize();
};

#endif