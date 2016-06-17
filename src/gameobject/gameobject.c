#include "gameobject.h"

struct GameObject *gameObject_NewPlayer() {
    struct GameObject *go = malloc(sizeof(struct GameObject));
    go->type =
        GAMEOBJECT_TYPE_BODY | GAMEOBJECT_TYPE_MOVER |
        GAMEOBJECT_TYPE_PLAYER;
    return go;
};

void gameObject_Destroy(struct GameObject *go) {
    free(go);
}
