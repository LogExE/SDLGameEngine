
#include <SDL2/SDL.h>

#include "WindowSDL.hpp"

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    WindowSDL wnd;
    wnd.get_graphics().clear();
    wnd.get_graphics().draw_line({{0, 0}, {500, 500}});
    wnd.get_graphics().present();
    SDL_Delay(1000);
    SDL_Quit();
    return 0;
}