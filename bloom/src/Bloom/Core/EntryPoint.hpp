#pragma once

#ifdef BM_PLATFORM_WINDOWS

extern Bloom::Application* Bloom::CreateApplication();

int main(int argc, char** argv) {
	Bloom::Log::init();

	BM_CORE_WARN("Initialized log!");
	int a = 5;
	BM_INFO("Hello! Var={0}", a);

	auto app = Bloom::CreateApplication();
	app->run();
	delete app;
}

#endif