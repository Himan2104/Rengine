#include"Rengine/Utility/Debug.hpp"

void ren::Debug::log()
{
    std::cout << ren::util::getCurrentTime() << " INFO : " << "Empty Log function called! If enabled, it won't be logged in the logfile." << std::endl;
}
void ren::Debug::log(std::string message, MessageType m_type)
{
    std::string type;
    switch(m_type)
    {
        case MessageType::INFO: type = " INFO : ";
            break;
        case MessageType::WARNING: type = " WARNING : ";
            break;
        case MessageType::ERROR: type = " ERROR : ";
            break;
        default: type = " UNKNOWN : ";
            break;
    }
    std::cout << ren::util::getCurrentTime() << type << message << std::endl;
}

