#include"Rengine/Utility/Misc.hpp"
#include<chrono>
#include<sstream>
#include<iomanip>
#include<vector>
#include<functional>

namespace ren
{
    std::string GetCurrentTime(const char* format)
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        struct tm timeinfo;
        localtime_s(&timeinfo, &in_time_t);
        std::stringstream ss;
        ss << std::put_time(&timeinfo, format);
        return ss.str();
    }

    void Encrypt(std::string& str)
    {
        srand(time(NULL));
        int seed = rand() % 4294967295;
        srand(seed);
        int random = rand() % 2147483647;
        for (int i = 0; i < str.length(); i++)
            str[i] = int(str[i]) + random;

        str = std::to_string(seed) + "." + str;
    }

    void Decrypt(std::string& str)
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