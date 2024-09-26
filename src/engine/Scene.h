#pragma once

#include <glm.hpp>
#include <vector>
#include "ecs/GameObject.h"

namespace Engine {
	class Scene {
	public:
		Scene();

		void addGameObject(GameObject* object);

		void renderSceneAtPosition(glm::vec3 position);
		void renderScene();
	private:
		std::vector<GameObject*> gameObjects;

		glm::mat4 viewMatrix;
	};
}