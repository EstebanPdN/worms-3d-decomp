/* Pool entry acquisition through a held reference. */
typedef struct S20Object { void **vtable; } S20Object;
extern char *fn_801ef048(char *, int, int, int);

int w3d_s20_store_float_pair_801738c0(char *self, float *value) {
    S20Object *volatile held;
    S20Object *current = *(S20Object **)(*(char **)(self + 128) + 48);
    char *base;
    char *list;
    char *pool;
    char *entry;
    int count;
    held = current;
    if (current != 0)
        ((void (*)(S20Object *))current->vtable[3])(current);
    base = (char *)held;
    pool = *(char **)(base + 68);
    list = base + 68;
    count = *(int *)(pool + 24);
    if (*(unsigned short *)(pool + 4) == 1) {
        *(unsigned short *)(pool + 28) += 1;
        entry = pool + 32;
    } else {
        entry = fn_801ef048(list, count, 8, 2);
    }
    {
        int offset = *(int *)(self + 124) * 8;
        float first = value[0];
        float second = value[1];
        *(float *)(*(int *)(self + 124) * 8 + entry) = first;
        {
            float *slot = (float *)(offset + entry);
            slot[1] = second;
        }
    }
    {
        S20Object *tail = held;
        if (tail != 0)
            ((void (*)(S20Object *))tail->vtable[4])(tail);
    }
    return 0;
}

