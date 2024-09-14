#include "Application.h"
#include "Logging.h"

void errorCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam)
{
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
		type, severity, message);
}


namespace Engine {
	Application::Application() : m_Window(nullptr), m_Width(800), m_Height(600), m_Title("New Window") {}

	Application::~Application() {
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	bool Application::init(int width, int height, const char* title) {
		m_Width = width;
		m_Height = height;
		m_Title = title;

		if (!glfwInit()) {
			printError("Failed to initialize GLFW");
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, title, nullptr, nullptr);
		if (!m_Window) {
			printError("Failed to create GLFW window");
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(m_Window);

		if (glewInit() != GLEW_OK) {
			printError("Failed to initialize GLEW");
			return false;
		}

		glfwSetWindowUserPointer(m_Window, this);
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));
			if (app) {
				app->onEvent(window, key, scancode, action, mods);
			}
			});

		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(errorCallback, 0);

		pastInit();

		return true;
	}

	void Application::run() {
		while (!glfwWindowShouldClose(m_Window)) {
			onUpdate();

			onRender();

			glfwSwapBuffers(m_Window);
			glfwPollEvents();
		}
	}
}