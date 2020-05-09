#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Irengin {
	
	class IRNGN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define IRNGN_CORE_FATAL(...)	::Irengin::Log::GetCoreLogger()->error(__VA_ARGS__);
#define IRNGN_CORE_ERROR(...)	::Irengin::Log::GetCoreLogger()->error(__VA_ARGS__);
#define IRNGN_CORE_WARN(...)	::Irengin::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define IRNGN_CORE_INFO(...)	::Irengin::Log::GetCoreLogger()->info(__VA_ARGS__);
#define IRNGN_CORE_TRACE(...)	::Irengin::Log::GetCoreLogger()->trace(__VA_ARGS__);

// Cliet log macros
#define IRNGN_FATAL(...)		::Irengin::Log::GetClientLogger()->error(__VA_ARGS__);
#define IRNGN_ERROR(...)		::Irengin::Log::GetClientLogger()->error(__VA_ARGS__);
#define IRNGN_WARN(...)			::Irengin::Log::GetClientLogger()->warn(__VA_ARGS__);
#define IRNGN_INFO(...)			::Irengin::Log::GetClientLogger()->info(__VA_ARGS__);
#define IRNGN_TRACE(...)		::Irengin::Log::GetClientLogger()->trace(__VA_ARGS__);