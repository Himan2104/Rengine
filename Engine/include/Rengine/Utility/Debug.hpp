#pragma once
#include<iostream>
#include<fstream>
#include"Rengine/utility/Utility.hpp"
#include"Rengine/Config.hpp"

namespace ren
{
    class REN_API Debug
    {
    public:
        enum class MessageType
        {
            INFO    = 0,
            WARNING = 1,
            ERROR   = 2
        };
        static void log();
        static void log(std::string message, MessageType m_type = MessageType::INFO);
    };
}