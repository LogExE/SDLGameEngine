#include "SDL.h"

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Log("Faf");
    SDL_Log("%d", argc);
    for (int i = 0; i < argc; ++i)
        SDL_Log("%s ", argv[i]);
    SDL_Quit();
    return 0;
}