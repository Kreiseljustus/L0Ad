#pragma once

#include "glm.hpp"
#include "imgui.h"

#include "Component.h"
#include "GameObject.h"

namespace Engine {
	class TransformComponent : public Component{
	public:
		TransformComponent() : position(glm::vec3(0.0f)), scale(glm::vec3(1.0f)), rotation(glm::vec3(0.0f)) {}

		virtual void onRender(glm::mat4& view) override;
		virtual void onUpdate() override;
		virtual void onRenderEditor(glm::mat4& view) override;
		virtual void onConstruction() override;
		virtual void onDestruction() override;
		virtual void onAttach() override;

		glm::vec3 position;
		glm::vec3 scale;
		glm::vec3 rotation;
	};
}