#include "bmpch.hpp"
#include "Bloom/Core/Window.hpp"

#ifdef BM_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.hpp"
#endif

namespace Bloom {
	Scope<Window> Window::Create(const WindowProps& props) {
		#ifdef BM_PLATFORM_WINDOWS
			return CreateScope<WindowsWindow>(props);
		#else
			BM_WARN(false, "Unknown platform!");
			return nullptr;
		#endif
	}
}