#pragma once

#include "Object.hpp"
#include "Transform.hpp"

#include <vector>

namespace fire::object {
	class GameObject : Object
	{
	public:
		GameObject();
		~GameObject();

		Transform getGlobalTransform();

	private:

		Transform localTransform;

		GameObject* parent;
		std::vector<GameObject*> children;
	};
}

