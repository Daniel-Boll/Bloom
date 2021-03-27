#include "bmpch.hpp"
#include "Application.hpp"

#include "Bloom/Core/Log.hpp"

#include "Bloom/Events/Event.hpp"
#include "Bloom/Events/ApplicationEvent.hpp"

namespace Bloom {
	
	Application::Application() {
		m_Window = Window::Create();
		//m_Window->setEventCallback(BM_BIND_EVENT_FN(Application::onEvent));
	}

	/*void Application::onEvent(Event& e) {
		BM_CORE_INFO("{0}", e);
		
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(BM_BIND_EVENT_FN(Application::onWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BM_BIND_EVENT_FN(Application::onWindowClose));
	}*/

	void Application::run() {
		while (m_Running) {
			m_Window->onUpdate();
		}
	}

	Application::~Application() {}
}
