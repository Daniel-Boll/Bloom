#include "bmpch.hpp"
#include "Application.hpp"

#include "Bloom/Core/Log.hpp"

#include "Bloom/Events/Event.hpp"
#include "Bloom/Events/ApplicationEvent.hpp"


namespace Bloom {
	
	Application::Application() {
		m_Window = Window::Create();
	}

	void Application::run() {
		while (m_Running) {
			m_Window->onUpdate();
		}
	}

	Application::~Application() {}
}
