#pragma once

#include <Rengine/Core/Types.hxx>
#include <Rengine/Core/LogType.hxx>
#include <chrono>
#include <format>
#include <memory>
#include <string>
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
    ILogChannel()                              = default;
    virtual ~ILogChannel()                     = default;
    virtual void OnLogged(const LogEntry& log) = 0;
};

template <typename T>
concept IsChannel = std::is_base_of_v<ILogChannel, T>;

class LogSystem
{
public:
    static LogSystem& GetInstance();

    template <IsChannel T, typename... Args>
    void AddChannel(Args&&... args)
    {
        // TODO: No check to see if a channel already exists :(
        // This is so bad but I will deal with it when I have time :3
        _logChannels.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

    void Log(std::string_view msg, LogType logType);

private:
    LogSystem() = default;

    UInt32 _bufferSize{};
    std::vector<LogEntry> _logs{};
    std::vector<std::unique_ptr<ILogChannel>> _logChannels{};
};
} // namespace Ren

template <>
struct std::formatter<Ren::LogEntry> : std::formatter<std::string>
{
    auto format(const Ren::LogEntry& logEntry, std::format_context& ctx) const
    {
        return std::formatter<std::string>::format(
            std::format("[{:%Y-%m-%d %X}] [{}] {}", logEntry.timestamp, logEntry.logType, logEntry.message), ctx);
    }
};
