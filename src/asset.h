/*
 * gameobject/gameobject.h
 *
 *  Created on: 15.06.2016
 *      Author: kori
 */

#ifndef SRC_TEXTURE_H_
#define SRC_TEXTURE_H_

#include <SDL2/SDL.h>

enum AssetType {
    ASSET_TEXTURE,
};

struct Asset {
    enum AssetType type;
    union {
        SDL_Texture *texture;
    };
    char *path;
};

struct AssetTree {
    struct Asset content;
    struct AssetTree *leftChild;
    struct AssetTree *rightChild;
};

/**
 * Returns a texture. If the texture is not cached, the texture
 * will be loaded from the given path.
 *
 * @param at The AssetTree to operate on
 * @param path The path of the asset relative to the assets directory
 *
 * @returns NULL if there is an error, otherwise a pointer to the texture
 */
SDL_Texture *assets_GetTexture(struct AssetTree *at, char *path);

#endif                          /* SRC_TEXTURE_H_ */
