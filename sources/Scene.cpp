#include "../headers/Scene.hpp"
#include "../headers/Object.hpp"
#include "../headers/Light.hpp"
#include "../headers/Camera.hpp"
#include <vector>

Scene::Scene(std::vector<std::unique_ptr<Object>> &objs, std::vector<Light> &lights, Camera &c) : 
	objs(std::move(objs)), lights(lights), camera(c)
{}