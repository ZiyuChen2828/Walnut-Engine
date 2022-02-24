#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Walnut
{
	class WN_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_clientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};
}

// Q: ... usage
// Core log
#define WN_CORE_TRACE(...)      ::Walnut::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WN_CORE_INFO(...)       ::Walnut::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WN_CORE_WARN(...)       ::Walnut::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WN_CORE_ERROR(...)      ::Walnut::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WN_CORE_FATAL(...)      ::Walnut::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log
#define WN_CLIENT_TRACE(...)    ::Walnut::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WN_CLIENT_INFO(...)     ::Walnut::Log::GetClientLogger()->info(__VA_ARGS__)
#define WN_CLIENT_WARN(...)     ::Walnut::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WN_CLIENT_ERROR(...)    ::Walnut::Log::GetClientLogger()->error(__VA_ARGS__)
#define WN_CLIENT_FATAL(...)    ::Walnut::Log::GetClientLogger()->fatal(__VA_ARGS__)

