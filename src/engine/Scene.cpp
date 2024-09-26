#include "Scene.h"

Engine::Scene::Scene() {

}

void Engine::Scene::addGameObject(GameObject* object) {
	gameObjects.push_back(object);
}

void Engine::Scene::renderScene() {
	for (auto& gameObject : gameObjects) {
		gameObject->onRender(viewMatrix);
	}
}
