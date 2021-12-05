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
    SDL_Rect coord;
    coord.w = 32;
    coord.h = 32;

    char ligne[64];
    FILE *f = fopen(adresse, "r");
    int j = 0;
    while(fgets(ligne, 63, f) != NULL)
    {
        coord.y = j*32;
        for (int i = 0 ; i < strlen(ligne)-1 ; i++)
        {
            coord.x = i*32;
            if(ligne[i] == 'a')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/coin_hg.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }

            else if(ligne[i] == 'b')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/mur_haut.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'c')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/coin_hd.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'd')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/mur_gauche.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'e')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/mur_droit.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'f')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/coin_bg.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'g')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/mur_bas.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'h')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/coin_bd.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'i')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/mid_haut.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'j')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/mid_droit.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'k')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/mid_bas.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'l')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/mid_gauche.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'm')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/mur_angle_gh.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'n')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/mur_angle_dh.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'o')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/mur_angle_gb.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'p')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/mur_angle_db.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'q')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/mur_hb.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'r')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/murs/mur_gd.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            
            else if(ligne[i] == 'A')
            {
                *texture=IMG_LoadTexture(*renderer, "ressources/sol/tuile.png");
                if(*texture == NULL)
                {
                    fprintf(stderr, "Erreur IMG_LoadTexture : %s", SDL_GetError());
                    statut = EXIT_FAILURE;
                }
            }
            printf("Coord x : %d coord y : %d\n", coord.x, coord.y);
            SDL_RenderCopy(*renderer, *texture, NULL, &coord);
        }
        j++;
    }
    SDL_RenderPresent(*renderer);

    fclose(f);
    return statut;
}