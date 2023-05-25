
#include <SDL2/SDL.h>

#include "SDLGraphics.hpp"

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *wnd = SDL_CreateWindow("test", 0, 0, 800, 600, SDL_WINDOW_SHOWN);
    SDLGraphics g(wnd);
    g.clear();
    g.draw_line({{0, 0}, {500, 500}});
    g.present();
    SDL_Delay(1000);
    SDL_Quit();
    return 0;
}