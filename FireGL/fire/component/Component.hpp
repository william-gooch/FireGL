#pragma once

namespace fire::component {
	class Component
	{
	public:
		virtual void Start() = 0;
		virtual void Update() = 0;

	protected:
		Component();
		~Component();
	};
}