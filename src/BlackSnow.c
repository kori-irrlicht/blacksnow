/*
 ============================================================================
 Name        : BlackSnow.c
 Author      : koridevel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "gameenv.h"
#include "gettext.h"

#define _(String) gettext (String)

bool bs_init();
void bs_close();

int main(void) {

    struct GameEnv ge;

    if (!bs_init(&ge)) {
        puts("bs_init failed! Closing...");
    }

    gameenv_Run(&ge);

    bs_close(&ge);
    return EXIT_SUCCESS;
}

bool bs_init(struct GameEnv * ge) {
    if (setlocale(LC_ALL, "") == NULL) {
        puts("setlocale failed");
        return false;
    }
    if (bindtextdomain(PACKAGE, LOCALEDIR) == NULL) {
        puts("bindtextdomain failed");
        return false;
    }
    if (textdomain(PACKAGE) == NULL) {
        puts("textdomain failed");
        return false;
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL initialization failed! SDL_Error: %s\n",
               SDL_GetError());
        return false;
    }

    if (!gameenv_Init(ge)) {
        puts("Couldn't create GameEnv");
        return false;
    }

    return true;
}

void bs_close(struct GameEnv *ge) {

    gameenv_Destroy(ge);
    ge = NULL;

    SDL_Quit();
}
