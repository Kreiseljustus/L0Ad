#include "TransformComponent.h"
#include <gtc/type_ptr.hpp>

void Engine::TransformComponent::onRender(glm::mat4& view) {
	
}

void Engine::TransformComponent::onUpdate()
{
}

void Engine::TransformComponent::onRenderEditor(glm::mat4& view) {
	ImGui::Separator();
	ImGui::BeginChild("Transform", ImVec2(0,0), ImGuiChildFlags_AlwaysAutoResize | ImGuiChildFlags_AutoResizeY);
	ImGui::Text(gameObject->name.c_str());
	ImGui::InputFloat3("Position", glm::value_ptr(position));
	ImGui::InputFloat3("Rotation", glm::value_ptr(rotation));
	ImGui::InputFloat3("Scale", glm::value_ptr(scale));

	ImGui::EndChild();
	ImGui::Separator();
}

void Engine::TransformComponent::onConstruction()
{
}

void Engine::TransformComponent::onDestruction()
{
}

void Engine::TransformComponent::onAttach() {

}
