#pragma once

#ifdef BM_PLATFORM_WINDOWS

extern Bloom::Application* \
			 Bloom::CreateApplication();

int main(int argc, char** argv) {
	auto app = Bloom::CreateApplication();
	app->run();
	delete app;
}

#endif