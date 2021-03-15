#include "Application.hpp"

#include "Bloom/Core/Log.hpp"

#include "Bloom/Events/Event.hpp"
#include "Bloom/Events/ApplicationEvent.hpp"


namespace Bloom {
	Application::Application() {

	}

	void Application::run() {
		WindowResizeEvent e(1280, 720);
		BM_TRACE(e);

		while (true);
	}

	Application::~Application() {

	}
}
