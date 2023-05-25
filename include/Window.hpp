
#pragma once

#include <string>

class Window
{
private:
    std::string m_title;
public:
    Window();
    virtual ~Window() = 0;

    virtual void change_title(const std::string &title)
    {
        m_title = title;
    }
    std::string get_title() 
    {
        return m_title;
    }
};