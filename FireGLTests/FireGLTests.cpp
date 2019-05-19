#include <iostream>
#include <fire/Engine.hpp>

fire::FireEngine e;

void onKeyCallback(fire::KeyEventArgs args) {
	if (args.action == GLFW_PRESS) {
		if (args.key == GLFW_KEY_ESCAPE)
			e.close();
	}
}

void onMouseButtonCallback(fire::MouseButtonEventArgs args) {
	if (args.action == GLFW_PRESS && args.button == GLFW_MOUSE_BUTTON_LEFT) {
		std::cout << "clicked at " << args.xpos << ", " << args.ypos << std::endl;
	}
}

int main()
{
	e.keyEvent += onKeyCallback;
	e.mouseButtonEvent += onMouseButtonCallback;
	e.start();
}
