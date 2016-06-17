/*
 * gameobject/gameobject.h
 *
 *  Created on: 15.06.2016
 *      Author: kori
 */

#ifndef SRC_GAMEOBJECT_GAMEOBJECT_H_
#define SRC_GAMEOBJECT_GAMEOBJECT_H_

#include <SDL2/SDL.h>
#include "basictypes.h"

enum GameObjectType {
    GAMEOBJECT_TYPE_NONE,
    GAMEOBJECT_TYPE_PLAYER = 1 << 0,
    GAMEOBJECT_TYPE_BODY = 1 << 2,
    GAMEOBJECT_TYPE_MOVER = 1 << 3,
    GAMEOBJECT_TYPE_RENDERABLE = 1 << 4,
};

struct GameObject {
    enum GameObjectType type;
    union {
        struct Player {
            struct Velocity vel;
            struct Acceleration acc;
            SDL_Rect rect;
            struct SDL_Texture *texture;
        } player;
        struct Body {
            SDL_Rect rect;
        } body;
        struct Mover {
            struct Velocity vel;
            struct Acceleration acc;
        } mover;
        struct Renderable {
            SDL_Rect rect;
            struct SDL_Texture *texture;
        } renderable;
    };
};

struct GameObject *gameObject_NewPlayer();
void gameObject_Destroy(struct GameObject *go);

#endif                          /* SRC_GAMEOBJECT_GAMEOBJECT_H_ */
