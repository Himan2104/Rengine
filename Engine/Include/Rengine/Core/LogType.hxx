#pragma once

#include <format>

namespace Ren
{
enum class LogType
{
    UNKNOWN = 0,
    INFO    = 1,
    WARNING = 2,
    ERROR   = 3,
    ASSERT  = 4
};
} // namespace Ren

template <>
struct std::formatter<Ren::LogType> : std::formatter<std::string_view>
{
    auto format(Ren::LogType logType, std::format_context& ctx) const
    {
        std::string_view name;
        switch (logType)
        {
        case Ren::LogType::UNKNOWN: name = "UNKNOWN"; break;
        case Ren::LogType::INFO: name = "INFO"; break;
        case Ren::LogType::WARNING: name = "WARNING"; break;
        case Ren::LogType::ERROR: name = "ERROR"; break;
        case Ren::LogType::ASSERT: name = "ASSERT"; break;
        }
        return std::formatter<std::string_view>::format(name, ctx);
    }
};
