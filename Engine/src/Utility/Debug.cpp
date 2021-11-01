#include"Rengine/Utility/Debug.hpp"

void ren::Debug::log()
{
    std::cout << ren::getCurrentTime() << " INFO : " << "Empty Log function called! If enabled, it won't be logged in the logfile." << std::endl;
}
void ren::Debug::log(std::string message, MessageType m_type)
{
    std::string type;
    switch(m_type)
    {
        case MessageType::INFO: type = " INFO : "; color = "\033[0m";
            break;
        case MessageType::WARNING: type = " WARNING : "; color = "\033[33m";
            break;
        case MessageType::ERROR: type = " ERROR : "; color = "\033[31m";
            break;
        default: type = " UNKNOWN : ";
            break;
    }
    std::cout << color << ren::getCurrentTime() << type << message << end << std::endl;
}

