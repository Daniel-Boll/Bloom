#pragma once

#include "Bloom/Core/Core.hpp"
#include "Bloom/Events/Event.hpp"

namespace Bloom {
	
	struct WindowProps {
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(
			const std::string& title = "Bloom Engine",
			uint32_t width = 1600,
			uint32_t height = 900
		) : Title(title), Width(width), Height(height) {}
	};
	
	// Basically a interface that must be implemented
	// in each plataform.
	class Window {
	//class BLOOM_API Window {
		public:
			using eventCallbackFn = std::function<void(Event&)>;

			virtual void onUpdate() = 0;

			virtual uint32_t getWidth() const = 0;
			virtual uint32_t getHeight() const = 0;

			// Window attributes
			virtual void setEventCallback(const eventCallbackFn& callback) = 0;
			virtual void setVSync(bool enabled) = 0;
			virtual bool isVSync() const = 0;

			virtual void* getNativeWindow() const = 0;

			static Scope<Window> Create(const WindowProps& props = WindowProps());

			virtual ~Window() = default;
	};
}

