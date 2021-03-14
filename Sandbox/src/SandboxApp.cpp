#include <Bloom.hpp>

/*
	Create a Sandbox class that inherit
	everything from the Bloom::Application
*/
class Sandbox : public Bloom::Application {
	public:
		Sandbox() {}

		~Sandbox() {}
};

Bloom::Application* Bloom::CreateApplication() {
	return new Sandbox();
}