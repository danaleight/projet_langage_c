#include "../include/sdl_fonctions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int SDL_AllClose(SDL_Window **wind, SDL_Renderer **renderer, SDL_Texture **texture)
{
    if(NULL != texture)
        SDL_DestroyTexture(*texture);
    if(NULL != renderer)
        SDL_DestroyRenderer(*renderer);
    if(wind != NULL)
        SDL_DestroyWindow(*wind);
    SDL_Quit();
}

int initAll(SDL_Window **wind, SDL_Renderer **renderer, SDL_Texture **texture)
{
    int statut = EXIT_FAILURE;
    *wind = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640, 512, SDL_WINDOW_SHOWN);
    if(*wind == NULL)
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
    
    else
    {
        *renderer = SDL_CreateRenderer(*wind, -1, SDL_RENDERER_ACCELERATED);
        if(*renderer == NULL)
            fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());

        else
        {
            *texture = SDL_CreateTexture(*renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, 20, 20);
            if(*texture == NULL)
                fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());

            else
                statut = EXIT_SUCCESS;
        }
    }
    
    return statut;    
}

int drawMap(char *adresse, SDL_Texture **texture, SDL_Renderer **renderer, SDL_Window **wind)
{
    /*fonctions qui permettra dans la partie 2 une modularite plus importante*/
    int statut = EXIT_SUCCESS;
    char ligne[64];
    FILE *f = fopen(adresse, "r");
    int j = 0;
    while(fgets(ligne, 63, f) != NULL)
    {
        for (int i = 0 ; i < strlen(ligne) ; i++)
        {
            if(ligne[i] == 0)
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/coin_hg.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
        }
        j++;
    }

    fclose(f);
}