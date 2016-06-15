/*
 * game.h
 *
 *  Created on: 14.06.2016
 *      Author: kori
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include <SDL2/SDL.h>

/**
 * Game contains the current stage.
 */
struct Game;

/**
 * game_SwitchStage requests a stage switch.
 * Stages will be switched in the next update call.
 */
void game_SwitchStage(struct Game *g, char *nextStage);

/**
 * game_Input handles the input.
 *
 * @param g The Game, which should handle the input
 * @param event A pointer to the Event, which should be handled
 */
void game_Input(struct Game *g, SDL_Event event);

/**
 * game_Update updates the game.
 * If a request for a stage switch has been made, 
 * the switch will be performed in this function.
 *
 * @param g The Game, which should be updated
 */
void game_Update(struct Game *g);

/**
 * game_New serves as the constructor of Game.
 * It it the preferred way to create a Game.
 * Be sure to call game_Destroy to destroy the struct.
 *
 * @return Pointer to a struct Game
 */
struct Game *game_New();

/**
 * game_Destroy destroys a Game and frees the memory.
 *
 * @param g The game, which should be destroyed
 */
void game_Destroy(struct Game *g);

#endif                          /* SRC_GAME_H_ */
