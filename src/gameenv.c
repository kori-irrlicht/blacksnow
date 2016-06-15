/*
 * gameenv.c
 *
 *  Created on: 13.06.2016
 *      Author: kori
 */

#include "gameenv.h"

void gameenv_Destroy(struct GameEnv *ge) {
    game_Destroy(ge->game);
    ge->game = NULL;

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

    ge->game = game_New();

    return true;

    // Cleanup if error in initialization
  err_render:
    SDL_DestroyRenderer(ge->renderer);
    ge->renderer = NULL;

  err_window:
    SDL_DestroyWindow(ge->window);
    ge->window = NULL;

    return false;
}

void gameenv_Run(struct GameEnv *ge) {

    const int MS_PER_FRAME = ge->msPerFrame;

    Uint32 prev = SDL_GetTicks();
    double lag = 0.0;
    bool running = true;

    SDL_Event e;
    while (running) {
        Uint32 now = SDL_GetTicks();
        Uint32 elapsed = now - prev;
        prev = now;
        lag += elapsed;

        // Input
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT:
                running = false;
                break;
            default:
                game_Input(ge->game, e);
                break;
                // input
            }
        }

        while (lag >= MS_PER_FRAME) {
            //update
            game_Update(ge->game);
            lag -= MS_PER_FRAME;
        }

        //render
    }
}
