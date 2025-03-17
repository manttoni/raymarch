#ifndef SHAPE_HPP
#define SHAPE_HPP

typedef enum
{
	SPHERE
} type;

class Shape
{
	private:
		type type;
		Vec3 location;
	public:
		type getType() const { return type; }
		Vec3 getLocation() const { return location; }
		
		virtual float SDF() = 0;
};

#endif