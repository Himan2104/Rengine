#pragma once
#include<iostream>
#include<chrono>
#include<sstream>
#include<time.h>
#include<string>
#include<iomanip>
#include<vector>
#include<functional>
#include<SFML/Graphics.hpp>

namespace ren
{
    /*
    \brief Get the current date+time as a string
    \param Time format as a string/const char*
    \see  Format String for std::put_time
    The default format is [YYYY-MM-DD|HH:MM:SS]
    */
    std::string getCurrentTime(const char* format = "[%Y-%m-%d|%X]")
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        struct tm timeinfo;
        localtime_s(&timeinfo, &in_time_t);
        std::stringstream ss;
        ss << std::put_time(&timeinfo, format);
        return ss.str();
    }

    /*
    \brief Center the origin of any object that derives from sf::Transformable*/
    //TODO: Get rid of the template. Very unsafe. Using this approach since
    //getGlobalBounds is defined differently in sf::Shape and sf::Sprite separately.
    //This will however be fixed inevidently when I create my own ECS for handling 
    //in-game objects.
    template<typename T>
    inline void centerOrigin(T& object)
    {
        object.setOrigin(object.getGlobalBounds().width / 2.0f, object.getGlobalBounds().height / 2.0f);
    }

    /*
    \brief Encrypt a given std::string
    \params std::string
    \returns void
    */
    void encrypt(std::string& str)
    {
        srand(time(NULL));
        int seed = rand() % 4294967295;
        srand(seed);
        int random = rand() % 2147483647;
        for (int i = 0; i < str.length(); i++)
            str[i] = int(str[i]) + random;

        str = std::to_string(seed) + "." + str;
    }

    /*
    \brief Decrypt a given std::string
    \params std::string
    \returns void
    */
    void decrypt(std::string& str)
    {
        int seed = 0;
        int random = 0;
        bool flag = false;
        std::string sub = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (!flag)
            {
                if (str[i] == '.')
                {
                    std::string temp = "";
                    for (int j = 0; j < i; j++) temp += str[j];
                    seed = std::stoi(temp);
                    srand(seed);
                    random = rand() % 2147483647;
                    flag = true;
                }
            }
            else sub += int(str[i]) - random;
        }
        str = sub;
    }

}
