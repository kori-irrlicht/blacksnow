/*
 * gameobject/basictypes.h
 *
 *  Created on: 16.06.2016
 *      Author: kori
 */

#ifndef SRC_GAMEOBJECT_BASICTYPES_H_
#define SRC_GAMEOBJECT_BASICTYPES_H_

struct Position {
    int x, y;
};

struct Velocity {
    int x, y;
};

struct Acceleration {
    int x, y;
};

struct Dimension {
    int width, height;
};

#endif                          /* SRC_GAMEOBJECT_BASICTYPES_H_ */
