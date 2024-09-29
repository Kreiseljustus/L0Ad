#pragma once

#include "glew.h"
#include <GLFW/glfw3.h>

namespace Engine {
	class Application {
	public:
		Application();
		virtual ~Application();

		bool init(int width, int height, const char* title);

		void run();

		float FPS = 120.0f;
		float* targetFPS = &FPS;
	protected:
		virtual void onUpdate(double deltatime) = 0;
		virtual void onRender(double deltatime) = 0;
		virtual void onKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) = 0;
		virtual void onMouseEvent(GLFWwindow* window, double xPos, double yPos) = 0;
		virtual void onMouseButtonEvent(GLFWwindow* window, int button, int action, int mods) = 0;

		virtual void pastInit(float* targetFPS) = 0;

		GLFWwindow* m_Window;

		int m_Width, m_Height;
		const char* m_Title;
	};
}