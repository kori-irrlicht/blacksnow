/*
 * gameobject/gameobject.h
 *
 *  Created on: 15.06.2016
 *      Author: kori
 */

#ifndef SRC_GAMEOBJECT_GAMEOBJECT_H_
#define SRC_GAMEOBJECT_GAMEOBJECT_H_

struct Position{
    int x,y;
};

struct Velocity{
    int x,y;
};

struct Acceleration{
    int x,y;
};

struct Unit {
    struct Position pos;
    struct Velocity vel;
    struct Acceleration acc;
};

struct Player {
    struct Unit;
};

struct GameObject{
    union {
        struct Unit unit;
        struct Player player;
    };
    char type;
};

#endif                          /* SRC_GAMEOBJECT_GAMEOBJECT_H_ */
