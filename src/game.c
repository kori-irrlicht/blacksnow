#include <SDL2/SDL.h>
#include <stdbool.h>

#include "game.h"

struct Game {
    char *currentStage;
    char *nextStage;

    // If a key is pressed or not
    // 282 -> In SDL, there are up to 282 different keys defined
    // https://wiki.libsdl.org/SDLScancodeLookup
    bool keyStatus[282];
};

struct Game *game_New(){
    struct Game *g = calloc(1, sizeof(struct Game));
    return g;
}

void game_Destroy(struct Game *g){
    free(g);
}

void game_Input(struct Game *g, SDL_Event * event) {
    switch (event->type) {
    case SDL_KEYUP:
        g->keyStatus[event->key.keysym.scancode] = false;
        break;

    case SDL_KEYDOWN:
        g->keyStatus[event->key.keysym.scancode] = true;
        break;

    default:
        break;
    }
}
