#include "EditorApplication.h"

#include "Logging.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include <gtc/type_ptr.hpp>

#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

namespace Editor {
	EditorApplication::EditorApplication() {

	}
	EditorApplication::~EditorApplication() {}

	void EditorApplication::onUpdate() {
		//DO STUFF
	}

	void EditorApplication::pastInit() {

		glClearColor(0, 0.5, 0.5, 1);
		shader = new Shader("assets/shaders/Basic.shader");
		shader->Bind();
		vb = new VertexBuffer(vertices, 24 * 6 * sizeof(float));
		ib = new IndexBuffer(triangles, 36);

		va = new VertexArray();
		layout = new VertexBufferLayout();
		renderer = new Renderer();

		layout->AddFloat(3);
		layout->AddFloat(3);
		va->AddBuffer(*vb, *layout);

		shader->SetUniform3f("lightPos", 1, 1, 1);
		shader->SetUniform3f("objectColor", 0.1, 0.25, 0.6);
		shader->SetUniform3f("lightColor", 0.3, 0.3, 0.3);

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();

		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch

		ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
		ImGui_ImplOpenGL3_Init();

		glEnable(GL_DEPTH_TEST);
	}

	int count = 0;
	float color[3];
	float lightPos[3];
	float lightColor[3];

	void EditorApplication::onRender() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//DO STUFF TO RENDER EDITOR UI
		ImGui_ImplGlfw_NewFrame();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("Test");

		ImGui::ColorEdit3("object color", color);
		ImGui::InputFloat3("light pos", lightPos);
		ImGui::ColorEdit3("light color", lightColor);

		ImGui::End();

		ImGui::ShowDemoWindow();

		ImGui::EndFrame();

		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		//RENDER REST OF SCENE (MAYBE IMPLEMENT IN ENGINE

		print("Rendererd");

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::rotate(model, glm::radians(50.0f)*float((count*0.01)), glm::vec3(0.5f, 1.0f, 0.0f));

		glm::mat4 view = glm::mat4(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

		glm::mat4 projection = glm::perspective(glm::radians(60.0f), float(m_Width) / (float)m_Height, 0.1f, 100.0f);

		int modelLoc = glGetUniformLocation(shader->Get(), "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		int viewLoc = glGetUniformLocation(shader->Get(), "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

		int projectionLoc = glGetUniformLocation(shader->Get(), "projection");
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

		shader->SetUniform4f("u_Color", 0.1, 0.25, 0.6, 1);

		shader->SetUniform3f("lightPos", lightPos[0], lightPos[1], lightPos[2]);
		shader->SetUniform3f("objectColor", color[0], color[1], color[2]);
		shader->SetUniform3f("lightColor", lightColor[0], lightColor[1], lightColor[2]);

		renderer->Draw(*va, *ib, *shader);

		count++;
	}

	void EditorApplication::onEvent(GLFWwindow* window, int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}

		if (key == GLFW_KEY_R && action == GLFW_PRESS) {
			Shader shader("assets/shaders/Basic.shader");
			shader.Bind();
		}

		if (key == GLFW_KEY_D && action == GLFW_PRESS) {
			glViewport(0, 0, m_Width, m_Height);
		}
	}
}