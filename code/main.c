#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Windows* SDL_CreateWindows("GAME", 50,50,700,700,SDL_WINDOW_RESIZABLE);
    SDL_Quit();
    return EXIT_SUCCESS;
}