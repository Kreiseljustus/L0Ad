#pragma once

#include "Component.h"
#include <vector>
#include <glm.hpp>
#include <string>

namespace Engine {
	class GameObject {
	public:
		GameObject();
		//~GameObject();

		void onUpdate();
		void onRender(glm::mat4& view);
		void onRenderEditor(glm::mat4& view);

		void onConstruction();

		void addComponent(Component*);

		std::vector<Component*> GetComponents() { return components; }

		template <typename T>
		T* getComponent() {
			for (auto* component : components) {
				if (T* casted = dynamic_cast<T*>(component)) {
					return casted;
				}
			}
			return nullptr;
		}

		std::string name;
	protected:
		unsigned int m_ObjectID;
		std::vector<Component*> components;
	};
}