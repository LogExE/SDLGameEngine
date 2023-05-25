
#pragma once

#include <string>

class Log
{
private:
    Log();
    Log(Log &other) = delete;
    void operator=(Log &other) = delete;
public:
    static Log instance();
    void write(const std::string &msg);
};