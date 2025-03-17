#ifndef OBJECT_HPP
#define OBJECT_HPP

typedef enum
{
	SPHERE
} type;

class Object
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