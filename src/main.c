#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sdl_fonctions.h"

int main(int argc, char **argv)
{
    if(0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }

    SDL_Window *windowMain = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;    
    SDL_Rect coord;

    char hall[128] = "data/hall.map"

    coord.w = 32;
    coord.h = 32;

    initAll(&windowMain, &renderer, &texture);

    texture=IMG_LoadTexture(renderer, "ressources/murs/coin_bd.png");
    if(NULL == texture){
        fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
        goto Quit;
    }

    SDL_RenderCopy(renderer, texture, NULL, &coord);
    SDL_RenderPresent(renderer);

    SDL_Delay(10000);
    
    Quit:
        SDL_AllClose(&windowMain, &renderer, &texture);

    return EXIT_SUCCESS;
}
