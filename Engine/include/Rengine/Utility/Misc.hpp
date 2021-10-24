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

    static std::string getCurrentTime(const char* format = "[%Y-%m-%d|%X]")
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        struct tm timeinfo;
        localtime_s(&timeinfo, &in_time_t);
        std::stringstream ss;
        ss << std::put_time(&timeinfo, format);
        return ss.str();
    }

    template<typename T>
    inline void centerOrigin(T& object)
    {
        object.setOrigin(object.getGlobalBounds().width / 2.0f, object.getGlobalBounds().height / 2.0f);
    }

    static void encrypt(std::string& str)
    {
        srand(time(NULL));
        int seed = rand() % 4294967295;
        srand(seed);
        int random = rand() % 2147483647;
        for (int i = 0; i < str.length(); i++)
            str[i] = int(str[i]) + random;

        str = std::to_string(seed) + "." + str;
    }

    static void decrypt(std::string& str)
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
