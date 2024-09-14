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

	protected:
		virtual void onUpdate() = 0;
		virtual void onRender() = 0;
		virtual void onEvent(GLFWwindow* window, int key, int scancode, int action, int mods) = 0;

		virtual void pastInit() = 0;

		GLFWwindow* m_Window;

		int m_Width, m_Height;
		const char* m_Title;
	};
}