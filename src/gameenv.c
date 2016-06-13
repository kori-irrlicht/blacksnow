/*
 * gameenv.c
 *
 *  Created on: 13.06.2016
 *      Author: kori
 */

#include "gameenv.h"

void gameenv_Destroy(struct GameEnv *ge) {
    SDL_DestroyRenderer(ge->renderer);
    ge->renderer = NULL;

    SDL_DestroyWindow(ge->window);
    ge->window = NULL;
}

bool gameenv_Init(struct GameEnv *ge) {

    ge->window = SDL_CreateWindow(PACKAGE_STRING,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  800,
                                  640,
                                  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (ge->window == NULL) {
        printf("Couldn't create window! SDL_Error: %s\n", SDL_GetError());
        goto err_window;
    }

    ge->renderer = SDL_CreateRenderer(ge->window,
                                      -1, SDL_RENDERER_ACCELERATED);

    if (ge->renderer == NULL) {
        printf("Couldn't create renderer! SDL_Error: %s\n",
               SDL_GetError());
        goto err_render;
    }

    return true;

  err_render:
    SDL_DestroyRenderer(ge->renderer);
    ge->renderer = NULL;

  err_window:
    SDL_DestroyWindow(ge->window);
    ge->window = NULL;

    return false;
}
