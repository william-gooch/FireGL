#pragma once

#include <thread>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "status.hpp"
#include "Event.hpp"
#include "object/Scene.hpp"

#ifdef FIREGL_EXPORTS
#define FIREGL_API __declspec(dllexport)
#else
#define FIREGL_API __declspec(dllimport)
#endif

namespace fire {
	using namespace object;

	class FireEngine {
	public:

		FIREGL_API FireEngine();

		FIREGL_API void start();
		FIREGL_API void close();

		KeyEvent keyEvent;
		MouseMoveEvent mouseMoveEvent;
		MouseButtonEvent mouseButtonEvent;

	private:
		GLFWwindow* window;
		Scene* scene;

		FireStatus startEngine();

		void mainLoop();
		void render();

		static void onKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void onMouseMove(GLFWwindow* window, double xpos, double ypos);
		static void onMouseButton(GLFWwindow* window, int button, int action, int mods);
		static void APIENTRY onDebugMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

		void terminate();

	};
}