#pragma once
#include<iostream>
#include<fstream>
#include"Rengine/utility/Misc.hpp"
#include"Rengine/Config.hpp"


//Why is this a class and not just a namespace with free functions?
//Because I need to make a complete logging system that will generate
//a log file and update it regularly throughout the programs execution.
//Stupid idea? Or have a better one? Let me know please.

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
    private:
        inline static std::string end = "\033[m";
        inline static std::string color = "\033[0m";
    };
}