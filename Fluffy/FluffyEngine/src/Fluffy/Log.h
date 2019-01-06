#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory.h>

namespace Fluffy{

class F_API Log 
{
public:

	static void Init();

	inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
	{
		return s_CoreLogger; 
	}

	inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
	{
		return s_ClientLogger;
	}


private:
	static std::shared_ptr < spdlog::logger> s_CoreLogger;
	static std::shared_ptr < spdlog::logger> s_ClientLogger;

};

}

// Core Log Macros
#define F_CORE_TRACE(...)  ::Fluffy::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define F_CORE_INFO(...)   ::Fluffy::Log::GetCoreLogger()->info(__VA_ARGS__);
#define F_CORE_WARN(...)   ::Fluffy::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define F_CORE_ERROR(...)  ::Fluffy::Log::GetCoreLogger()->error(__VA_ARGS__);
#define F_CORE_FATAL(...)  ::Fluffy::Log::GetCoreLogger()->fatal(__VA_ARGS__);

// Client Log Macros
#define F_APP_TRACE(...)  ::Fluffy::Log::GetClientLogger()->trace(__VA_ARGS__);
#define F_APP_INFO(...)   ::Fluffy::Log::GetClientLogger()->info(__VA_ARGS__);
#define F_APP_WARN(...)   ::Fluffy::Log::GetClientLogger()->warn(__VA_ARGS__);
#define F_APP_ERROR(...)  ::Fluffy::Log::GetClientLogger()->error(__VA_ARGS__);
#define F_APP_FATAL(...)  ::Fluffy::Log::GetClientLogger()->fatal(__VA_ARGS__);