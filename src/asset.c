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

static int assets_GetAsset(AssetTree * at, char *path, struct Asset *asset) {
    return 0;
}

SDL_Texture *assets_GetTexture(AssetTree * at, char *path) {

    struct Asset a = {.type = ASSET_TEXTURE,.path = path };
    int code = assets_GetAsset(at, path, &a);
    if (code == 0) {
        return a.texture;
    }
    return NULL;

}
