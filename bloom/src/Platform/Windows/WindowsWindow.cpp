#include "bmpch.hpp"

#include "Platform/Windows/WindowsWindow.hpp"

#include "Bloom/Events/ApplicationEvent.hpp"
#include "Bloom/Events/MouseEvent.hpp"
#include "Bloom/Events/KeyEvent.hpp"

namespace Bloom {
	static bool s_GLFWInitialized = false;

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		init(props);
	}

	void WindowsWindow::init(const WindowProps& props) {
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		BM_CORE_INFO("Creating window {0} ({1} x {2})",\
			props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized) {
			// TODO: glfwTerminate on systemshutdown
			int success = glfwInit();
			BM_CORE_ASSERT(success, "Could not initialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(																		\
			(int)props.Width, (int)props.Height, m_Data.Title.c_str(),		\
			nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVSync(true);
	}

	void WindowsWindow::shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::setVSync(bool enabled) {
		glfwSwapInterval((enabled) ? 1 : 0);
		m_Data.VSync = enabled;
	}

	bool WindowsWindow::isVSync() const {
		return m_Data.VSync;
	}

	WindowsWindow::~WindowsWindow() {
		shutdown();
	}
}