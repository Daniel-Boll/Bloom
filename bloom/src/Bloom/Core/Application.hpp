#pragma once

#include "Core.hpp"

namespace Bloom {
	class BLOOM_API Application {
		public:
			Application();
			
			void run();

			virtual ~Application();
	};

	// Should be defined in CLIENT.
	Application* CreateApplication();
}

