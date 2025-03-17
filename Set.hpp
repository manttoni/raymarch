#ifndef SET_HPP
#define SET_HPP

#include "Light.hpp"
#include "Object.hpp"
#include "Camera.hpp"
#include <vector>

class Set
{
	private:
		vector<Object> objs;
		vector<Light> lights;
		Camera c;
	public:
		Set(vector<Object> &objs, vector<Light> lights, Camera &c);
		Camera& getCamera() const { return c; }
};

#endif