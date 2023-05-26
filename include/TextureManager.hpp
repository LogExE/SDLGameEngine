
#pragma once

class TextureManager
{
private:
    TextureManager *instance;
    TextureManager()
    {}
public:
    static TextureManager& get_instance()
    {
        static TextureManager inst;
        return inst;
    }
    TextureManager(const TextureManager &) = delete;
    void operator=(const TextureManager &) = delete;
};