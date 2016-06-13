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

/**
 * MS_PER_FRAME is the max time, a frame should take for updating.
 *
 * TODO: Read from config file
 */
extern const int MS_PER_FRAME;

/**
 * GameEnv contains the environement of the game, like the main window.
 */
struct GameEnv {
    SDL_Window *window;
    SDL_Renderer *renderer;
};

/**
 * gameenv_Destroy destroys the GameEnv.
 * All resources of GameEnv are destroyed and 
 * all pointers are set to NULL.
 *
 * @param ge Pointer to the GameEnv, that should be destroyed
 */
void gameenv_Destroy(struct GameEnv *ge);

/**
 * gameenv_Init initializes GameEnv.
 * Creates a window and a renderer for the GameEnv.
 *
 * If the initialization failed, all fields are set to their 'false' value.
 *
 * @param ge Pointer to the GameEnv, that needs to be initialized
 *
 * @return If the initialization was successful or not
 */
bool gameenv_Init(struct GameEnv *ge);

/**
 * gameenv_Run contains the gameloop.
 */
void gameenv_Run(struct GameEnv *ge);

#endif                          /* SRC_GAMEENV_H_ */
