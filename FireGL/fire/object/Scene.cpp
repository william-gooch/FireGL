#include "Scene.hpp"

namespace fire::object {
	Scene::Scene()
	{
		this->rootObjects = std::vector<GameObject*>();
	}


	Scene::~Scene()
	{
	}

	void Scene::AddObject(GameObject *gameObject)
	{
		this->rootObjects.push_back(gameObject);
	}
}
