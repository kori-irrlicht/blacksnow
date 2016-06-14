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
