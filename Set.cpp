#include "Set.hpp"
#include "Object.hpp"
#include "Light.hpp"
#include "Camera.hpp"
#include <vector>

using namespace Set;

Set(vector<Object> &objs, vector<Light> &lights, Camera &c) : 
	objs(objs), lights(lights), camera(c)
{}