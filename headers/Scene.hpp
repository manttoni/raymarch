#ifndef SCENE_HPP
#define SCENE_HPP

#include "Light.hpp"
#include "Object.hpp"
#include "Camera.hpp"
#include <vector>

class Scene
{
	private:
		std::vector<Object> objs;
		std::vector<Light> lights;
		Camera camera;
	public:
		Scene(std::vector<Object> &objs, std::vector<Light> &lights, Camera &c);
		Camera getCamera() const { return camera; }
};

#endif