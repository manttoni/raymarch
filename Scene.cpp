#include "Scene.hpp"
#include "Object.hpp"
#include "Light.hpp"
#include "Camera.hpp"
#include <vector>

Scene::Scene(std::vector<Object> &objs, std::vector<Light> &lights, Camera &c) : 
	objs(objs), lights(lights), camera(c)
{}