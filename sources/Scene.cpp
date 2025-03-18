#include "../headers/Scene.hpp"
#include "../headers/Object.hpp"
#include "../headers/Light.hpp"
#include "../headers/Camera.hpp"
#include <vector>

Scene::Scene(std::vector<Object> &objs, std::vector<Light> &lights, Camera &c) : 
	objs(objs), lights(lights), camera(c)
{}