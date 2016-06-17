#include "gameobject.h"

static void initRenderable(struct GameObject *go) {
    go->type |= GAMEOBJECT_TYPE_RENDERABLE | GAMEOBJECT_TYPE_BODY;
}

struct GameObject *gameObject_NewPlayer() {
    struct GameObject *go = malloc(sizeof(struct GameObject));
    go->type = GAMEOBJECT_TYPE_MOVER | GAMEOBJECT_TYPE_PLAYER;
    initRenderable(go);
    return go;
};

void gameObject_Destroy(struct GameObject *go) {
    free(go);
}
