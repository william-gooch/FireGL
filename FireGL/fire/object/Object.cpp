#include "Object.hpp"

namespace fire::object {
	Object::Object()
	{
	}

	Object::Object(const Object* copy)
	{
		this->components = std::map(copy->components);
	}

	Object::~Object()
	{
	}

	void Object::AddComponent(std::string name, Component* component)
	{
		components[name] = component;
	}
}