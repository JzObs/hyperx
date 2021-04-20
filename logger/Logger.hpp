#pragma once

#ifndef UTILITY_LOGGER_HPP
#define UTILITY_LOGGER_HPP

#include <string>

namespace utility
{

class Logger
{
public:
    Logger() {}
    ~Logger() {}
    void Print(const std::string& s);
};

Logger& GetLogger();

}

#endif