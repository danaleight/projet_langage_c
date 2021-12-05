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
    SDL_Rect coord;

    coord.w = 32;
    coord.h = 32;

    coord.x = 0;
    coord.y = 0;

    char hall[128] = "data/hall.map";

    statut =initAll(&windowMain, &renderer, &texture);
    
    /*int tailleX, tailleY;
    SDL_GetWindowSize(windowMain, &tailleX, &tailleY);

    for (int i = 0 ; i < tailleY ; i+=32)
    {
        coord.y = i;
        for(int j = 0 ; j < tailleX ; j+=32)
        {
            coord.x = j;
            if(i == 0)
            {
                if(j == 0)
                    texture=IMG_LoadTexture(renderer, "ressources/murs/coin_hg.png");
                else if(j == tailleX-32)
                    texture=IMG_LoadTexture(renderer, "ressources/murs/coin_hd.png");
                else
                    texture=IMG_LoadTexture(renderer, "ressources/murs/mur_haut.png");
            }

            else if(i == tailleY-32)
            {
                if(j == 0)
                    texture=IMG_LoadTexture(renderer, "ressources/murs/coin_bg.png");
                else if(j == tailleX-32)
                    texture=IMG_LoadTexture(renderer, "ressources/murs/coin_bd.png");
                else
                    texture=IMG_LoadTexture(renderer, "ressources/murs/mur_bas.png");
            } 

            else
            {
                if(j == 0)
                    texture=IMG_LoadTexture(renderer, "ressources/murs/mur_gauche.png");
                else if(j == tailleX-32)
                    texture=IMG_LoadTexture(renderer, "ressources/murs/mur_droit.png");
                else
                    texture=IMG_LoadTexture(renderer, "ressources/sol/tuile.png");
            }
            if(texture == NULL)
            {
                fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                statut = EXIT_FAILURE;
            }
            SDL_RenderCopy(renderer, texture, NULL, &coord);
        }
        SDL_Delay(250);
    }

    coord.x = 128;
    coord.y = 256;

    texture=IMG_LoadTexture(renderer, "ressources/joueur/player.png");
    if(texture == NULL)
    {
        fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
        statut = EXIT_FAILURE;
    }
    SDL_RenderCopy(renderer, texture, NULL, &coord);
    SDL_RenderPresent(renderer);*/

    statut = drawMap(hall, &texture, &renderer, &windowMain);
    SDL_Delay(10000);
    
    Quit:
        SDL_AllClose(&windowMain, &renderer, &texture);

    return EXIT_SUCCESS;
}
