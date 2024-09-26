#include "GameObject.h"

Engine::GameObject::GameObject() {
	for (auto& component : components) {
		//component->onConstruction();
	}
}

void Engine::GameObject::onUpdate() {
	for (auto& component : components) {
		component->onUpdate();
	}
}

void Engine::GameObject::onRender(glm::mat4& view) {
	for (auto& component : components) {
		component->onRender(view);
	}
}

void Engine::GameObject::onRenderEditor(glm::mat4& view) {
	for (auto& component : components) {
		component->onRenderEditor(view);
	}
}

void Engine::GameObject::addComponent(Component* c) {
	c->gameObject = this;
	c->onAttach();
	components.push_back(c);
}
