#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere : public Shape
{
	private:
		float r;
		Color color;
	public:
		float getD() const { return d; }
		Color& getColor() const { return color; }

		float SDF(Vec3 pos, float r) { return len(p) - r; }
};

#endif