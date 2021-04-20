#include "Logger.hpp"
#include <iostream>

namespace utility
{

Logger& GetLogger()
{
    static Logger l;
    return l;
}

void Logger::Print(const std::string& s)
{
    std::cout << s << std::endl;
}

}