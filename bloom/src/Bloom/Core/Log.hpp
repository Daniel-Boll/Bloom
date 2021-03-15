#pragma once

#include "Core.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Bloom {
	class BLOOM_API Log {
		public:
			static void init();

			inline static std::shared_ptr<spdlog::logger>& getCoreLogger() {
				return s_CoreLogger;
			}
			inline static std::shared_ptr<spdlog::logger>& getClientLogger() {
				return s_ClientLogger;
			}
		
		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// MACROS

// Core log
#define BM_CORE_TRACE(...)		::Bloom::Log::getCoreLogger()->trace(__VA_ARGS__)
#define BM_CORE_INFO(...)			::Bloom::Log::getCoreLogger()->info(__VA_ARGS__)
#define BM_CORE_WARN(...)			::Bloom::Log::getCoreLogger()->warn(__VA_ARGS__)
#define BM_CORE_ERROR(...)		::Bloom::Log::getCoreLogger()->error(__VA_ARGS__)
#define BM_CORE_CRITICAL(...)	::Bloom::Log::getCoreLogger()->critical(__VA_ARGS__)

// Client log
#define BM_TRACE(...)					::Bloom::Log::getClientLogger()->trace(__VA_ARGS__)
#define BM_INFO(...)					::Bloom::Log::getClientLogger()->info(__VA_ARGS__)
#define BM_WARN(...)					::Bloom::Log::getClientLogger()->warn(__VA_ARGS__)
#define BM_ERROR(...)					::Bloom::Log::getClientLogger()->error(__VA_ARGS__)
#define BM_CRITICAL(...)			::Bloom::Log::getClientLogger()->critical(__VA_ARGS__)