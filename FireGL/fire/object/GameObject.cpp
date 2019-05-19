#include "GameObject.hpp"

#include <queue>

namespace fire::object {
	GameObject::GameObject()
	{
	}


	GameObject::~GameObject()
	{
	}

	Transform GameObject::getGlobalTransform()
	{
		GameObject* currentObj = this;
		Transform globalTransform;
		while (currentObj != nullptr) {
			globalTransform = globalTransform * currentObj->localTransform;
			currentObj = currentObj->parent;
		}
		return globalTransform;
	}
}
