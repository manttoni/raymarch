#ifndef OBJECT_HPP
#define OBJECT_HPP

class Object
{
	private:
		Vec3 location;
	public:
		Object(Vec3 &location) : location(location) {}
		Vec3 getLocation() const { return location; }
		
		virtual float SDF() = 0;
};

#endif