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

    printf("init accepted\n");
    SDL_Window *windowMain = NULL;
    windowMain = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640, 500, SDL_WINDOW_SHOWN);

    if(windowMain == NULL)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }

    printf("window accepted\n");
    SDL_Renderer *rendu = NULL;
    rendu = SDL_CreateRenderer(windowMain, -1, SDL_RENDERER_ACCELERATED);

    if(rendu == NULL)
    {
        fprintf(stderr, "Erreur SDL_Renderer : %s", SDL_GetError);
        goto Quit;
    }
    printf("renderer accepted\n");

    SDL_Rect coord;
    int posInitX;
    int posInitY;
    coord.w = 64;
    coord.h = 64;
    SDL_GetWindowSize(windowMain, &tailleX, &tailleY);
    SDL_GetWindowPosition(windowMain, &posInitX, &posInitY);

    printf("position accepted\n");
    SDL_Texture *texture = NULL;
    for (int i = 0 ; i < tailleX ; i+=64)
    {
        for(int j = 0 ; j < tailleY ; j+=64)
        {
            printf("coord i : %d, j : %d\n", i, j);
            if(i == 0)
            {
                if(j == 0)
                {
                    texture = IMG_LoadTexture(rendu, "/home/danaleight/Data/Documents/programmation/projets/git/projet_langage_c/ressources/murs/mur_angle_hg.png");
                    coord.x = posInitX;
                    coord.y = posInitY;
                    SDL_RenderCopy(rendu, texture, NULL, &coord);
                }

                else if(j == tailleX-64)
                {
                    texture = IMG_LoadTexture(rendu, "../ressources/murs/mur_angle_gd.png");
                    coord.x = (posInitX + tailleX)-64;
                    coord.y = posInitY;
                    SDL_RenderCopy(rendu, texture, NULL, &coord);
                }
                else
                {
                    texture = IMG_LoadTexture(rendu, "../ressources/murs/mur_angle_gd.png");
                    coord.x = posInitX+j;
                    coord.y = posInitY;
                    SDL_RenderCopy(rendu, texture, NULL, &coord);
                }
            }else
            {
                printf("truc");
            }
        }
            
    
    }
    SDL_Delay(5000);
    printf("going to quit\n");
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