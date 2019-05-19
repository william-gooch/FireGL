#pragma once

#include "GameObject.hpp"
#include "Object.hpp"

#include <vector>

namespace fire::object {
	class Scene : Object 
	{
	public:
		Scene();
		~Scene();

		void AddObject(GameObject* gameObject);

	private:
		std::vector<GameObject*> rootObjects;
	};
}
