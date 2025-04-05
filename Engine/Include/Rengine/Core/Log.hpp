#pragma once

#include <Rengine/Core/Definitions.hpp>
#include <Rengine/Core/LogType.hpp>
#include <chrono>
#include <format>
#include <string_view>
#include <type_traits>
#include <vector>

#define REN_LOG_INFO(message)    Ren::LogSystem::GetInstance().Log(message, LogType::INFO)
#define REN_LOG_WARNING(message) Ren::LogSystem::GetInstance().Log(message, LogType::WARNING)
#define REN_LOG_ERROR(message)   Ren::LogSystem::GetInstance().Log(message, LogType::ERROR)

#define REN_ASSERT(expression, message)                                            \
    if (!expression) Ren::LogSystem::GetInstance().Log(#message, LogType::ASSERT); \
    assert(expression, #message);

// #define REN_STATIC_ASSERT() Maybe asserts be somewhere else? Problem for future Himan to figure out.

namespace Ren
{

struct LogEntry
{
    LogType logType{LogType::INFO};
    std::string_view message{};
    std::chrono::time_point<std::chrono::system_clock> timestamp;
};

class ILogChannel
{
public:
    virtual void OnLogged(const LogEntry& log) = 0;
};

template <typename T>
concept IsChannel = std::is_base_of_v<ILogChannel, T>;

class LogSystem
{
public:
    static LogSystem& GetInstance();

    template <IsChannel T> void AddChannel() { _logChannels.push_back(new T()); }

    void Log(std::string_view msg, LogType logType);

private:
    LogSystem() = default;

    UInt32 _bufferSize{};
    std::vector<LogEntry> _logs{};
    std::vector<ILogChannel*> _logChannels{};
};
} // namespace Ren
