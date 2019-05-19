#pragma once

#include <vector>

#ifdef FIREGL_EXPORTS
#define FIREGL_API __declspec(dllexport)
#else
#define FIREGL_API __declspec(dllimport)
#endif

namespace fire {
	template <typename T> class Event
	{
	public:
		using EventCallback = void (*) (T);

		Event() {
			this->callbacks = std::vector<EventCallback>();
		}
		~Event() {}

		void invoke(T args) {
			for (EventCallback callback : this->callbacks) {
				callback(args);
			}
		}

		void operator += (EventCallback callback) {
			this->callbacks.push_back(callback);
		}

	private:
		std::vector<EventCallback> callbacks;
	};

	struct KeyEventArgs {
		int key;
		int scancode;
		int action;
		int mods;
	};
	using KeyEvent = Event<KeyEventArgs>;
	using KeyEventCallback = KeyEvent::EventCallback;

	struct MouseMoveEventArgs {
		double xpos;
		double ypos;
	};
	using MouseMoveEvent = Event<MouseMoveEventArgs>;
	using MouseMoveEventCallback = MouseMoveEvent::EventCallback;
	
	struct MouseButtonEventArgs {
		double xpos;
		double ypos;
		int button;
		int action;
		int mods;
	};
	using MouseButtonEvent = Event<MouseButtonEventArgs>;
	using MouseButtonEventCallback = MouseButtonEvent::EventCallback;
}