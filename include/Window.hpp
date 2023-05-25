
#pragma once

#include <string>

#include "Graphics.hpp"
#include <memory>

class Window
{
protected:
    std::string m_title;
    std::unique_ptr<Graphics> m_graphics;
public:
    const static std::string DEFAULT_TITLE;
    Window() {}
    virtual ~Window() = 0;

    virtual void change_title(const std::string &title)
    {
        m_title = title;
    }
    std::string get_title() 
    {
        return m_title;
    }
    Graphics& get_graphics()
    {
        return *m_graphics;
    }
};