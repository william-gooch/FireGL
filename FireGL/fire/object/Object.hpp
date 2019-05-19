#pragma once

#include "../component/Component.hpp"

#include <vector>
#include <map>
#include <string>

namespace fire::object {
	using namespace component;

	class Object
	{
	public:
		Object();
		Object(const Object* copy);
		~Object();

		void AddComponent(std::string name, Component* component);

	private:

		std::map<std::string, Component*> components;

	};

}