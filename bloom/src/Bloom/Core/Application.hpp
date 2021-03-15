#pragma once

#include "Bloom/Core/Core.hpp"
#include "Bloom/Core/Window.hpp"

namespace Bloom {
	class BLOOM_API Application {
		public:
			Application();
			
			void run();

			virtual ~Application();

		private:
			Scope<Window> m_Window;

			bool m_Running = true;
			bool m_Minimized = false;
			float m_LastFrameTime = .0f;
	};

	// Should be defined in CLIENT.
	Application* CreateApplication();
}

