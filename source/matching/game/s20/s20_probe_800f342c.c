typedef struct S20Object { void **vtable; } S20Object;
typedef struct S20Cell { S20Object *object; } S20Cell;

void w3d_s20_release_slots_800f342c(char *self) {
    int zero = 0;
    S20Cell *cell;
    unsigned int i;
    if (*(int *)(self + 3168) != 1)
        *(int *)(self + 3168) = 0;
    cell = (S20Cell *)(self + 88);
    for (i = 0; i <= 199; i++, cell++) {
        if (cell->object != 0)
            ((void (*)(S20Object *))cell->object->vtable[4])(cell->object);
        cell->object = (S20Object *)zero;
    }
}

