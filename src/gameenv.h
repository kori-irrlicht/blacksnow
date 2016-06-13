/*
 * gameenv.h
 *
 *  Created on: 13.06.2016
 *      Author: kori
 */

#ifndef SRC_GAMEENV_H_
#define SRC_GAMEENV_H_

#include <SDL2/SDL.h>
#include <stdbool.h>

struct GameEnv {
    SDL_Window *window;
    SDL_Renderer *renderer;
};

void gameenv_Destroy(struct GameEnv *ge);

bool gameenv_Init(struct GameEnv *ge);

#endif                          /* SRC_GAMEENV_H_ */
