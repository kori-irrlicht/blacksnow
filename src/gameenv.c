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
