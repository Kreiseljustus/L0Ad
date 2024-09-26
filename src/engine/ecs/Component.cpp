#include "Component.h"

unsigned int Engine::Component::m_HighestID = 0;

namespace Engine {
	Component::Component() {
		m_ComponentID = m_HighestID++;
		print("Created component " << m_ComponentID);
	}
}