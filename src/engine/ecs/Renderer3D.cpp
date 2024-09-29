#include "Renderer3D.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx/string_cast.hpp>

namespace Engine {
	void Renderer3D::onRenderEditor(glm::mat4& view) {
		ImGui::BeginChild("Renderer3D", ImVec2(0, 0), ImGuiChildFlags_AlwaysAutoResize | ImGuiChildFlags_AutoResizeY);

		ImGui::TextDisabled("Renderer3D");

		ImGui::EndChild();
		ImGui::Separator();
	}

	void Renderer3D::onConstruction() {

	}

	void Renderer3D::onDestruction()
	{
	}

	void Renderer3D::onAttach() {
		transform = gameObject->getComponent<TransformComponent>();
		printc("Component got attached",1 ,32);

		vb = new VertexBuffer(vert, sizeof(vert) * sizeof(float));
		ib = new IndexBuffer(triangles, sizeof(triangles));

		va = new VertexArray();
		layout = new VertexBufferLayout;
		
		layout->AddFloat(3);
		layout->AddFloat(3);
		va->AddBuffer(*vb, *layout);
	}

	Renderer3D::Renderer3D() {
		onConstruction();
	}

	void Renderer3D::onRender(glm::mat4& view) {
		print(shader);
		shader->Bind();

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(transform->position.x, transform->position.y, transform->position.z));

		glm::vec3 rotationAngles = glm::vec3(transform->rotation.x, transform->rotation.y, transform->rotation.z);

		rotationAngles = glm::radians(rotationAngles);

		model = glm::rotate(model, rotationAngles.x, glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, rotationAngles.y, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, rotationAngles.z, glm::vec3(0.0f, 0.0f, 1.0f));

		model = glm::scale(model, transform->scale);

		//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

		print("Uniform ");
		shader->SetUniformMatrix4fv("model", model);
		print("After uniform");

		renderer->Draw(*va, *ib, *shader);
	}
	void Renderer3D::onUpdate()
	{
	}
}