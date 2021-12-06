#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/sdl_fonctions.h"

int main(int argc, char **argv)
{
    int statut = EXIT_SUCCESS;
    if(0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }

    SDL_Window *windowMain = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;    

    char **map;
    int mapSizeX;
    int mapSizeY;

    char hall[128] = "data/hall.map";

    statut =initAll(&windowMain, &renderer, &texture);
    statut = drawMap(hall, map, &mapSizeX, &mapSizeY, &texture, &renderer, &windowMain);
    SDL_Delay(5000);
    
    Quit:
        SDL_AllClose(&windowMain, &renderer, &texture);

    return EXIT_SUCCESS;
}
