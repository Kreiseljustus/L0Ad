#pragma once


#include "../Logging.h"
#include <glm.hpp>

namespace Engine {
	class GameObject;
	class Component {
	protected:
		unsigned int m_ComponentID;
	public:
		Component();
		//~Component();

		virtual void onUpdate() = 0;
		virtual void onRender(glm::mat4& view) = 0;
		virtual void onRenderEditor(glm::mat4& view) = 0;

		virtual void onAttach() = 0;

		virtual void onConstruction() = 0;
		virtual void onDestruction() = 0;

		GameObject* gameObject;
	private:
		static unsigned int m_HighestID;
	};
}