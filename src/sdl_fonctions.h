#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef __SDL_FONCTIONS__H__
#define __SDL_FONCTIONS__H__

int SDL_AllClose(SDL_Window **wind, SDL_Renderer **renderer, SDL_Texture **texture);
int initAll(SDL_Window **wind, SDL_Renderer **renderer, SDL_Texture **texture);

#endif