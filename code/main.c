#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int tailleX;
    int tailleY;

    if(0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }

    SDL_Window *windowMain = NULL;
    windowMain = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640, 480, SDL_WINDOW_SHOWN);

    if(windowMain == NULL)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }

    SDL_Renderer *rendu = NULL;
    rendu = SDL_CreateRenderer(windowMain, -1, SDL_RENDERER_ACCELERATED);

    if(rendu == NULL)
    {
        fprintf(stderr, "Erreur SDL_Renderer : %s", SDL_GetError);
        goto Quit;
    }

    SDL_Rect coord;
    coord.w = 64;
    coord.h = 64;
    SDL_GetWindowSize(windowMain, &tailleX, &tailleY);

    SDL_Texture *texture = NULL;
    for (int i = 0 ; i < tailleX/64 ; i++)
        for(int j = 0 ; j < tailleY/64 ; i++)
        {
            if(i == 0)
            {
                if(j == 0)
                {
                    texture = IMG_LoadTexture(rendu, "../ressources/murs/mur_angle_gh.png");
                    coord.x = 0;
                    coord.y = 0;
                    SDL_RenderCopy(rendu, texture, NULL, &coord);
                }
            }
        }
    
Quit:
    if(texture != NULL)
        SDL_DestroyTexture(texture);
    if(rendu != NULL)
        SDL_DestroyRenderer(rendu);
    if(windowMain != NULL)
        SDL_DestroyWindow(windowMain);
    SDL_Quit();
    return EXIT_SUCCESS;
}