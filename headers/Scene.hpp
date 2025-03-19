#ifndef SCENE_HPP
#define SCENE_HPP

#include "Light.hpp"
#include "Object.hpp"
#include "Camera.hpp"
#include <vector>
#include <memory>

class Scene
{
	private:
		std::vector<std::unique_ptr<Object>> objs;
		std::vector<Light> lights;
		Camera camera;
	public:
		Scene(std::vector<std::unique_ptr<Object>> &objs, std::vector<Light> &lights, Camera &c);
		Scene(const Scene&) = delete;
		Scene& operator=(const Scene&) = delete;
		Camera getCamera() const { return camera; }
		const std::vector<std::unique_ptr<Object>>& getObjects() const { return objs; }
		const std::vector<Light>& getLights() const { return lights; }
};

#endif