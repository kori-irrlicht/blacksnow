#include "asset.h"

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

