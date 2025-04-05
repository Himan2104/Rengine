#include <Rengine/Core/Log.hpp>
#include <chrono>
#include <format>
#include <iostream>

namespace Ren
{

LogSystem& LogSystem::GetInstance()
{
    static LogSystem logSystem;
    return logSystem;
}

void LogSystem::Log(std::string_view msg, LogType logType)

{
    LogEntry logEntry{.logType = logType, .message = msg, .timestamp = std::chrono::system_clock::now()};
    _logs.push_back(logEntry);
    auto strlog = std::format("[{:%Y-%m-%d %X}] [{}] {}", logEntry.timestamp, logType, msg);
    std::cout << strlog << "\n";

    // TODO: Implement Channels
}

} // namespace Ren
