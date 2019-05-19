#include "Engine.hpp"

#include <iostream>

namespace fire {
	FIREGL_API FireEngine::FireEngine()
	{
		this->keyEvent = KeyEvent();
		this->window = nullptr;
		this->scene = new Scene();
	}

	FIREGL_API void FireEngine::start()
	{
		if (this->startEngine() == FIRE_SUCCESS) {
			this->mainLoop();
		}
		this->terminate();
	}

	FIREGL_API void FireEngine::close()
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	FireStatus FireEngine::startEngine()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef _DEBUG
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif

		window = glfwCreateWindow(1600, 900, "OpenGL Window", NULL, NULL);
		if (window == NULL) {
			std::cout << "Failed to create GLFW window!" << std::endl;
			glfwTerminate();
			return FIRE_FAIL;
		}
		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD!" << std::endl;
			return FIRE_FAIL;
		}

		glfwSetWindowUserPointer(window, this);
		glfwSetKeyCallback(window, &onKeyPress);
		glfwSetCursorPosCallback(window, &onMouseMove);
		glfwSetMouseButtonCallback(window, &onMouseButton);

		GLint flags; glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
		if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
		{
			glEnable(GL_DEBUG_OUTPUT);
			//glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			glDebugMessageCallback(onDebugMessage, nullptr);
			glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
		}

		glViewport(0, 0, 1600, 900);

		return FIRE_SUCCESS;
	}

	void FireEngine::mainLoop()
	{
		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();

			render();

			glfwSwapBuffers(window);
		}
	}

	void FireEngine::render()
	{
		glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void FireEngine::onKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		FireEngine* engine = static_cast< FireEngine* >(glfwGetWindowUserPointer(window));
		KeyEventArgs keyEventArgs = KeyEventArgs{ key, scancode, action, mods };
		engine->keyEvent.invoke(keyEventArgs);
	}

	void FireEngine::onMouseMove(GLFWwindow* window, double xpos, double ypos)
	{
		FireEngine* engine = static_cast< FireEngine* >(glfwGetWindowUserPointer(window));
		MouseMoveEventArgs mouseMoveEventArgs = MouseMoveEventArgs{ xpos, ypos };
		engine->mouseMoveEvent.invoke(mouseMoveEventArgs);
	}

	void FireEngine::onMouseButton(GLFWwindow* window, int button, int action, int mods)
	{
		FireEngine* engine = static_cast<FireEngine*>(glfwGetWindowUserPointer(window));
		double xpos, ypos; glfwGetCursorPos(window, &xpos, &ypos);
		MouseButtonEventArgs mouseButtonEventArgs = MouseButtonEventArgs{ xpos, ypos, button, action, mods };
		engine->mouseButtonEvent.invoke(mouseButtonEventArgs);
	}

	void APIENTRY FireEngine::onDebugMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
	{
		MessageBoxA(NULL, message, "GL Debug Message", MB_OK | MB_ICONERROR);
	}

	void FireEngine::terminate()
	{
		glfwTerminate();
	}
}